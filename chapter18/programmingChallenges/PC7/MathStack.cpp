#include "MathStack.h"

/**
 * Operation add(): Pops the top two values off the stack, adds them,
 * and pushes their sum onto the stack.
 */
void MathStack::add()
{
    int num1, sum;

    // Pop the first two values off the stack.
    pop(num1);
    pop(sum);

    // Add the two values and store in sum.
    sum = sum + num1;

    // Push the sum back onto the stack.
    push(sum);
}
