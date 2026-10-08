#ifndef LIB_CLASS_MACROS_HPP_
#define LIB_CLASS_MACROS_HPP_

/**
 * DISABLE_CONSTRUCTORS disables copy and assignment constructors to prevent complex objects from being implicitly copied.
 *
 * @attention This should be used in every class that does not act as a structure.
 * When passed as a function parameter, classes get copied.
 * When a function exits, this copy gets destroyed which results in a hardfault.
 *
 * @param[in] className class name within which the macro is used.
 */
#define DISABLE_CONSTRUCTORS(className)              \
    className(className&)                  = delete; \
    className(const className&)            = delete; \
    className& operator=(className)        = delete; \
    className& operator=(className&)       = delete; \
    className& operator=(const className&) = delete;

#endif  // LIB_CLASS_MACROS_HPP_