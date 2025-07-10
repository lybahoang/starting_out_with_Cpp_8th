#ifndef MATHSTACK_H
#define MATHSTACK_H
#include "DynamicIntStack.h"

class MathStack : public DynamicIntStack
{
public:
    // Constructor.
    MathStack() : DynamicIntStack() { }

    // MathStack operations.
    void add();
    void sub();
    void mult();
    void div();
    void addAll();
    void multAll();
};
#endif