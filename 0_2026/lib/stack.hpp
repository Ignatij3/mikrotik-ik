#ifndef LIB_STACK_HPP_
#define LIB_STACK_HPP_

#include "class-macros.hpp"
#include "container.hpp"

namespace utils
{

/**
 * This structure implements an interface of std::stack, with embedded-oriented implementation.
 *
 * The class preallocates the memory needed to store all of the items at compile-time.
 * 
 * Container base class implements data handling and general methods like "push" or "empty" (returns true if empty).
 *
 * @tparam T datatype to be stored.
 * @tparam Size size of the array which will be constructed.
 */
template<typename T, uint32 Size>
class stack : public Container<T, Size> {
    DISABLE_CONSTRUCTORS(stack)
public:
    /**
     * @copydoc Container::Container()
     */
    inline constexpr stack() : Container<T, Size>() {}

    /**
     * @copydoc Container::Container(const T&)
     */
    inline constexpr stack(const T& val) : Container<T, Size>(val) {}

    /**
     * pop removes element from the stack.
     *
     * If the stack is empty, nothing happens.
     */
    constexpr void pop()
    {
        if (!this->empty()) {
            this->NItems_--;
        }
    }

    /**
     * top returns reference to the top element in the stack. This is the most recently pushed element.
     *
     * This element will be removed on a call to pop().
     *
     * @return the last pushed element. If this function is called before pushing the first element,
     * it will result in undefined behaviour.
     */
    inline constexpr const T& top() const { return this->Data_[this->NItems_ - 1]; }
};

}  // namespace utils

#endif  // LIB_STACK_HPP_