# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-src"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-build"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/tmp"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/src"
  "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/kryptokommunist/CLionProjects/fsfw-test/build/_deps/etl-subbuild/etl-populate-prefix/src/etl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
