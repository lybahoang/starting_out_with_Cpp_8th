#include "MathStack.h"
#include <iostream>
using namespace std;

/**
 * Operation add(): Pops the top two values off the stack, adds them,
 * and pushes their sum onto the stack.
 */
void MathStack::add()
{
    int num1, num2;

    // Pop the first two values off the stack.
    pop(num1);
    pop(num2);
    
    // Push the sum back onto the stack.
    push(num1 + num2);
}

/**
 * Operation sub(): Pops the top two values off the stack, subtracts the 
 * second value from the first value, and pushes its difference back onto
 * the stack.
 */
void MathStack::sub()
{
    int difference, num2;

    // Pop two top values off the stack.
   pop(difference);
   pop(num2);

   // Push the difference getting from subtracting the second value from
   // the first value.
   push(difference - num2);
}

/**
 * Operation mult(): Pops the two top values off the stack, multiples them, and
 * pushes their product onto the stack.
 */
void MathStack::mult()
{
    int num1, num2;

    // Pop the two top values off the stack.
    pop(num1);
    pop(num2);

    // Push their product to the stack.
    push(num1 * num2);
}

/**
 * Operation div(): Pops the two top values off the stack, divides the second value
 * by the first, and pushes the quotient onto the stack.
 */
void MathStack::div()
{
    int num1, num2;

    // Pop the two top values off the stack.
    pop(num1);
    pop(num2);

    // Push the quotient onto the stack.
    push(num1 / num2);
}

/**
 * Operation addAll(): Pops all values off the stack, adds them, and pushes their sum
 * onto the stack.
 */
void MathStack::addAll()
{
    while (this->getNumNodes() > 1)
    {
        add();
    }
}

/**
 * Operation multAll(): Pops all values off the stack, multiples them, and pushes
 * their product onto the stack.
 */
void MathStack::multAll()
{
    while (this->getNumNodes() > 1)
    {
        mult();
    }
}
