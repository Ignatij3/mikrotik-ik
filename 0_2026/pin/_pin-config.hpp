#ifndef PIN__PIN_CONFIG_HPP_
#define PIN__PIN_CONFIG_HPP_

#include "stdint.hpp"

namespace io_
{

/**
 * Pin_Config_ is a wrapper for pin configuration structure.
 */
struct Pin_Config_ {
    /**
     * The structure contains GPIO configuration.
     *
     * It contains necessary information to properly initialize an MCU pin.
     *
     * @attention Default GPIO settings are undefined.
     */
    struct Config final {
        typedef uint8 alternate_t;                   //!< Alternate GPIO function. Consult with the datasheet for available alternates.

        static constexpr alternate_t AF_NONE = 0x0;  //!< No alternate function is assigned to the pin.

        /**
         * Specifies whether pin is general I/O, alternate I/O, an analog pin, or any other pin mode.
         */
        enum class mode : uint32 {
            INPUT              = GPIO_MODE_INPUT,               //!< Input Floating Mode.
            OUTPUT__PP         = GPIO_MODE_OUTPUT_PP,           //!< Output Push Pull Mode.
            OUTPUT__OD         = GPIO_MODE_OUTPUT_OD,           //!< Output Open Drain Mode.
            AF_PP              = GPIO_MODE_AF_PP,               //!< Alternate Function Push Pull Mode.
            AF_OD              = GPIO_MODE_AF_OD,               //!< Alternate Function Open Drain Mode.
            ANALOG             = GPIO_MODE_ANALOG,              //!< Analog Mode.
            ANALOG_ADC_CONTROL = GPIO_MODE_ANALOG_ADC_CONTROL,  //!< Analog Mode for ADC conversion (0xB).
            IT_RISING          = GPIO_MODE_IT_RISING,           //!< External Interrupt Mode with Rising edge trigger detection.
            IT_FALLING         = GPIO_MODE_IT_FALLING,          //!< External Interrupt Mode with Falling edge trigger detection.
            IT_RISING_FALLING  = GPIO_MODE_IT_RISING_FALLING,   //!< External Interrupt Mode with Rising/Falling edge trigger detection.
            EVT_RISING         = GPIO_MODE_EVT_RISING,          //!< External Event Mode with Rising edge trigger detection.
            EVT_FALLING        = GPIO_MODE_EVT_FALLING,         //!< External Event Mode with Falling edge trigger detection.
            EVT_RISING_FALLING = GPIO_MODE_EVT_RISING_FALLING   //!< External Event Mode with Rising/Falling edge trigger detection.
        };

        /**
         * Specifies whether to pull the pin up or down, or to leave it floating (with `PULL_NO`).
         */
        enum class pull : uint32 {
            PULL_NO   = GPIO_NOPULL,   //!< No Pull-up or Pull-down activation.
            PULL_UP   = GPIO_PULLUP,   //!< Pull-up activation.
            PULL_DOWN = GPIO_PULLDOWN  //!< Pull-down activation.
        };

        /**
         * Specifies the speed, from `LOW` to `VERY_HIGH`.
         */
        enum class speed : uint32 {
            LOW       = GPIO_SPEED_FREQ_LOW,       //!< Low speed.
            MEDIUM    = GPIO_SPEED_FREQ_MEDIUM,    //!< Medium speed.
            HIGH      = GPIO_SPEED_FREQ_HIGH,      //!< High speed.
            VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH  //!< Very high speed.
        };

        mode  pinMode;                             //!< I/O mode.
        pull  pinPull;                             //!< Pull-up/down resistor setup.
        speed pinSpeed;                            //!< Speed which the pin will support.
        /**
         * A pin may only have 1 alternate function.
         * @note Definitions for alternate functions begin with "GPIO_AF" and are contained in the HAL library.
         */
        uint8 alt;  //!< Alternate pin functions, consult with the datasheet for available alternates.
    };
};

}  // namespace io_

#endif  // PIN__PIN_CONFIG_HPP_