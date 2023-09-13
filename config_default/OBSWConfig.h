/**
 * @brief	This file can be used to add preprocessor define for conditional
 * 			code inclusion exclusion or various other project constants and
 * 			properties in one place.
 */
#ifndef FSFWCONFIG_OBSWCONFIG_H_
#define FSFWCONFIG_OBSWCONFIG_H_

#define STM_USE_PERIPHERAL_TX_BUFFER_MPU_PROTECTION     1

//! Specify whether lwIP components are added. These are necessary for TMTC commanding
#define OBSW_ADD_LWIP_COMPONENTS            1
//! Specify whether TMTC commanding via Ethernet is possible
#define OBSW_ETHERNET_TMTC_COMMANDING       1
//! Only applies if TMTC commanding is enabled.
//! Specify whether LEDs are used to display Ethernet connection status.
#define OBSW_ETHERNET_USE_LED1_LED2         0

#define OBSW_ATTEMPT_DHCP_CONN              1

#define OBSW_PERIPHERAL_PST                 0
#define OBSW_PERFORM_SPI_TEST               0

#define OBSW_PERFORM_L3GD20H_TEST           0

#if OBSW_ATTEMPT_DHCP_CONN == 0
#define MAX_DHCP_TRIES                      0
#else
#define MAX_DHCP_TRIES                      3
#endif


#ifdef __cplusplus

#include "events/subsystemIdRanges.h"
#include "objects/systemObjectList.h"
#include <commonConfig.h>

namespace config {
#endif

/* Add mission configuration flags here */

#ifdef __cplusplus
}
#endif

#endif /* FSFWCONFIG_OBSWCONFIG_H_ */
