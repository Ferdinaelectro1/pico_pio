#include <pico/stdlib.h>
#include "hardware/pio.h"

#include "blink.pio.h"

#define LED 15

int main() {
    
    PIO pio = pio1;
    uint offset = pio_add_program(pio,&blink_program);
    uint sm = pio_claim_unused_sm(pio, true);
    blink_program_init(pio,sm,offset,LED);
    while (1)
    {
    }    
    return 0;
}