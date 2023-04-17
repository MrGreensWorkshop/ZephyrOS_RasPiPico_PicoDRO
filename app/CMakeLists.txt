# Copyright (c) 2022 Mr. Green's Workshop https://www.MrGreensWorkshop.com
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# Set the board name
# Check out the docs: https://docs.zephyrproject.org/latest/develop/application/index.html#application-cmakelists-txt
set(BOARD rpi_pico)

# Set default console output (ON: USB CDC, OFF: UART)
# Check out the docs: https://docs.zephyrproject.org/latest/develop/west/build-flash-debug.html#permanent-cmake-arguments
set(USE_USB_CONSOLE ON CACHE BOOL "Enable USB CDC console")

# Setting CONF_FILE and DTC_OVERLAY_FILE
# Check out the docs: https://docs.zephyrproject.org/latest/build/kconfig/setting.html#the-initial-configuration
# Check out the docs: https://docs.zephyrproject.org/latest/build/dts/howtos.html#set-devicetree-overlays
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.conf")
  list(APPEND CONF_FILE "prj.conf")
endif()

if(USE_USB_CONSOLE)
  message("-- The console output set to USB")
  list(APPEND CONF_FILE "usb.conf")

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/app.overlay")
    list(APPEND DTC_OVERLAY_FILE "app.overlay")
  endif()
  list(APPEND DTC_OVERLAY_FILE "usb.overlay")
else()
  message("-- The console output set to UART")
endif()

# Set debug.conf to always on
#list(APPEND OVERLAY_CONFIG "debug.conf")

# include Zephyr
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Set the project name
project(picodro)

# Add all the C source files to the build (non-recursive)
file(GLOB app_src src/*.c)
target_sources(app PRIVATE ${app_src})
