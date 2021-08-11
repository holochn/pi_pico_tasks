add_executable(freertos_multi_core_inverted
        main.cpp
)

target_link_libraries(freertos_multi_core_inverted pico_stdlib pico_multicore freertos)

# enable USB output and disable UART output
pico_enable_stdio_usb(freertos_multi_core_inverted 1)
pico_enable_stdio_uart(freertos_multi_core_inverted 0)

pico_add_extra_outputs(freertos_multi_core_inverted)
