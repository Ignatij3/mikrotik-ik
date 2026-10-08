#ifndef LOGGER__LOGLEVEL_HPP_
#define LOGGER__LOGLEVEL_HPP_

namespace logger_
{

/**
 * log_level_ contains constants that are used internally to specify severity
 * level of the logging output.
 */
enum class log_level_ : char {
    DEBUG    = 0,  //!< `DEBUG` message severity level.
    INFO     = 1,  //!< `INFO` message severity level.
    WARN     = 2,  //!< `WARN` message severity level.
    ERROR    = 3,  //!< `ERROR` message severity level.
    CRITICAL = 4,  //!< `CRITICAL` message severity level.
    /**
     * A program is terminated after printing a `FATAL` message.
     */
    FATAL    = 5  //!< `FATAL` message severity level.
};

}  // namespace logger_

#endif  // LOGGER__LOGLEVEL_HPP_