/*
 * Copyright © 2017-2022 The Crust Firmware Authors.
 * SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0-only
 */

#include <device.h>
#include <intrusive.h>
#include <stdint.h>
#include <watchdog.h>
#include <watchdog/sun9i-a80-twd.h>

#include "watchdog.h"

/**
 * Get the ops for the watchdog controller device.
 */
static inline const struct watchdog_driver_ops *
watchdog_ops_for(const struct device *dev)
{
	const struct watchdog_driver *drv =
		container_of(dev->drv, const struct watchdog_driver, drv);

	return &drv->ops;
}

const struct device *
watchdog_get(void)
{
	return device_get_or_null(&r_twd.dev);
}

void
watchdog_reset_system(const struct device *dev)
{
	watchdog_ops_for(dev)->reset_system(dev);
}

void
watchdog_restart(const struct device *dev)
{
	watchdog_ops_for(dev)->restart(dev);
}
