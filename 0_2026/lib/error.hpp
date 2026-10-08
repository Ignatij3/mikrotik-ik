#ifndef LIB_ERROR_HPP_
#define LIB_ERROR_HPP_

/**
 * Any error status code implementation must derive from this class in order to implement an error API.
 * 
 * This is a QOL improvement for the codebase. Implementation of the ErrorBase is made such
 * that is mimics GoLang style of error handling.
 *
 * A derived class must implement:
 * 1. enumeration called "code" of type "char", where the first value is called "OK" and has value 0.
 * If error codes have specific values that are outside [0;255] range, they may be implemented with wchar.
 * 2. String() function which returns name of the enumeration member to which "error" variable is set, in string form.
 */
struct ErrorBase {
    /**
     * Constructor sets an error value.
     * @param[in] err error code.
     */
    inline ErrorBase(char err) : error(err) {}

    char error;  //!< Variable which contains a set error code.

    /**
     * This operator checks if passed error code (rhs) is the same as the saved code.
     * @param[in] rhs error code against which the comparison is made.
     * @return whether the error codes are the same.
     */
    inline bool operator==(const char& rhs) const { return rhs == error; }

    /**
     * This operator checks if passed error code (rhs) is not the same as the saved code.
     * @param[in] rhs error code against which the comparison is made.
     * @return whether the error codes are different.
     */
    inline bool operator!=(const char& rhs) const { return rhs != error; }

    /**
     * String converts an error code to a string representation.
     * @return stringified error code.
     */
    virtual const char* String() const = 0;
};

#endif  // LIB_ERROR_HPP_