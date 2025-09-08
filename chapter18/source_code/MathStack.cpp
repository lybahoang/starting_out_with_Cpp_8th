// Implementation file for the MathStack class.
#include "MathStack.h"

/***
 * Member function - add()
 * This function pops the first two values off the stack 
 * and adds them. The sum is pushed onto the stack.
 */
void MathStack::add()
{
    int num, sum;
    
    // Pop the first two values off the stack.
    pop(num);
    pop(sum);

    // Add the two values, store in sum.
    sum = sum + num;

    // Push sum back onto the stack.
    push(sum);
}

/***
 * Member function - subtract()
 * This function pops the first two values off the stack.
 * The second value is subtracted from the first value.
 * The difference is pused onto the stack.
 */
void MathStack::subtract()
{
    int num, diff;

    // Pop the first two values off the stack.
    pop(diff);
    pop(num);

    // Subtract the second value from the first value.
    diff = diff - num;

    // Push diff back onto the stack.
    push(diff);
}