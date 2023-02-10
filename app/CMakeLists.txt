# Copyright (c) 2022 Mr. Green's Workshop https://www.MrGreensWorkshop.com
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# Set the board name
# Check out the docs: https://docs.zephyrproject.org/latest/develop/application/index.html#application-cmakelists-txt
set(BOARD rpi_pico)

# include Zephyr
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Set the project name
project(picodro)

# Add all the C source files to the build (non-recursive)
file(GLOB app_src src/*.c)
target_sources(app PRIVATE ${app_src})
