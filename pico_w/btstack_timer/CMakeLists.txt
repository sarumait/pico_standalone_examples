cmake_minimum_required(VERSION 3.13)

# pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(btstack_timer)

# initialize the SDK
pico_sdk_init()

add_executable(btstack_timer main.c)

target_link_libraries(btstack_timer 
    pico_stdlib 
    pico_cyw43_arch_none 
    pico_btstack_cyw43)

target_include_directories(btstack_timer PRIVATE
    # For btstack config
    ${CMAKE_CURRENT_LIST_DIR}
)


# enable usb output
pico_enable_stdio_usb(btstack_timer 1)

# create uf2 file
pico_add_extra_outputs(btstack_timer)