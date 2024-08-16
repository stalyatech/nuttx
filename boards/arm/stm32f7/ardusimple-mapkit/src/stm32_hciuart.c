/****************************************************************************
 * boards/arm/stm32f7/ardusimple-mapkit/src/stm32_hciuart.c
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

#include <stdio.h>
#include <debug.h>
#include <errno.h>

#include <nuttx/wireless/bluetooth/bt_uart_shim.h>

#include "ardusimple-mapkit.h"

#ifdef HAVE_HCIUART

/****************************************************************************
 * Include the firmware blob(s).
 ****************************************************************************/

#include "../firmware/src/bt_fw.h"

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: hciuart_dev_initialize
 *
 * Description:
 *   This function is called by board initialization logic to configure the
 *   Bluetooth HCI UART driver
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero is returned on success.  Otherwise, a negated errno value is
 *   returned to indicate the nature of the failure.
 *
 ****************************************************************************/

int hciuart_dev_initialize(void)
{
  int ret;

  /* Instantiate the HCI UART lower half interface
   * Then initialize the HCI UART upper half driver with the bluetooth stack
   */

  ret = btuart_register(btuart_shim_getdevice(BT_UART_DEVPATH));
  if (ret < 0)
    {
      wlerr("ERROR: btuart_register() failed: %d\n", ret);
    }

  return ret;
}

#endif /* HAVE_HCIUART */
