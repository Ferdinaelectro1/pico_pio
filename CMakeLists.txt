cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_pio)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PICOTOOL_FORCE_FETCH_FROM_GIT ON CACHE BOOL "" FORCE)

pico_sdk_init()

add_executable(${PROJECT_NAME} 
               main.c
               )

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/blink.pio)
pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib hardware_exception hardware_pio)
