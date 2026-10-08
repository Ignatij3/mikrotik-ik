#ifndef LOGGER_LOGGER_HPP_
#define LOGGER_LOGGER_HPP_

#include "_loglevel.hpp"
#include "_source.hpp"

/**
 * This namespace contains functions which output to the debug UART.
 *
 * In the code below you will see definitions of the functions.
 * After they are defined, they are deleted from symbol table (with undef)
 * and then redefined with macros which cover actual function calls that we want to make.
 * If specified in the commmand-line - some of the functions will be disabled and replaced with `__NOP()`.
 * Logger also uses some macros to find meta information about the caller:
 * - `__PRETTY_FUNCTION__`, gives full function signature of the caller function
 * - `__FILE_NAME__`, gives file name where logger is called
 * - `__LINE__`, gives line number where logging call is located
 */
namespace logger
{

/**
 * Debug outputs a `DEBUG` level message.
 *
 * @param[in] s message that is going to be sent over UART.
 */
void Debug(const char *s);
#undef Debug

/**
 * Debugf extends `Debug()` function to support `printf`-like argument formatting.
 *
 * @param[in] format format string which specifies the output.
 */
void Debugf(const char *format, ...);
#undef Debugf

// declaring functions as empty if log threshold cuts these off
#if LOG_LEVEL_THRESHOLD >= 1
#  define Debug(s)            __NOP()
#  define Debugf(format, ...) __NOP()
#else
#  define Debug(s)            Log_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::DEBUG, s)
#  define Debugf(format, ...) Logf_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::DEBUG, format, ##__VA_ARGS__)
#endif  // LOG_LEVEL_THRESHOLD >= 1

/**
 * Info outputs an `INFO` level message.
 *
 * @param[in] s message that is going to be sent over UART.
 */
void Info(const char *s);
#undef Info

/**
 * Infof extends `Info()` function to support `printf`-like argument formatting.
 *
 * @param[in] format format string which specifies the output.
 */
void Infof(const char *format, ...);
#undef Infof

// declaring functions as empty if log threshold cuts these off
#if LOG_LEVEL_THRESHOLD >= 2
#  define Info(s)            __NOP()
#  define Infof(format, ...) __NOP()
#else
#  define Info(s)            Log_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::INFO, s)
#  define Infof(format, ...) Logf_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::INFO, format, ##__VA_ARGS__)
#endif  // LOG_LEVEL_THRESHOLD >= 2

/**
 * Warn outputs a `WARNING` level message.
 *
 * @param[in] s message that is going to be sent over UART.
 */
void Warn(const char *s);
#undef Warn

/**
 * Warnf extends `Warn()` function to support `printf`-like argument formatting.
 *
 * @param[in] format format string which specifies the output.
 */
void Warnf(const char *format, ...);
#undef Warnf

// declaring functions as empty if log threshold cuts these off
#if LOG_LEVEL_THRESHOLD >= 3
#  define Warn(s)            __NOP()
#  define Warnf(format, ...) __NOP()
#else
#  define Warn(s)            Log_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::WARN, s)
#  define Warnf(format, ...) Logf_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::WARN, format, ##__VA_ARGS__)
#endif  // LOG_LEVEL_THRESHOLD >= 3

/**
 * Error outputs an `ERROR` level message.
 *
 * @param[in] s message that is going to be sent over UART.
 */
void Error(const char *s);
#undef Error

/**
 * Errorf extends `Error()` function to support `printf`-like argument formatting.
 *
 * @param[in] format format string which specifies the output.
 */
void Errorf(const char *format, ...);
#undef Errorf

// declaring functions as empty if log threshold cuts these off
#if LOG_LEVEL_THRESHOLD >= 4
#  define Error(s)           __NOP()
#  define Errorf(format, ...) __NOP()
#else
#  define Error(s)           Log_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::ERROR, s)
#  define Errorf(format, ...) Logf_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::ERROR, format, ##__VA_ARGS__)
#endif  // LOG_LEVEL_THRESHOLD >= 4

/**
 * Fatal outputs a `FATAL` level message.
 *
 * After the message has been tranceived, `SystemReset()` is then called.
 * This is useful to prevent further execution of a program to avoid bunch of issue-unrelated
 * error messages to stack up.
 *
 * If `FATAL` level outputs are disabled - the function will do nothing.
 *
 * @param[in] s message that is going to be sent over UART.
 */
void Fatal(const char *s);
#undef Fatal

/**
 * Fatalf extends `Fatal()` function to support `printf`-like argument formatting.
 *
 * If `FATAL` level outputs are disabled - the function will do nothing.
 *
 * @param[in] format format string which specifies the output.
 */
void Fatalf(const char *format, ...);
#undef Fatalf

// declaring functions as empty if log threshold cuts these off
#if LOG_LEVEL_THRESHOLD >= 6
#  define Fatal(s)            __NOP()
#  define Fatalf(format, ...) __NOP()
#else
#  define Fatal(s)            Log_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::FATAL, s)
#  define Fatalf(format, ...) Logf_()(__PRETTY_FUNCTION__, __FILE_NAME__, __LINE__, logger_::log_level_::FATAL, format, ##__VA_ARGS__)
#endif  // LOG_LEVEL_THRESHOLD >= 6

}  // namespace logger

#endif  // LOGGER_LOGGER_HPP_