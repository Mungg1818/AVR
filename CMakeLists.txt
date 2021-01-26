#
# Filename: /home/pi/Documents/AVR/CMakeLists.txt
# Path: /home/pi/Documents/AVR
# Created Date: Tuesday, January 26th 2021, 5:28:07 pm
# Author: Pascal Weder
#
# Copyright (c) 2021 CodeHard AG
#

set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/avr-g++")
set(CMAKE_ASM_COMPILER "/usr/bin/avr-gcc")

cmake_minimum_required(VERSION 3.13.4)

project(HelloWorld C CXX ASM) 

add_subdirectory( FW ) #FW files
