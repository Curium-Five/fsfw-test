/**
 * @brief   This file will contain configuration constants which are used across all BSPs
 */
#ifndef COMMON_COMMONCONFIG_H_
#define COMMON_COMMONCONFIG_H_

#include <cstdint>

#define FSFW_ADD_FMT_TESTS 0

//! Specify the debug output verbose level
#define OBSW_VERBOSE_LEVEL              1
#define OBSW_TCPIP_UDP_WIRETAPPING      0
#define OBSW_PRINT_MISSED_DEADLINES     0

//! Perform internal unit testd at application startup
#define OBSW_PERFORM_INTERNAL_UNITTEST  1

//! Add core components for the FSFW and for TMTC communication
#define OBSW_ADD_CORE_COMPONENTS        1

//! Add the PUS service stack
#define OBSW_ADD_PUS_STACK              1
#define OBSW_PUS_PRINTOUT               0

//! Add the task examples
#define OBSW_ADD_TASK_EXAMPLE           1
#define OBSW_TASK_EXAMPLE_PRINTOUT      0

//! Add the demo device handler object
#define OBSW_ADD_DEVICE_HANDLER_DEMO    1
#define OBSW_DEVICE_HANDLER_PRINTOUT    1

//! Add the demo controller object
#define OBSW_ADD_CONTROLLER_DEMO        1
#define OBSW_CONTROLLER_PRINTOUT        1

/**
 *  The APID is a 14 bit identifier which can be used to distinguish processes and applications
 * on a spacecraft. For more details, see the related ECSS/CCSDS standards.
 * For this example, we are going to use a constant APID
*/
static const uint16_t COMMON_APID = 0xEF;

#ifdef __cplusplus

namespace cfg {

static constexpr uint32_t OBSW_MAX_SCHEDULED_TCS = 200;

}

#endif /* __cplusplus */

#endif /* COMMON_COMMONCONFIG_H_ */
