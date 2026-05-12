#include<stdio.h>
#include<stdint.h>
#include"register_map.h"
void delay_ms(uint16_t ms){

    RCC_APB1PCENR |= (1 << 0);
    TIM2_CTRL  = 0;              // make sure timer is off
    TIM2_PSC   = 8000 - 1;     // 24MHz / 24000 = 1kHz tick
    TIM2_ATRLR = ms;             // count up to ms
    TIM2_CNT   = 0;
    TIM2_INTFR = 0;              // clear all flags (write 0, rc_w0 register)
    TIM2_CTRL  = (1 << 0);      // CEN, one-pulse mode off, just start it
    while (!(TIM2_INTFR & (1 << 0)));  // wait for UIF
    TIM2_CTRL  = 0;
}

void i2c_init(void){
    RCC_APB2PCENR |= (1 << 4);  // IOPCEN
    RCC_APB1PCENR |= (1 << 21); // I2C1EN

    // 2. Configure PC1 (SDA) and PC2 (SCL)
    // Set to Multiplexed Open-Drain, 50MHz (CNF=11, MODE=11)
    GPIOC_CFGLR &= ~(0xFF << 4);
    GPIOC_CFGLR |= (0xEE << 4);

    // 3. Setup I2C Timings
    I2C1_CTLR2 = 24;           // Assuming 24MHz HSI Clock
    I2C1_CKCFGR = 30;          // Fast Mode (~400kHz)

    // 4. Enable Peripheral
    I2C1_CTLR1 |= (1 << 0);    // PE bit
}

