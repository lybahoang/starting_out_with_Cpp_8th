#ifndef MATHSTACK_H
#define MATHSTACK_H

#include "DynamicStack.h"

template <class T>
class MathStack : public DynamicStack<T>
{
public:
    // Constructor.
    MathStack() : DynamicStack<T>() { };

    // Math stack operations.
    void add();
    void sub();
    void mult();
    void div();
    void addAll();
    void multAll();
};

/**
 * Operation add(): The function pops the top two values off the stack, adds them,
 * and then pushes their sum onto the stack.
 */
template <class T>
void MathStack<T>::add()
{
    T value1, value2;

    // Pop the top two values off the stack.
    this->pop(value1);
    this->pop(value2);

    // Push their sum onto the stack.
    this->push(value1 + value2);
}

/**
 * Operation sub(): The function pops the top two values off the stack, subtracts
 * the second value from the first value, and pushes its difference onto the stack.
 */
template <class T>
void MathStack<T>::sub()
{
    T value1, value2;

    // Pop the top two values off the stack.
    this->pop(value1);
    this->pop(value2);

    // Push their difference onto the stack.
    this->push(value1 - value2);
}

/**
 * Operation mult(): The function pops the top two values off the stack, multiples them,
 * and pushes the product onto the stack.
 */
template <class T>
void MathStack<T>::mult()
{
    T value1, value2;

    // Pop the top two values off the stack.
    this->pop(value1);
    this->pop(value2);

    // Push their product onto the stack.
    this->push(value1 * value2);
}

/**
 * Operation div(): The function pops the top two values off the stack, divides the second
 * value by the first one, and pushes their quotient onto the stack.
 */
template <class T>
void MathStack<T>::div()
{
    T value1, value2;

    // Pop the top two values off the stack.
    this->pop(value1);
    this->pop(value2);

    // Push their quotient onto the stack.
    this->push(value1 / value2);
}

/**
 * Operation addAll(): The function pops all the values off the stack, adds them, and pushes
 * their sum onto the stack.
 */
template <class T>
void MathStack<T>::addAll()
{
    // If the stack is empty, do nothing.
    if (this->isEmpty())
        return;

    // Variables.
    T value;

    // Pop the firt top value off the stack and assign it to sum.
    this->pop(value);
    T sum = value;

    // While the stack is not empty, pop the top value and add it to sum.
    while (!(this->isEmpty()))
    {
        this->pop(value);
        sum += value;
    }

    // Push sum onto the stack.
    this->push(sum);
}

/**
 * Operation multAll(): The function pops all the values off the stack, multiples them,
 * and pushes their product onto the stack.
 */
template <class T>
void MathStack<T>::multAll()
{
    // If the stack is empty, then do nothing.
    if (this->isEmpty())
        return;
    
    // Variable.
    T value;

    // Pop the top value of the stack and assign it to product.
    this->pop(value);
    T product = value;

    // While the stack is not empty, pop its top value and multiply with product.
    while (!(this->isEmpty()))
    {
        this->pop(value);
        product *= value;
    }

    // Push the product onto the stack.
    this->push(product);
}
#endif