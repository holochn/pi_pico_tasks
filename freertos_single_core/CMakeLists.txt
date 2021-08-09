add_executable(freertos_single_core
        main.cpp
)

target_link_libraries(freertos_single_core pico_stdlib pico_multicore freertos)

# enable USB output and disable UART output
pico_enable_stdio_usb(freertos_single_core 1)
pico_enable_stdio_uart(freertos_single_core 0)

pico_add_extra_outputs(freertos_single_core)
