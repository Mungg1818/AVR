#[[
	Filename: /home/pi/Documents/AVR/CMakeLists.txt
	Path: /home/pi/Documents/AVR
	Created Date: Tuesday, January 26th 2021, 5:28:07 pm
	Author: Pascal Weder

	Copyright (c) 2021 CodeHard AG
]]#

include(${CMAKE_CURRENT_SOURCE_DIR}/_Project/toolchain.cmake)

cmake_minimum_required(VERSION 3.13.4)

project(HelloWorld C CXX ASM) 

add_subdirectory( FW ) #FW files
