#ifndef REGISTER_MAP_H
#define REGISTER_MAP_H
#include<stdio.h>
#include<stdint.h>
#define RCC_BASE  0x40021000
#define GPIOC_BASE 0x40011000
#define RCC_APB1PCENR (*(volatile uint32_t*)(RCC_BASE+0x1C))
#define RCC_APB2PRSTR (*(volatile uint32_t*)(RCC_BASE+0x0C))
#define RCC_APB2PCENR (*(volatile uint32_t*)0x40021018)
#define GPIOC_BSHR (*(volatile uint32_t*)(GPIOC_BASE+0x10))
#define GPIOC_CFGLR (*(volatile uint32_t*)(GPIOC_BASE))
#define GPIOC_INDR (*(volatile uint32_t*)(GPIOC_BASE+0x8))
#define RCC_CFGR (*(volatile uint32_t*)(RCC_BASE+0x4))
#define TIM2_CTRL  (*(volatile uint32_t*)(TIM2_BASE+0x00))
#define TIM2_BASE 0x40000000
#define TIM2_CTRL  (*(volatile uint32_t*)(TIM2_BASE+0x00))  // CTLR1
#define TIM2_CTRL  (*(volatile uint32_t*)(TIM2_BASE+0x00))
#define TIM2_INTFR (*(volatile uint32_t*)(TIM2_BASE+0x10))
#define TIM2_CNT   (*(volatile uint32_t*)(TIM2_BASE+0x24))
#define TIM2_PSC   (*(volatile uint32_t*)(TIM2_BASE+0x28))
#define TIM2_ATRLR (*(volatile uint32_t*)(TIM2_BASE+0x2C))
#define I2C_BASE_CTR 0x40005400
#define I2C1_CTLR1 (*(volatile uint32_t*)(I2C_BASE_CTR+0x0))
#define I2C1_CTLR2 (*(volatile uint32_t*)(I2C_BASE_CTR+0x04))
#define I2C1_CKCFGR (*(volatile uint32_t*)(I2C_BASE_CTR+0x1C))
#define I2C1_OADDR1 (*(volatile uint32_t*)(I2C_BASE_CTR+0x08))
#define I2C1_OADDR2 (*(volatile uint32_t*)(I2C_BASE_CTR+0x0C))
#define I2C1_DATAR (*(volatile uint32_t*)(I2C_BASE_CTR+0x10))
#define I2C1_STAR1 (*(volatile uint32_t*)(I2C_BASE_CTR+0x14))
#define I2C1_STAR2 (*(volatile uint32_t*)(I2C_BASE_CTR+0x18))
#define USART_BASE 0x40013800
#define USART_STATR (*(volatile uint32_t*)(USART_BASE))
#define USART_DATAR (*(volatile uint32_t*)(USART_BASE + 0x4))
#define USART_BRR (*(volatile uint32_t*)(USART_BASE + 0x8))
#define USART_CTRL1 (*(volatile uint32_t*)(USART_BASE + 0xc))
#define USART_CTLR2 (*(volatile uint32_t*)(USART_BASE + 0x10))
#define USART_CTRL3 (*(volatile uint32_t*)(USART_BASE + 0x14))
#define USART_GPR (*(volatile uint32_t*)(USART_BASE + 0x18))



void delay_ms(uint16_t ms);
void i2c_init(void);
#endif
