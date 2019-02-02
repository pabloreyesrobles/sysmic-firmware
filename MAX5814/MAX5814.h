/**
 * @author  Pablo Reyes Robles
 * @email   pablo.reyesr@alumnos.usm.cl
 * @version v1.0
 * @license UTFSM
@verbatim
   ----------------------------------------------------------------------
    Copyright (C) Sysmic Robotics, 2019
   ----------------------------------------------------------------------
@endverbatim
 */

#ifndef _MAX5814_H_
#define _MAX5814_H_

/* Include proper header file */
/* STM32F7xx */
#if defined(STM32F0xx) || defined(STM32F0XX)
#ifndef STM32F0xx
#define STM32F0xx
#endif
#ifndef STM32F0XX
#define STM32F0XX
#endif
#include "stm32f0xx.h"
#include "stm32f0xx_hal.h"
#endif

/* STM32F4xx */
#if defined(STM32F4xx) || defined(STM32F4XX)
#ifndef STM32F4xx
#define STM32F4xx
#endif
#ifndef STM32F4XX
#define STM32F4XX
#endif
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#endif

/* STM32F7xx */
#if defined(STM32F7xx) || defined(STM32F7XX)
#ifndef STM32F7xx
#define STM32F7xx
#endif
#ifndef STM32F7XX
#define STM32F7XX
#endif
#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#endif

#define DAC_ADDRESS 	 			0x00
#define DAC_WRITE_OPERATION			0x00
#define DAC_READ_OPERATION			0x01

#define DAC_CMD_CODEn				0x00
#define DAC_CMD_LOADn				0x10
#define DAC_CMD_CODEn_LOAD_ALL		0x20
#define DAC_CMD_CODEn_LOADn			0x30
#define DAC_CMD_CODE_ALL 			0x80
#define DAC_CMD_LOAD_ALL 			0x81
#define DAC_CMD_CODE_ALL_LOAD_ALL	0x82

#define DAC_CMD_POWER				0x40
#define DAC_CMD_SW_CLEAR			0x50
#define DAC_CMD_SW_RESET			0x51
#define DAC_CMD_CONFIG				0x60
#define DAC_CMD_REF					0x70

#define DAC_REF_EXT					0x00
#define DAC_REF_25					0x01
#define DAC_REF_20					0x02
#define DAC_REF_41					0x03
#define DAC_REF_PWR_ON				0x04

#define DAC_OUTPUT_A				0x00
#define DAC_OUTPUT_B				0x01
#define DAC_OUTPUT_C				0x02
#define DAC_OUTPUT_D				0x03
#define DAC_OUTPUT_ALL				0x04 // or 0x08

#define DAC_ENABLE_LATCH			0x00
#define DAC_DISABLE_LATCH			0x01
#define DAC_SEL_ALL					0x40
#define DAC_SEL_A 					0x01
#define DAC_SEL_B					0x02
#define DAC_SEL_C 					0x04
#define DAC_SEL_D					0x08

void Dac_WriteCommand(uint8_t dacCommand);
void Dac_ReadCommand(uint8_t *dacData);
void Dac_Init(I2C_HandleTypeDef *hi2c, uint8_t dacRefSelector);
void Dac_Code(uint8_t dacSelector, uint16_t dacData);
void Dac_Load(uint8_t dacSelector, uint16_t dacData);
void Dac_CodeLoadAll(uint8_t dacSelector, uint16_t dacData);
void Dac_CodeLoad(uint8_t dacSelector, uint16_t dacData);
void Dac_CodeAll(uint16_t dacData);
void Dac_LoadAll(void);
void Dac_CodeAllLoadAll(uint16_t dacData);
void DacSetVoltage(uint16_t output);

#endif
