#[[
	Filename: /home/pi/Documents/AVR/FW/CMakeLists.txt
	Path: /home/pi/Documents/AVR/FW
	Created Date: Monday, January 25th 2021, 5:45:44 pm
	Author: Pascal Weder
	
	Copyright (c) 2021 CodeHard AG
]]#

set(target ${PROJECT_NAME}.elf)

add_executable(${target} main.c)

set_target_properties(
	${target}
	PROPERTIES
	COMPILE_FLAGS "-mmcu=at90usb1287"
	LINK_FLAGS "-mmcu=at90usb1287"
)

#generating HEX output
add_custom_command(
	TARGET ${target}
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O ihex ${target} ${PROJECT_NAME}.hex
)
