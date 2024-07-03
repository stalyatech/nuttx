/****************************************************************************
 * boards/arm/stm32f7/ardusimple-sbc/src/stm32_bno085_i2c.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/kthread.h>
#include <nuttx/board.h>
#include <arch/board/board.h>
#include <nuttx/sensors/ublox_gps.h>

#include <stdio.h>
#include <debug.h>
#include <errno.h>

#include "ardusimple-sbc.h"

#if defined(CONFIG_SENSORS_GPS)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_gnss_initialize
 *
 * Description:
 *   GNSS driver registration
 *
 * Input Parameters:
 *   name    - Serial port name that connected to the GPS device.
 *   devno   - The user specifies which device of this type, from 0.
 *   nbuffer - The number of events that the circular buffer can hold.
 *
 * Returned Value:
 *   Zero (OK) or positive on success; a negated errno value on failure.
 *
 ****************************************************************************/

int board_gnss_initialize(FAR const char *name, int devno, uint32_t nbuffer)
{
  return ublox_gps_init(name, devno, nbuffer);
}

#endif /* CONFIG_SENSORS_GPS */
