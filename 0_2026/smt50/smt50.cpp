#include "smt50.hpp"

#include "logger.hpp"

namespace sensors
{

void Smt50::Init()
{
    OnOff_.Init();
    Moisture_.Init();
    Temperature_.Init();
}

void Smt50::DeInit()
{
    OnOff_.DeInit();
    Moisture_.DeInit();
    Temperature_.DeInit();
}

void Smt50::Turn_On() const
{
    OnOff_.Write(true);
}

Smt50::Error Smt50::Read_Moisture(float &hum)
{
    if (OnOff_.Read() == io::CLEAR) {
        return Error::NO_POWER;
    }

    float volt = 0;

    io::ADC::Error err = Moisture_.Read_Voltage(volt);
    if (err != 0) {
        logger::Errorf("Error reading humidity: %s", err.String());
        return Error::ADC_READ_ERROR;
    }

    // formula given by datasheet
    hum = (volt * 50.f) / 3.f;
    return 0;
}

Smt50::Error Smt50::Read_Temperature(float &temp)
{
    if (OnOff_.Read() == io::CLEAR) {
        return Error::NO_POWER;
    }

    float volt = 0;

    io::ADC::Error err = Temperature_.Read_Voltage(volt);
    if (err != 0) {
        logger::Errorf("Error reading temperature: %s", err.String());
        return Error::ADC_READ_ERROR;
    }

    // formula given by datasheet
    temp = (volt - 0.5f) / 0.01f;
    return 0;
}

}  // namespace sensors
