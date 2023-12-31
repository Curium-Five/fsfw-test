# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitclone-lastrun.txt" AND EXISTS "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitinfo.txt" AND
  "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/ETLCPP/etl" "etl-src"
    WORKING_DIRECTORY "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/ETLCPP/etl'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "20.28.0" --
  WORKING_DIRECTORY "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '20.28.0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitinfo.txt" "/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/etl-populate-gitclone-lastrun.txt'")
endif()
