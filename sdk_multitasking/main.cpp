#include "pico/multicore.h"
#include "pico/stdlib.h"
#include <iostream>

void core1Blink(void)
{
    int pin = 14;
    uint32_t fromCore0 = 0;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    
    while(true)
    {
        if( multicore_fifo_rvalid() == true )
        {
            fromCore0 = multicore_fifo_pop_blocking();
            std::cout << "R core1: " << fromCore0 << std::endl;
            fromCore0 += 10;
            sleep_ms(50);
        }
        
        gpio_put(pin, true);
        sleep_ms(200);
        gpio_put(pin, false);
        sleep_ms(200);

        multicore_fifo_push_blocking(fromCore0);
        std::cout << "S core1: " << fromCore0 << std::endl;
        sleep_ms(50);
    }
}

int main()
{
    uint32_t fromCore1 = 0;
    stdio_init_all();

    multicore_launch_core1(core1Blink);

    int pin = 15;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    
    multicore_fifo_push_blocking(fromCore1);

    while(true)
    {
        if( multicore_fifo_rvalid() == true )
        {
            fromCore1 = multicore_fifo_pop_blocking();
            std::cout << "R core0: " << fromCore1 << std::endl;
            sleep_ms(50);
        }

        gpio_put(pin, true);
        sleep_ms(100);
        gpio_put(pin, false);
        sleep_ms(100);
        
        fromCore1++;
        multicore_fifo_push_blocking(fromCore1);
        std::cout << "S core0: " << fromCore1 << std::endl;
        sleep_ms(50);
    }
}