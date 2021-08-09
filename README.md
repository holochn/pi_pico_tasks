# Multitasking on the Raspberry Pi Pico
## Using the Raspberry Pi Pico SDK
Example sdk_multitasking shows how to run a task on each of the two core
## Using FreeRTOS
Example freertos_single_core runs two tasks on one core (core0). Both tasks use a queue to exchange data.
## Using FreeRTOS AND the Raspberry Pi Pico SDK
Example freertos_multi_core runs one task on core 1 and three tasks (including main) on core0.
The FreeRTOs tasks use a queue to exchange data. One of the FreeRTOs tsks uses SDK's FIFO to exchange data
with core1.