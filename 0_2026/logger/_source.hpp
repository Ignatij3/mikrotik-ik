#ifndef LOGGER__SOURCE_HPP_
#define LOGGER__SOURCE_HPP_

#include "_loglevel.hpp"
#include "stdint.hpp"

namespace logger
{

/**
 * This structure serves as a wrapper to a function which allows for strict type-checking.
 */
struct Log_ final {
    /**
     * Log_ outputs string to the UART with appropriate full prefix and severity prefix.
     *
     * @param[in] func function name, given with `__PRETTY_FUNCTION__`.
     * @param[in] file file name, given with `__FILE_NAME__`.
     * @param[in] line line number, given with `__LINE__`.
     * @param[in] s string to be transmitted over the UART.
     * @param[in] logl log severity level.
     */
    static void operator()(const char* func, const char* file, int32 line, logger_::log_level_ logl, const char* s);
};

/**
 * This structure serves as a wrapper to a function which allows for strict type-checking.
 */
struct Logf_ final {
    /**
     * Logf_ outputs formatted string to the UART with appropriate full prefix and severity prefix.
     *
     * Current formatted string limitation is 256 symbols.
     *
     * @param[in] func function name, given with `__PRETTY_FUNCTION__`.
     * @param[in] file file name, given with `__FILE_NAME__`.
     * @param[in] line line number, given with `__LINE__`.
     * @param[in] logl log severity level.
     * @param[in] format format string which specifies the output to the UART.
     */
    static void operator()(const char* func, const char* file, int32 line, logger_::log_level_ logl, const char* format, ...);
};

}  // namespace logger

#endif  // LOGGER__SOURCE_HPP_