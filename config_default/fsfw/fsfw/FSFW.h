#ifndef FSFW_FSFW_H_
#define FSFW_FSFW_H_

#include "FSFWConfig.h"

/* #undef FSFW_OSAL_RTEMS */
#define FSFW_OSAL_FREERTOS
/* #undef FSFW_OSAL_LINUX */
/* #undef FSFW_OSAL_HOST */

/* #undef FSFW_ADD_RMAP */
/* #undef FSFW_ADD_DATALINKLAYER */
/* #undef FSFW_ADD_TMSTORAGE */
/* #undef FSFW_ADD_COORDINATES */
#define FSFW_ADD_PUS
#define FSFW_ADD_MONITORING
/* #undef FSFW_ADD_SGP4_PROPAGATOR */

// FSFW core defines

#ifndef FSFW_TCP_RECV_WIRETAPPING_ENABLED
#define FSFW_TCP_RECV_WIRETAPPING_ENABLED   0
#endif

#ifndef FSFW_CPP_OSTREAM_ENABLED
#define FSFW_CPP_OSTREAM_ENABLED            1
#endif /* FSFW_CPP_OSTREAM_ENABLED */

#ifndef FSFW_VERBOSE_LEVEL
#define FSFW_VERBOSE_LEVEL                  1
#endif /* FSFW_VERBOSE_LEVEL */

#ifndef FSFW_DISABLE_PRINTOUT
#define FSFW_DISABLE_PRINTOUT               0
#endif

#ifndef FSFW_USE_REALTIME_FOR_LINUX
#define FSFW_USE_REALTIME_FOR_LINUX         0
#endif /* FSFW_USE_REALTIME_FOR_LINUX */

#ifndef FSFW_NO_C99_IO
#define FSFW_NO_C99_IO                      0
#endif /* FSFW_NO_C99_IO */

#ifndef FSFW_USE_PUS_C_TELEMETRY
#define FSFW_USE_PUS_C_TELEMETRY            1
#endif /* FSFW_USE_PUS_C_TELEMETRY */

#ifndef FSFW_USE_PUS_C_TELECOMMANDS
#define FSFW_USE_PUS_C_TELECOMMANDS         1
#endif

#ifndef FSFW_TCP_RECV_WIRETAPPING_ENABLED
#define FSFW_TCP_RECV_WIRETAPPING_ENABLED   0
#endif

// FSFW HAL defines

// Can be used for low-level debugging of the SPI bus
#ifndef FSFW_HAL_SPI_WIRETAPPING
#define FSFW_HAL_SPI_WIRETAPPING            0
#endif

// Can be used for low-level debugging of the I2C bus
#ifndef FSFW_HAL_I2C_WIRETAPPING
#define FSFW_HAL_I2C_WIRETAPPING            0
#endif

#endif /* FSFW_FSFW_H_ */
