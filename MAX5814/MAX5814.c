#include "MAX5814.h"

I2C_HandleTypeDef *dacI2C;

void Dac_WriteCommand(uint8_t *dacData)
{
	uint8_t t_dacAdd = 0x20 | DAC_ADDRESS << 1 | DAC_WRITE_OPERATION;
	HAL_I2C_Master_Transmit(&dacI2C, t_dacAdd, dacData, 3, 10);
}

void Dac_ReadCommand(uint8_t *dacData)
{
	uint8_t t_dacAdd = 0x20 | DAC_ADDRESS << 1 | DAC_Read_OPERATION;
	HAL_I2C_Master_Transmit(&dacI2C, t_dacAdd, dacData, 3, 10);
}

void Dac_Init(I2C_HandleTypeDef *hi2c)
{
	dacI2C = hi2c;

	Dac_Config(DAC_DISABLE_LATCH | DAC_SEL_ALL, DAC_SEL_A | DAC_SEL_B | DAC_SEL_C | DAC_SEL_D);
	Dac_Reference(DAC_REF_EXT | DAC_REF_PWR_ON);
}

void Dac_Config(uint8_t dacLatch, uint8_t dacConfigSelector)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CONFIG | dacLatch;
	t_dacBuffer[1] = dacConfigSelector;
	t_dacBuffer[2] = 0x00;

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_Reference(uint8_t dacRefConfig)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_REF | dacRefConfig;
	t_dacBuffer[1] = 0x00;
	t_dacBuffer[2] = 0x00;

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_Code(uint8_t dacSelector, uint16_t dacData)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CODEn | dacSelector;
	t_dacBuffer[1] = (uint8_t)((dacData >> 4) & 0xFF);
	t_dacBuffer[2] = (uint8_t)((dacData << 4) & 0xF0);

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_Load(uint8_t dacSelector, uint16_t dacData)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_LOADn | dacSelector;
	t_dacBuffer[1] = 0x00;
	t_dacBuffer[2] = 0x00;

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_CodeLoadAll(uint8_t dacSelector, uint16_t dacData)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CODEn_LOAD_ALL | dacSelector;
	t_dacBuffer[1] = (uint8_t)((dacData >> 4) & 0xFF);
	t_dacBuffer[2] = (uint8_t)((dacData << 4) & 0xF0);

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_CodeLoad(uint8_t dacSelector, uint16_t dacData)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CODEn_LOADn | dacSelector;
	t_dacBuffer[1] = (uint8_t)((dacData >> 4) & 0xFF);
	t_dacBuffer[2] = (uint8_t)((dacData << 4) & 0xF0);

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_CodeAll(uint16_t dacData)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CODE_ALL;
	t_dacBuffer[1] = (uint8_t)((dacData >> 4) & 0xFF);
	t_dacBuffer[2] = (uint8_t)((dacData << 4) & 0xF0);

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_LoadAll(void)
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_LOAD_ALL;
	t_dacBuffer[1] = 0x00;
	t_dacBuffer[2] = 0x00;

	Dac_WriteCommand(t_dacBuffer);
}

void Dac_CodeAllLoadAll(uint16_t dacData);
{
	uint8_t t_dacBuffer[3];

	t_dacBuffer[0] = DAC_CMD_CODE_ALL_LOAD_ALL;
	t_dacBuffer[1] = (uint8_t)((dacData >> 4) & 0xFF);
	t_dacBuffer[2] = (uint8_t)((dacData << 4) & 0xF0);

	Dac_WriteCommand(t_dacBuffer);
}



void DacSetVoltage(uint16_t output)
{
	unsigned int i;

	for (i = 0; i < 3; i++)
	{
		dacBuffer[i] = 0x00;
	}

	dacBuffer[1] = output / 16;
	dacBuffer[2] = (output % 16) << 4;
	
	HAL_I2C_Master_Transmit(&dacI2C, dacAdd, dacBuffer, 3, 10);
}
