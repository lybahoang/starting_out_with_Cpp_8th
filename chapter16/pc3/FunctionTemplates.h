#ifndef FUNCTION_TEMPLATES_H
#define FUNCTION_TEMPLATES_H

/***
 * Function to return the larger number between
 * two numbers.
 */
template <class T>
T minimum(const T &num1, const T &num2)
{
    return (num1 >= num2 ? num2 : num1);
}

/***
 * Function to return the smaller number
 * between two numbers.
 */
template <class T>
T maximum(const T &num1, const T &num2)
{
    return (num1 >= num2 ? num1 : num2);
}

#endif