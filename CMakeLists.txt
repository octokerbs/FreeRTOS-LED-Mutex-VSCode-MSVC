cmake_minimum_required(VERSION 3.13)

project(blinkers C)

set(CMAKE_C_STANDARD 99)

# Source files
set(SOURCES

    # Project source files
    main.c
    led.c

    # Library source files
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/list.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/queue.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/tasks.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/timers.c"

    # Port source files
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/portable/MSVC-MingW/port.c"
)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/portable/MSVC-MingW"
)

# Add executable
add_executable(blinkers ${SOURCES})