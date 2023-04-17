/*
 * Copyright (c) 2022 Mr. Green's Workshop https://www.MrGreensWorkshop.com
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <stdio.h>
#include <zephyr/drivers/uart.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_MAIN_LOG_LEVEL);

// Devicetree
#define CONSOLE_DEVICE DEVICE_DT_GET(DT_CHOSEN(zephyr_console))
#define USB_CDC_ACM_CHECK DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_console), zephyr_cdc_acm_uart)

void main(void) {
#if (IS_ENABLED(USB_CDC_ACM_CHECK) && IS_ENABLED(CONFIG_LOG))
	const struct device *const console_dev = CONSOLE_DEVICE;
	uint32_t dtr_line = 0;

	while (!dtr_line) {
		uart_line_ctrl_get(console_dev, UART_LINE_CTRL_DTR, &dtr_line);
		k_sleep(K_MSEC(100));
	}
#endif

	LOG_INF("PicoDRO application.");

	while (1) {
		// For debugging purpose
		printf("Hello World!\n");
		k_sleep(K_MSEC(1000));
	}
}
