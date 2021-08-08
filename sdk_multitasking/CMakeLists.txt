add_executable(sdk_multitasking
        main.cpp
)

target_link_libraries(sdk_multitasking pico_stdlib pico_multicore)

# enable USB output and disable UART output
pico_enable_stdio_usb(sdk_multitasking 1)
pico_enable_stdio_uart(sdk_multitasking 0)

pico_add_extra_outputs(sdk_multitasking)
