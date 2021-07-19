/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "mgos.h"
#include "mgos_i2c.h"
#include "mgos_htu31df.h"
#include <math.h>

#define MGOS_HTU31DF_DEFAULT_I2CADDR (0x40)

#define MGOS_HTU31DF_READTEMPHUM (0x00)
#define MGOS_HTU31DF_HEATERON (0x04)
#define MGOS_HTU31DF_HEATEROFF (0x02)
#define MGOS_HTU31DF_READREG (0x0A)
#define MGOS_HTU31DF_RESET (0x1E)

#ifdef __cplusplus
extern "C"
{
#endif

  struct mgos_htu31df
  {
    struct mgos_i2c *i2c;
    uint8_t i2caddr;
    struct mgos_htu31df_stats stats;

    float humidity, temperature;
  };

#ifdef __cplusplus
}
#endif
