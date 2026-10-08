#ifndef SMT50__SMT50_ERROR_HPP_
#define SMT50__SMT50_ERROR_HPP_

#include "error.hpp"

namespace sensors_
{

/**
 * Smt50_Error_ is a wrapper for smt50 error structure.
 *
 * @attention This class must only be inherited by the @ref sensors::Smt50 "smt 50" class.
 */
struct Smt50_Error_ {
    /**
     * The structure contains status codes for the smt50 module.
     */
    struct Error final : public ErrorBase {
        /**
         * This enumeration contains list of status codes.
         */
        enum code : char {
            OK,              //!< No error.
            ADC_READ_ERROR,  //!< Error while reading the ADC.
            NO_POWER         //!< Power switch has not been turned on.
        };

        /**
         * This constructor sets an error code from enumeration type.
         *  @param[in] err error code.
         */
        inline Error(code err) : ErrorBase(err) {}

        /**
         * @copydoc ErrorBase::String()
         */
        const char* String() const override
        {
            if (error == OK) {
                return "OK";
            } else if (error == ADC_READ_ERROR) {
                return "Internal ADC error";
            } else if (error == NO_POWER) {
                return "Power switch has not been turned on";
            }
            return "{Smt50_Error_ INCORRECT CODE}";
        }
    };
};

}  // namespace sensors_

#endif  // SMT50__SMT50_ERROR_HPP_