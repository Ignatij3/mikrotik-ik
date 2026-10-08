#ifndef APP
#define APP

#include "logger.hpp"
#include "smt50.hpp"
#include "time-macros.hpp"

/**
 * This function tests the Smt50 sensor.
 *
 * @note This function does not exit.
 *
 * Every loop it should print ground moisture and temperature followed by a 15 second sleep.
 */
void app();

void app()
{
    sensors::Smt50 sensor(hw_config::SENSOR1);

    float moisture    = 0;
    float temperature = 0;
    while (true) {
        sensor.Init();
        sensor.Turn_On();

        sensor.Read_Moisture(moisture);
        sensor.Read_Temperature(temperature);

        logger::Infof("Current humidity: %.6f", (double)moisture);
        logger::Infof("Current temperature: %.6f", (double)temperature);

        sensor.Turn_Off();
        sensor.DeInit();

        base::DeepSleep(15 * SECOND);
    }
}

#endif  // APP