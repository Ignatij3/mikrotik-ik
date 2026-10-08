#ifndef SMT50_SMT50_HPP_
#define SMT50_SMT50_HPP_

#include "_smt50-error.hpp"
#include "adc.hpp"
#include "pin.hpp"
#include "class-macros.hpp"

namespace sensors
{

/**
 * This class implements the Smt50 sensor module.
 *
 * Usage information:
 * First call @ref Init(), followed by @ref Turn_On().
 * The @ref Turn_On() function contains a small delay after which measurements can be made.
 * At this moment the module is running and drawing power.
 * To get measurements call the @ref Read_Moisture(float&) and Read_Temperature(float&) functions.
 * To finish working, call the @ref Turn_Off() and @ref DeInit() functions in order.
 */
class Smt50 : public sensors_::Smt50_Error_ {
    DISABLE_CONSTRUCTORS(Smt50)
public:
    /**
     * Constructor instantiates GPIO and ADC.
     *
     * @param[in] module hw_config for the sensor module. For instance: hw_config::SENSOR1.
     */
    Smt50(hw_config::Module module) :
        OnOff_(module.onOff, io::Pin::CONF_OUTPUT_PP), Moisture_(module.adc0), Temperature_(module.adc1)
    {}

    /**
     * Deconstructor calls the DeInit function.
     */
    ~Smt50() { DeInit(); }

    /**
     * Initialize the on/off gpio and two ADC.
     */
    void Init();

    /**
     * De-Initialize the on/off gpio and two ADCs, and disable two clocks.
     */
    void DeInit();

    /**
     * Turn on the SMT50 by turning a power switch on and waiting 5ms such that the device is started correctly.
     */
    void Turn_On() const;

    /**
     * Turn off the SMT50 by turning a power switch off.
     */
    void inline Turn_Off() const { OnOff_.Write(false); }

    /**
     * Read the water content using the SMT50.
     *
     * The moisture content lies in a range of 0 to 50% volumetric water content (VWC).
     * It should have a accuracy of ±2% VWC.
     *
     * @param[out] moist moisture reading is stored here.
     *
     * @retval 1. @ref sensors_::Smt50_Error_::Error::ADC_READ_ERROR "ADC_READ_ERROR" if an error occurred in the ADC.
     * @retval 2. @ref sensors_::Smt50_Error_::Error::NO_POWER "NO_POWER" if power switch is turned off.
     * @retval 3. @ref sensors_::Smt50_Error_::Error::OK "OK" when measurement was successfull.
     */
    Error Read_Moisture(float &moist);

    /**
     * Read the temperature using the SMT50.
     *
     * The tempoerature range is -20 to +85°C.
     * It has a typical accuracy of ±0.8°C.
     *
     * @param[out] temp temperature reading is stored here.
     *
     * @retval 1. @ref sensors_::Smt50_Error_::Error::ADC_READ_ERROR "ADC_READ_ERROR" if an error occurred in the ADC.
     * @retval 2. @ref sensors_::Smt50_Error_::Error::NO_POWER "NO_POWER" if power switch is turned off.
     * @retval 3. @ref sensors_::Smt50_Error_::Error::OK "OK" when measurement was successfull.
     */
    Error Read_Temperature(float &temp);

protected:
    const io::Pin  OnOff_;        //!< GPIO Instance.
    io::ADC        Moisture_;     //!< ADC Moisture Instance.
    io::ADC        Temperature_;  //!< ADC Temperature Instance.
};

}  // namespace sensors

#endif  // SMT50_SMT50_HPP_