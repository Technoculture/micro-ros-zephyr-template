#
# Copyright (c) 2022, Technoculture Research
#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 3.13.1)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)

project(micro-ros-zephyr-template)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FILE(GLOB app_sources ../src/*.c*)
target_sources(app PRIVATE ${app_sources})
