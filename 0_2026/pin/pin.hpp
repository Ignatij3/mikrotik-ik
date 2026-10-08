#ifndef PIN_PIN_HPP_
#define PIN_PIN_HPP_

#include "_pin-config.hpp"
#include "class-macros.hpp"

namespace io
{

/**
 * Used for writing logic to a Pin.
 */
constexpr bool CLEAR = false;  //!< Logic low.

/**
 * Used for writing logic to a Pin.
 */
constexpr bool SET = true;  //!< Logic high.

/**
 * This class represents Pin state for a single GPIO on an MCU.
 */
class Pin : public io_::Pin_Config_ {
    DISABLE_CONSTRUCTORS(Pin)
public:
    /**
     * Constructor creates a Pin instance which can be used to manage underlying GPIO.
     *
     * @param[in] hw_pin_config GPIO port and pin number.
     * @param[in] config configuration for the pin.
     */
    inline explicit Pin(const hw_config::Pin& hw_pin_config, const Config& config) :
        Port_(hw_pin_config.port), Pin_Pos_(hw_pin_config.pin), Conf_(config)
    {}

    /**
     * Init initializes the GPIO pin which was passed to the constructor.
     */
    void Init() const;

    /**
     * DeInit disables clock to the pin for better power consumption.
     */
    void DeInit() const;

    /**
     * Write will set either logic HIGH or LOW on the gpio.
     * @param[in] state high or low pin logic.
     */
    inline void Write(bool state) const { HAL_GPIO_WritePin(Port_, (uint16)Pin_Pos_, (GPIO_PinState)state); }

    /**
     * Read will report either HIGH or LOW logic on the gpio.
     * @retval true pin logic "high".
     * @retval false pin logic "low".
     */
    inline bool Read() const { return (bool)HAL_GPIO_ReadPin(Port_, (uint16)Pin_Pos_); }

    /**
     * Toggle will toggle the state of the pin.
     */
    inline void Toggle() const { HAL_GPIO_TogglePin(Port_, (uint16)Pin_Pos_); }

private:
    const Port   Port_;     //!< GPIO port.
    const uint32 Pin_Pos_;  //!< GPIO number.
    const Config Conf_;     //!< Pin configuration.

    /**
     * Enable_Clock_ supplies clock to the port on which the pin sits.
     *
     * @param[in] port GPIO port on which a clock should be enabled.
     */
    static void Enable_Clock_(const Port port);

    /**
     * Disable_Clock_ supplies clock to the port on which the pin sits.
     * @warning Calling this function prevents from using GPIOs on the same port!
     * It is implicitly called during object destruction and during DeInit.
     *
     * @param[out] port GPIO port on which a clock should be disabled.
     */
    static void Disable_Clock_(const Port port);
};

}  // namespace io

#endif  // PIN_PIN_HPP_