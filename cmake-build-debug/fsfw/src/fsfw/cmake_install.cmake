# Install script for directory: /Users/kryptokommunist/CLionProjects/fsfw-test/fsfw/src/fsfw

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/action/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/cfdp/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/container/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/controller/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/datapool/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/datapoollocal/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/devicehandlers/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/events/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/fdir/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/globalfunctions/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/health/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/housekeeping/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/internalerror/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/ipc/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/memory/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/modes/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/objectmanager/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/parameters/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/power/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/serialize/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/serviceinterface/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/storagemanager/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/subsystem/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/tasks/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/tcdistribution/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/thermal/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/timemanager/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/tmtcpacket/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/tmtcservices/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/filesystem/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/monitoring/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/pus/cmake_install.cmake")
  include("/Users/kryptokommunist/CLionProjects/fsfw-test/cmake-build-debug/fsfw/src/fsfw/osal/cmake_install.cmake")

endif()

