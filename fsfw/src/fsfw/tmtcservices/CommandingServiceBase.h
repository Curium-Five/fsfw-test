#ifndef FSFW_TMTCSERVICES_COMMANDINGSERVICEBASE_H_
#define FSFW_TMTCSERVICES_COMMANDINGSERVICEBASE_H_

#include "AcceptsTelecommandsIF.h"
#include "TmSendHelper.h"
#include "TmStoreHelper.h"
#include "VerificationReporter.h"
#include "fsfw/FSFW.h"
#include "fsfw/container/FIFO.h"
#include "fsfw/container/FixedMap.h"
#include "fsfw/ipc/CommandMessage.h"
#include "fsfw/ipc/MessageQueueIF.h"
#include "fsfw/objectmanager/SystemObject.h"
#include "fsfw/serialize/SerializeIF.h"
#include "fsfw/storagemanager/StorageManagerIF.h"
#include "fsfw/tasks/ExecutableObjectIF.h"
#include "fsfw/tmtcservices/TmStoreAndSendHelper.h"

namespace Factory {
void setStaticFrameworkObjectIds();
};

/**
 * @brief 	This class is the basis for all PUS Services, which have to
 * 			relay Telecommands to software bus.
 *
 * It manages Telecommand reception and the generation of Verification Reports
 * similar to @PusServiceBase. This class is used if a telecommand can't be
 * handled immediately and must be relayed to the internal software bus.
 *   - isValidSubservice
 *   - getMessageQueueAndObject
 *   - prepareCommand
 *   - handleReply
 *
 * Please note that the TM packets generated by this class will not have a valid CRC. It is
 * generally assumed that all packets will pass through a layer where the sequence count is set
 * and the CRC16 needs to be re-calculated anyway.
 * @author gaisser
 * @ingroup pus_services
 */
class CommandingServiceBase : public SystemObject,
                              public AcceptsTelecommandsIF,
                              public ExecutableObjectIF {
  friend void Factory::setStaticFrameworkObjectIds();

 public:
  // We could make this configurable via preprocessor and the FSFWConfig file.
  static constexpr uint8_t COMMAND_INFO_FIFO_DEPTH = fsfwconfig::FSFW_CSB_FIFO_DEPTH;

  static const uint8_t INTERFACE_ID = CLASS_ID::COMMAND_SERVICE_BASE;

  static const ReturnValue_t EXECUTION_COMPLETE = MAKE_RETURN_CODE(1);
  static const ReturnValue_t NO_STEP_MESSAGE = MAKE_RETURN_CODE(2);
  /**
   * Target object has too many pending requests
   */
  static const ReturnValue_t OBJECT_BUSY = MAKE_RETURN_CODE(3);
  /**
   * Command map is full
   */
  static const ReturnValue_t BUSY = MAKE_RETURN_CODE(4);
  static const ReturnValue_t INVALID_TC = MAKE_RETURN_CODE(5);
  static const ReturnValue_t INVALID_OBJECT = MAKE_RETURN_CODE(6);
  static const ReturnValue_t INVALID_REPLY = MAKE_RETURN_CODE(7);

  /**
   * Class constructor. Initializes two important MessageQueues:
   * commandQueue for command reception and requestQueue for device reception
   * @param setObjectId
   * @param apid
   * @param service
   * @param numberOfParallelCommands
   * @param commandTimeout_seconds
   * @param setPacketSource
   * @param setPacketDestination
   * @param queueDepth
   */
  CommandingServiceBase(object_id_t setObjectId, uint16_t apid, const char* name, uint8_t service,
                        uint8_t numberOfParallelCommands, uint16_t commandTimeoutSeconds,
                        size_t queueDepth = 20, VerificationReporterIF* reporter = nullptr);
  ~CommandingServiceBase() override;

  void setCustomTmStore(StorageManagerIF& store);
  /**
   * This setter can be used to set the packet source individually instead
   * of using the default static framework ID set in the factory.
   * This should be called at object initialization and not during run-time!
   * @param packetSource
   */
  void setPacketSource(object_id_t packetSource);
  /**
   * This setter can be used to set the packet destination individually
   * instead of using the default static framework ID set in the factory.
   * This should be called at object initialization and not during run-time!
   * @param packetDestination
   */
  void setPacketDestination(object_id_t packetDestination);

  /***
   * This is the periodically called function.
   * Handle request queue for external commands.
   * Handle command Queue for internal commands.
   * @param opCode is unused here at the moment
   * @return returnvalue::OK
   */
  ReturnValue_t performOperation(uint8_t opCode) override;

  uint32_t getIdentifier() const override;

  /**
   * Returns the requestQueue MessageQueueId_t
   *
   * The requestQueue is the queue for external commands (TC)
   *
   * @return requestQueue messageQueueId_t
   */
  MessageQueueId_t getRequestQueue() const override;

  /**
   * Returns the commandQueue MessageQueueId_t
   *
   * Remember the CommandQueue is the queue for internal communication
   * @return commandQueue messageQueueId_t
   */
  virtual MessageQueueId_t getCommandQueue();

  ReturnValue_t initialize() override;

  /**
   * Implementation of ExecutableObjectIF function
   *
   * Used to setup the reference of the task, that executes this component
   * @param task Pointer to the taskIF of this task
   */
  void setTaskIF(PeriodicTaskIF* task) override;
  const char* getName() const override;

 protected:
  /**
   * Check the target subservice
   * @param subservice[in]
   * @return
   * -@c returnvalue::OK Subservice valid, continue message handling
   * -@c INVALID_SUBSERVICE if service is not known, rejects packet.
   */
  virtual ReturnValue_t isValidSubservice(uint8_t subservice) = 0;

  /**
   * Once a TC Request is valid, the existence of the destination and its
   * target interface is checked and retrieved. The target message queue ID
   * can then be acquired by using the target interface.
   * @param subservice
   * @param tcData Application Data of TC Packet
   * @param tcDataLen
   * @param id MessageQueue ID is stored here
   * @param objectId Object ID is extracted and stored here
   * @return
   * - @c returnvalue::OK Continue message handling
   * - @c returnvalue::FAILED Reject the packet and generates a start failure
   *      verification
   */
  virtual ReturnValue_t getMessageQueueAndObject(uint8_t subservice, const uint8_t* tcData,
                                                 size_t tcDataLen, MessageQueueId_t* id,
                                                 object_id_t* objectId) = 0;

  /**
   * After the Message Queue and Object ID are determined, the command is
   * prepared by using an implementation specific CommandMessage type
   * which is sent to the target object. It contains all necessary information
   * for the device to execute telecommands.
   * @param message [out] message which can be set and is sent to the object
   * @param subservice Subservice of the current communication
   * @param tcData Application data of command
   * @param tcDataLen Application data length
   * @param state [out/in] Setable state of the communication.
   * communication
   * @param objectId Target object ID
   * @return
   * - @c returnvalue::OK to generate a verification start message
   * - @c EXECUTION_COMPLETE Fire-and-forget command. Generate a completion
   *      verification message.
   * - @c Anything else rejects the packets and generates a start failure
   *      verification.
   */
  virtual ReturnValue_t prepareCommand(CommandMessage* message, uint8_t subservice,
                                       const uint8_t* tcData, size_t tcDataLen, uint32_t* state,
                                       object_id_t objectId) = 0;

  /**
   * This function is implemented by child services to specify how replies
   * to a command from another software component are handled.
   * @param reply
   * This is the reply in form of a generic read-only command message.
   * @param previousCommand
   * Command_t of related command
   * @param state [out/in]
   * Additional parameter which can be used to pass state information.
   * State of the communication
   * @param optionalNextCommand [out]
   * An optional next command which can be set in this function
   * @param objectId Source object ID
   * @param isStep Flag value to mark steps of command execution
   * @return
   * - @c returnvalue::OK, @c EXECUTION_COMPLETE or @c NO_STEP_MESSAGE to
   *   generate TC verification success
   * - @c INVALID_REPLY Calls handleUnrequestedReply
   * - Anything else triggers a TC verification failure. If returnvalue::FAILED or
   * 	 INVALID_REPLY is returned and the command ID is
   * 	 CommandMessage::REPLY_REJECTED, a failure verification message with
   * 	 the reason as the error parameter and the initial command as
   * 	 failure parameter 1 is generated.
   */
  virtual ReturnValue_t handleReply(const CommandMessage* reply, Command_t previousCommand,
                                    uint32_t* state, CommandMessage* optionalNextCommand,
                                    object_id_t objectId, bool* isStep) = 0;

  /**
   * This function can be overidden to handle unrequested reply,
   * when the reply sender ID is unknown or is not found is the command map.
   * The default implementation will clear the command message and all
   * its contents.
   * @param reply
   * Reply which is non-const so the default implementation can clear the
   * message.
   */
  virtual void handleUnrequestedReply(CommandMessage* reply);

  virtual void doPeriodicOperation();

  struct CommandInfo : public SerializeIF {
    struct TcInfo {
      uint8_t ackFlags;
      uint16_t tcPacketId;
      uint16_t tcSequenceControl;
    } tcInfo;
    uint32_t uptimeOfStart;
    uint8_t step;
    uint8_t subservice;
    uint32_t state;
    Command_t command;
    object_id_t objectId;
    FIFO<store_address_t, COMMAND_INFO_FIFO_DEPTH> fifo;

    ReturnValue_t serialize(uint8_t** buffer, size_t* size, size_t maxSize,
                            Endianness streamEndianness) const override {
      return returnvalue::FAILED;
    };

    [[nodiscard]] size_t getSerializedSize() const override { return 0; };

    ReturnValue_t deSerialize(const uint8_t** buffer, size_t* size,
                              Endianness streamEndianness) override {
      return returnvalue::FAILED;
    };
  };

  using CommandMapIter = FixedMap<MessageQueueId_t, CommandingServiceBase::CommandInfo>::Iterator;

  const uint16_t apid;

  const uint8_t service;

  const uint16_t timeoutSeconds;

  PusTcReader tcReader;
  TmStoreHelper tmStoreHelper;
  TmSendHelper tmSendHelper;
  TmStoreAndSendWrapper tmHelper;

  StorageManagerIF* tcStore = nullptr;
  StorageManagerIF* ipcStore = nullptr;

  MessageQueueIF* commandQueue = nullptr;
  MessageQueueIF* requestQueue = nullptr;

  TimeWriterIF* tmTimeStamper = nullptr;
  VerificationReporterIF* verificationReporter;

  InternalErrorReporterIF* errReporter = nullptr;

  FixedMap<MessageQueueId_t, CommandInfo> commandMap;

  /* May be set be children to return a more precise failure condition. */
  uint32_t failureParameter1 = 0;
  uint32_t failureParameter2 = 0;

  const char* name = "";

  static object_id_t defaultPacketSource;
  object_id_t packetSource = objects::NO_OBJECT;
  static object_id_t defaultPacketDestination;
  object_id_t packetDestination = objects::NO_OBJECT;

  /**
   * Pointer to the task which executes this component,
   * is invalid before setTaskIF was called.
   */
  PeriodicTaskIF* executingTask = nullptr;

  ReturnValue_t sendTmPacket(uint8_t subservice, const uint8_t* sourceData, size_t sourceDataLen);
  ReturnValue_t sendTmPacket(uint8_t subservice, object_id_t objectId, const uint8_t* data,
                             size_t dataLen);
  ReturnValue_t sendTmPacket(uint8_t subservice, SerializeIF& sourceData);

  void checkAndExecuteFifo(CommandMapIter& iter);
  VerifFailureParams failParams;
  VerifSuccessParams successParams;

 private:
  /**
   * This method handles internal execution of a command,
   * once it has been started by @startExecution in the request
   * queue handler.
   * It handles replies generated by the devices and relayed by the specific
   * service implementation. This means that it determines further course of
   * action depending on the return values specified in the service
   * implementation.
   * This includes the generation of TC verification messages. Note that
   * the static framework object ID @c VerificationReporter::messageReceiver
   * needs to be set.
   *   - TM[1,5] Step Successs
   *   - TM[1,6] Step Failure
   *   - TM[1,7] Completion Success
   *   - TM[1,8] Completion Failure
   */
  void handleCommandQueue();

  /**
   * @brief       Handler function for request queue
   * @details
   * Sequence of request queue handling:
   * @isValidSubservice -> @getMessageQueueAndObject -> @startExecution
   * Generates a Start Success Reports TM[1,3] in subfunction
   * @startExecution or  a Start Failure Report TM[1,4] by using the
   * TC Verification Service.
   */
  void handleRequestQueue();

  ReturnValue_t setUpTcReader(store_address_t storeId);

  /**
   * The TC format is invalid or there was an issue retrieving a TC packet from the store.
   * @param errorCode Result of the failed operation, will be sent with the verification failure
   *    message
   * @return
   */
  ReturnValue_t rejectPacketInvalidTc(ReturnValue_t errorCode, store_address_t tcStoreId);
  ReturnValue_t rejectPacket(uint8_t reportId, store_address_t tcStoreId, ReturnValue_t errorCode);

  ReturnValue_t acceptPacket(uint8_t reportId, store_address_t tcStoreId);

  void startExecution(store_address_t storeId, CommandMapIter& iter);

  void handleCommandMessage(CommandMessage* reply);
  void handleReplyHandlerResult(ReturnValue_t result, CommandMapIter iter,
                                CommandMessage* nextCommand, CommandMessage* reply, bool& isStep);
  void prepareVerificationFailureWithNoTcInfo(uint8_t reportId, ReturnValue_t errorCode,
                                              bool setCachedFailParams);
  void prepareVerificationFailureWithFullInfo(uint8_t reportId, CommandInfo::TcInfo& tcInfo,
                                              ReturnValue_t errorCode, bool setCachedFailParams);
  void prepareVerificationSuccessWithFullInfo(uint8_t reportId, CommandInfo::TcInfo& tcInfo);
  void checkTimeout();
};

#endif /* FSFW_TMTCSERVICES_COMMANDINGSERVICEBASE_H_ */