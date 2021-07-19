# HTU31D(F) I2C Driver

A Mongoose library for Measurement Specialities HTU31D(F) integrated circuit.


## Example application

An example program using a timer to read data from the sensor every 5 seconds:

```
#include "mgos.h"
#include "mgos_i2c.h"
#include "mgos_htu31df.h"

static struct mgos_htu31df *s_htu31df;

static void timer_cb(void *user_data) {
  float temperature, humidity;

  temperature=mgos_htu31df_getTemperature(s_htu31df);
  humidity=mgos_htu31df_getHumidity(s_htu31df);

  LOG(LL_INFO, ("htu31df temperature=%.2f humidity=%.2f", temperature, humidity));

  (void) user_data;
}

enum mgos_app_init_result mgos_app_init(void) {
  struct mgos_i2c *i2c;

  i2c=mgos_i2c_get_global();
  if (!i2c) {
    LOG(LL_ERROR, ("I2C bus missing, set i2c.enable=true in mos.yml"));
  } else {
    s_htu31df=mgos_htu31df_create(i2c, 0x40); // Default I2C address
    if (s_htu31df) {
      mgos_set_timer(5000, true, timer_cb, NULL);
    } else {
      LOG(LL_ERROR, ("Could not initialize sensor"));
    }
  }
  return MGOS_APP_INIT_SUCCESS;
}
```

# Disclaimer

This project is not an official Google project. It is not supported by Google
and Google specifically disclaims all warranties as to its quality,
merchantability, or fitness for a particular purpose.
