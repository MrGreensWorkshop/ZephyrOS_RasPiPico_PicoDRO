/*
 * Copyright (c) 2022 Mr. Green's Workshop https://www.MrGreensWorkshop.com
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <stdio.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_MAIN_LOG_LEVEL);

void main(void) {
	LOG_INF("PicoDRO application.");

	while (1) {
		// For debugging purpose
		printf("Hello World!\n");
		LOG_DBG("Log test");
		k_sleep(K_MSEC(1000));
	}
}
