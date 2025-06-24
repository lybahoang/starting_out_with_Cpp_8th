// Specification file for the MathStack class.
#ifndef MATH_STACK_H
#define MATH_STACK_H
#include "IntStack.h"

class MathStack : public IntStack
{
public:
    // Constructor.
    MathStack(int size) : IntStack(size) { }

    // MathStack operations.
    void add();
    void subtract();
};
#endif