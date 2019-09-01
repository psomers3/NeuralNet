# This example toolchain file describes the cross compiler to use for
# the target architecture indicated in the configuration file.

# In this sample application, the "cross" toolchain is configured to
# simply use the system native compiler with the "m32" switch to output
# 32-bit code on a 64-bit system.  This will not be necessary in
# future revisions.

# Basic cross system configuration
SET(CMAKE_SYSTEM_NAME           Linux)
SET(CMAKE_SYSTEM_VERSION        1)
SET(CMAKE_SYSTEM_PROCESSOR      armhf)

# Specify the cross compiler executables
# Typically these would be installed in a home directory or somewhere
# in /opt.  However in this example the system compiler is used.

if(APPLE)
    message(STATUS "Is Apple")
    SET(CMAKE_C_COMPILER            "/Volumes/ct-beaglebone/x-tools/arm-cortex_a8-linux-gnueabihf/bin/arm-cortex_a8-linux-gnueabihf-gcc")
    SET(CMAKE_CXX_COMPILER          "/Volumes/ct-beaglebone/x-tools/arm-cortex_a8-linux-gnueabihf/bin/arm-cortex_a8-linux-gnueabihf-g++")
else()
    SET(CMAKE_C_COMPILER            "/usr/bin/arm-linux-gnueabihf-gcc")
    SET(CMAKE_CXX_COMPILER          "/usr/bin/arm-linux-gnueabihf-g++")
endif()

# Configure the find commands
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM   NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY   ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE   ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE   ONLY)

# This adds ensures that our binaries match the beaglebone black
set( CMAKE_C_FLAGS  "-march=armv7-a -mfpu=vfpv3-d16" CACHE  INTERNAL "" FORCE)
set( CMAKE_CXX_FLAGS  "-march=armv7-a -mfpu=vfpv3-d16" CACHE  INTERNAL "" FORCE)

set(THREADS_PTHREAD_ARG "2" CACHE STRING "Forcibly set by CMakeLists.txt." FORCE)
