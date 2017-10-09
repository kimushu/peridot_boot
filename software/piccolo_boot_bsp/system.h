/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_fast' in SOPC Builder design 'ngs_boot_core'
 * SOPC Builder design path: ../../ngs_boot_core.sopcinfo
 *
 * Generated: Mon Oct 09 20:39:25 JST 2017
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x0fff0020
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 8192
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 1
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_DIVISION_ERROR_EXCEPTION
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 16384
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_fast"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 7
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x0fff0020
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 8192
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 1
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_DIVISION_ERROR_EXCEPTION
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 16384
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 7
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_ONCHIP_FLASH
#define __PERIDOT_HOSTBRIDGE


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/null"
#define ALT_STDERR_BASE 0x0
#define ALT_STDERR_DEV null
#define ALT_STDERR_TYPE ""
#define ALT_STDIN "/dev/null"
#define ALT_STDIN_BASE 0x0
#define ALT_STDIN_DEV null
#define ALT_STDIN_TYPE ""
#define ALT_STDOUT "/dev/null"
#define ALT_STDOUT_BASE 0x0
#define ALT_STDOUT_DEV null
#define ALT_STDOUT_TYPE ""
#define ALT_SYSTEM_NAME "ngs_boot_core"


/*
 * digests configuration
 *
 */

#define DIGESTS_MD5_ENABLE
#define DIGESTS_MD5_STATIC_TABLE


/*
 * flash_writer configuration
 *
 */

#define FLASH_WRITER_OCF_ENABLED
#define FLASH_WRITER_OCF_NAME "/dev/ufm_data"
#define FLASH_WRITER_OCF_READ_ONLY 0
#define FLASH_WRITER_ROOT_NAME "/sys/flash"
#define FLASH_WRITER_SPI_ENABLED
#define FLASH_WRITER_SPI_NAME "/dev/peridot_hostbridge_flash"
#define FLASH_WRITER_SPI_READ_ONLY 0


/*
 * gpio configuration
 *
 */

#define ALT_MODULE_CLASS_gpio altera_avalon_pio
#define GPIO_BASE 0x10000100
#define GPIO_BIT_CLEARING_EDGE_REGISTER 0
#define GPIO_BIT_MODIFYING_OUTPUT_REGISTER 1
#define GPIO_CAPTURE 0
#define GPIO_DATA_WIDTH 30
#define GPIO_DO_TEST_BENCH_WIRING 0
#define GPIO_DRIVEN_SIM_VALUE 0
#define GPIO_EDGE_TYPE "NONE"
#define GPIO_FREQ 25000000
#define GPIO_HAS_IN 0
#define GPIO_HAS_OUT 0
#define GPIO_HAS_TRI 1
#define GPIO_IRQ 16
#define GPIO_IRQ_INTERRUPT_CONTROLLER_ID 0
#define GPIO_IRQ_TYPE "LEVEL"
#define GPIO_NAME "/dev/gpio"
#define GPIO_RESET_VALUE 0
#define GPIO_SPAN 32
#define GPIO_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYSTIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x10000040
#define JTAG_UART_IRQ 8
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * peridot_hostbridge configuration
 *
 */

#define ALT_MODULE_CLASS_peridot_hostbridge peridot_hostbridge
#define PERIDOT_HOSTBRIDGE_BASE 0x10000000
#define PERIDOT_HOSTBRIDGE_CPURESET_KEY 0xdead
#define PERIDOT_HOSTBRIDGE_ID 0x72a90000
#define PERIDOT_HOSTBRIDGE_IRQ 31
#define PERIDOT_HOSTBRIDGE_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PERIDOT_HOSTBRIDGE_NAME "/dev/peridot_hostbridge"
#define PERIDOT_HOSTBRIDGE_SPAN 32
#define PERIDOT_HOSTBRIDGE_TIMESTAMP 1494052269
#define PERIDOT_HOSTBRIDGE_TYPE "peridot_hostbridge"
#define PERIDOT_HOSTBRIDGE_USE_EPCSBOOT 1
#define PERIDOT_HOSTBRIDGE_USE_MESSAGE 1
#define PERIDOT_HOSTBRIDGE_USE_UIDREAD 1


/*
 * peridot_swi_driver configuration
 *
 */

#define PERIDOT_SPI_FLASH_BOOT_OFFSET 0x0
#define PERIDOT_SWI_DRIVER_FLASH_INSTANCE peridot_hostbridge
#define PERIDOT_SWI_FLASH_ENABLE


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 2
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 200.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x16
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 8
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 12
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 8388608
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 6.0
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 21.0
#define SDRAM_T_RFC 63.0
#define SDRAM_T_RP 21.0
#define SDRAM_T_WR 14.0


/*
 * systimer configuration
 *
 */

#define ALT_MODULE_CLASS_systimer altera_avalon_timer
#define SYSTIMER_ALWAYS_RUN 0
#define SYSTIMER_BASE 0x10000020
#define SYSTIMER_COUNTER_SIZE 32
#define SYSTIMER_FIXED_PERIOD 0
#define SYSTIMER_FREQ 25000000
#define SYSTIMER_IRQ 0
#define SYSTIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYSTIMER_LOAD_VALUE 24999
#define SYSTIMER_MULT 0.001
#define SYSTIMER_NAME "/dev/systimer"
#define SYSTIMER_PERIOD 1
#define SYSTIMER_PERIOD_UNITS "ms"
#define SYSTIMER_RESET_OUTPUT 0
#define SYSTIMER_SNAPSHOT 1
#define SYSTIMER_SPAN 32
#define SYSTIMER_TICKS_PER_SEC 1000
#define SYSTIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYSTIMER_TYPE "altera_avalon_timer"


/*
 * ufm_csr configuration
 *
 */

#define ALT_MODULE_CLASS_ufm_csr altera_onchip_flash
#define UFM_CSR_BASE 0x1000f000
#define UFM_CSR_BYTES_PER_PAGE 2048
#define UFM_CSR_IRQ -1
#define UFM_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define UFM_CSR_NAME "/dev/ufm_csr"
#define UFM_CSR_READ_ONLY_MODE 0
#define UFM_CSR_SECTOR1_ENABLED 1
#define UFM_CSR_SECTOR1_END_ADDR 0x3fff
#define UFM_CSR_SECTOR1_START_ADDR 0
#define UFM_CSR_SECTOR2_ENABLED 1
#define UFM_CSR_SECTOR2_END_ADDR 0x7fff
#define UFM_CSR_SECTOR2_START_ADDR 0x4000
#define UFM_CSR_SECTOR3_ENABLED 1
#define UFM_CSR_SECTOR3_END_ADDR 0x1c7ff
#define UFM_CSR_SECTOR3_START_ADDR 0x8000
#define UFM_CSR_SECTOR4_ENABLED 1
#define UFM_CSR_SECTOR4_END_ADDR 0x2afff
#define UFM_CSR_SECTOR4_START_ADDR 0x1c800
#define UFM_CSR_SECTOR5_ENABLED 0
#define UFM_CSR_SECTOR5_END_ADDR 0xffffffff
#define UFM_CSR_SECTOR5_START_ADDR 0xffffffff
#define UFM_CSR_SPAN 8
#define UFM_CSR_TYPE "altera_onchip_flash"


/*
 * ufm_data configuration
 *
 */

#define ALT_MODULE_CLASS_ufm_data altera_onchip_flash
#define UFM_DATA_BASE 0xf800000
#define UFM_DATA_BYTES_PER_PAGE 2048
#define UFM_DATA_IRQ -1
#define UFM_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define UFM_DATA_NAME "/dev/ufm_data"
#define UFM_DATA_READ_ONLY_MODE 0
#define UFM_DATA_SECTOR1_ENABLED 1
#define UFM_DATA_SECTOR1_END_ADDR 0x3fff
#define UFM_DATA_SECTOR1_START_ADDR 0
#define UFM_DATA_SECTOR2_ENABLED 1
#define UFM_DATA_SECTOR2_END_ADDR 0x7fff
#define UFM_DATA_SECTOR2_START_ADDR 0x4000
#define UFM_DATA_SECTOR3_ENABLED 1
#define UFM_DATA_SECTOR3_END_ADDR 0x1c7ff
#define UFM_DATA_SECTOR3_START_ADDR 0x8000
#define UFM_DATA_SECTOR4_ENABLED 1
#define UFM_DATA_SECTOR4_END_ADDR 0x2afff
#define UFM_DATA_SECTOR4_START_ADDR 0x1c800
#define UFM_DATA_SECTOR5_ENABLED 0
#define UFM_DATA_SECTOR5_END_ADDR 0xffffffff
#define UFM_DATA_SECTOR5_START_ADDR 0xffffffff
#define UFM_DATA_SPAN 176128
#define UFM_DATA_TYPE "altera_onchip_flash"

#endif /* __SYSTEM_H_ */
