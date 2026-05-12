#include <stdint.h>
#include "register_map.h"

int main(void) {
    RCC_CFGR &= ~((uint32_t)0xF << 4);
   RCC_APB2PCENR |= (1 << 4);

    GPIOC_CFGLR &= ~((uint32_t)0xF << 12);
    GPIOC_CFGLR |=  ((uint32_t)0x4 << 12);

    // PC7 push-pull output (LED)
    GPIOC_CFGLR &= ~((uint32_t)0xF << 28);
    GPIOC_CFGLR |=  ((uint32_t)0x3 << 28);
    while(1) {
        if(GPIOC_INDR & (1 << 3))  // read PC3 (button)
            GPIOC_BSHR = (1 << 7);  // set PC7 high (LED on)
            else
                GPIOC_BSHR = (1 << 23); // set PC7 low (LED off)
    }
}
