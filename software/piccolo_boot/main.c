/*
 * main.c
 *
 *  Created on: 2017/05/02
 *      Author: shuta
 */

#include "rubic_fwup.h"
#include "system.h"
#include "linker.h"

static const rubic_fwup_memory memories[] = {
	{
		// User-side FPGA configuration
		.name = "img",
		.path = FLASH_WRITER_ROOT_NAME "/image1",
		.offset = 0,
		.length = -1,
	},
	{
		// On-chip memory for user-side bootloader
		.name = "ufm",
		.path = FLASH_WRITER_ROOT_NAME "/ufm",
		.offset = 0,
		.length = -1,
	},
	{
		// SPI flash head for user-side firmware
		.name = "spi",
		.path = FLASH_WRITER_ROOT_NAME "/spi",
		.offset = 0,
		.length = 512 * 1024,
	},
	{
		.name = NULL,
	}
};

int main(void)
{
	return rubic_fwup_service(MESSAGE_REGION_BASE, MESSAGE_REGION_SPAN, memories);
}
