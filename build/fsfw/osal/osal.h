#pragma once

namespace osal {
    enum osalTarget{
        HOST,
        LINUX,
        WINDOWS,
        FREERTOS,
        RTEMS,
    };

/* #undef FSFW_OSAL_HOST */
/* #undef FSFW_OSAL_LINUX */
/* #undef FSFW_OSAL_WINDOWS */
#define FSFW_OSAL_FREERTOS
/* #undef FSFW_OSAL_RTEMS */


    constexpr osalTarget getTarget() {
#ifdef FSFW_OSAL_HOST
  return HOST;
#endif
#ifdef FSFW_OSAL_LINUX
  return LINUX;
#endif
#ifdef FSFW_OSAL_WINDOWS
  return WINDOWS;
#endif
#ifdef FSFW_OSAL_FREERTOS
  return FREERTOS;
#endif
#ifdef FSFW_OSAL_RTEMS
  return RTEMS;
#endif
    }
};
