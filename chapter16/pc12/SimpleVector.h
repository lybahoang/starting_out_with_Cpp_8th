#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H
#include <new>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class SimpleVector
{
protected:
    T *arrayPtr;            // To point to the allocated array.
    int arraySize;          // Number of elements in the array.
    void memoryError();     // Handles memory allocation errors.
    void subscriptError();  // Handles subscripts out of range.
    void popbackError();    // Handles no values to pop back.
public:
    // Default constructor.
    SimpleVector()
        { arrayPtr = nullptr; arraySize = 0; }
    
    // Constructor.
    SimpleVector(int size);

    // Copy constructor.
    SimpleVector(const SimpleVector &other);

    // Accessors.
    int getSize() const
        { return arraySize; }
    
    T getElementAt(int sub) const;

    // Overloaded operator.
    T &operator[](int sub);

    // Other functions.
    void push_back(T value);
    void pop_back();
    void displayArray() const;
    // Destructor.
    ~SimpleVector();
};


/***
 * Function memoryError: The function displays an error
 * message and terminates the program when memory allocation
 * fails.
 */
template <class T>
void SimpleVector<T>::memoryError()
{
    cout << "Error: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

/***
 * Function subscriptError: The function displays an error
 * message and terminates the program when subscript is
 * out of range.
 */
template <class T>
void SimpleVector<T>::subscriptError()
{
    cout << "Error: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

/***
 * Function popbackError: The function displays an error
 * message and terminates the program when there is no
 * element in the array to pop back.
 */
template <class T>
void SimpleVector<T>::popbackError()
{
    cout << "Error: No element to pop back.\n";
    exit(EXIT_FAILURE);
}

/***
 * Constructor: The constructor accepts an argument about
 * the size of the array and then allocate an array with 
 * default values of zero.
 */
template <class T>
SimpleVector<T>::SimpleVector(int size)
{
    // Store 'size' int 'arraySize'.
    arraySize = size;

    // Allocate memory for the array.
    try
    {
        arrayPtr = new T[size];
    }
    catch(bad_alloc)
    {
        memoryError();
    }
    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
    {
        arrayPtr[count] = 0;
    }
}

/***
 * Copy constructor: The constructor is used when two objects
 * are used in an assignment statement.
 */
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &other)
{
    // Copy the array size.
    this->arraySize = other.arraySize;

    // Allocated memory for the array of 'this' object.
    this->arrayPtr = new T[this->arraySize];
    if (arrayPtr == nullptr)
        memoryError();
    
    // Copy the elements of 'other' array.
    for (int count = 0; count < arraySize; count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

/***
 * Function getElementAt: The function accepts an argument about
 * the subscript and returns the value stored at the subscript
 * in the array.
 */
template <class T>
T SimpleVector<T>::getElementAt(int sub) const
{
    // If the 'sub' is out of range, then call the
    // subscriptError function.
    if (sub > arraySize - 1 || sub < 0)
        subscriptError();
    // Otherwise, return the values.
    return arrayPtr[sub];
}

/***
 * Overloaded operator[]: The operator takes an argument.abort
 * The argument is a subscript. This function returns a reference 
 * to the element in the array indexed by the subscript.
 */
template <class T>
T &SimpleVector<T>::operator[](int sub)
{
    // If the 'sub' is out of range, the call the
    // subscriptError function.
    if (sub > arraySize - 1 || sub < 0)
        subscriptError();
    // Otherwise, return the values.
    return arrayPtr[sub];
}

/***
 * Function push_back: The function accepts an argument about
 * and then pushes it to the end of the array.
 */
template <class T>
void SimpleVector<T>::push_back(T value)
{
    // Increment the size of the array.
    int newArraySize = arraySize + 1;

    // Allocate a new array with the new size.
    T *newArray = new T[newArraySize];

    // Copy 'this' array to the new array.
    for (int count = 0; count < arraySize; count++)
        newArray[count] = this->arrayPtr[count];

    // Append the value to the new array.
    newArray[newArraySize - 1] = value;

    // Delete 'this' current array.
    delete [] this->arrayPtr;

    // Make 'this' object store the new array.
    this->arrayPtr = newArray;
    this->arraySize= newArraySize;
}

/***
 * Function pop_back: The function removes the last element
 * from the array.
 */
template <class T>
void SimpleVector<T>::pop_back()
{
    // If the current array has no element, then
    // call the function popbackError.
    if (this->arraySize == 0)
        popbackError();

    // The size of the new array.
    int newArraySize = this->arraySize - 1;

    // Allocate a new array with new array size.
    T *newArray = new T[newArraySize];

    // Copy the elements of 'this' array into
    // the new array except the last element.
    for (int count = 0; count < newArraySize; count++)
        newArray[count] = this->arrayPtr[count];

    // Delete 'this' current array.
    delete [] this->arrayPtr;

    // Make 'this' object hold data of the new array.
    this->arrayPtr = newArray;
    this->arraySize = newArraySize;
}

/***
 * Function displayArray: The function prints the values in
 * the array to the screen.
 */
template <class T>
void SimpleVector<T>::displayArray() const
{
    for (int count = 0; count < arraySize; count++)
        cout << arrayPtr[count] << " ";
}

 /***
 * Destructor: The destructor deletes dynamically allocated
 * memory in arrayPtr.
 */
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arrayPtr != nullptr)
        delete [] arrayPtr;
}


// A specialized template that works with string data type.
template <>
class SimpleVector<string>
{
protected:
    string *arrayPtr;             // To point to allocate memory.
    int arraySize;                // Number of elements in the array.
    void memoryError() const;     // Handles memory allocation errors.
    void subscriptError() const;  // Handles subscripts out of range.
    void popbackError() const;    // Handles no values to pop back.
public:
    // Default constructor.
    SimpleVector() 
        { arrayPtr = nullptr; arraySize = 0; }

    // Constructor.
    SimpleVector(int);

    // Copy constructor.
    SimpleVector(const SimpleVector &);

    // Accessors.
    int getSize() const
        { return arraySize; }
    
    string getElementAt(int) const;

    // Overloaded operator.
    string &operator[](int);

    // Other functions.
    void push_back(const string &);
    void pop_back();
    void displayArray() const;

    // Destructor.
    ~SimpleVector();
};

/***
 * Function memoryError: The function displays an error
 * message and terminates the program when memory allocation
 * fails.
 */
void SimpleVector<string>::memoryError() const
{
    cout << "Error: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

/***
 * Function subscriptError: The function displays an error
 * message and terminates the program when subscript is
 * out of range.
 */
void SimpleVector<string>::subscriptError() const
{
    cout << "Error: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

/***
 * Function popbackError: The function displays an error
 * message and terminates the program when there is no
 * element in the array to pop back.
 */
void SimpleVector<string>::popbackError() const
{
    cout << "Error: No element to pop back.\n";
    exit(EXIT_FAILURE);
}

/***
 * Constructor: The constructor accepts an argument about
 * the size of the array and then allocate an array with 
 * default values of zero.
 */
SimpleVector<string>::SimpleVector(int size)
{
    // Store 'size' int 'arraySize'.
    arraySize = size;

    // Allocate memory for the array.
    try
    {
        arrayPtr = new string[size];
    }
    catch(bad_alloc)
    {
        memoryError();
    }
    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
    {
        arrayPtr[count] = "";
    }
}

/***
 * Copy constructor: The constructor is used when two objects
 * are used in an assignment statement.
 */
SimpleVector<string>::SimpleVector(const SimpleVector &other)
{
    // Copy the array size.
    this->arraySize = other.arraySize;

    // Allocated memory for the array of 'this' object.
    this->arrayPtr = new string[this->arraySize];
    if (arrayPtr == nullptr)
        memoryError();
    
    // Copy the elements of 'other' array.
    for (int count = 0; count < arraySize; count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

/***
 * Function getElementAt: The function accepts an argument about
 * the subscript and returns the value stored at the subscript
 * in the array.
 */
string SimpleVector<string>::getElementAt(int sub) const
{
    // If the 'sub' is out of range, then call the
    // subscriptError function.
    if (sub > arraySize - 1 || sub < 0)
        subscriptError();
    // Otherwise, return the values.
    return arrayPtr[sub];
}

/***
 * Overloaded operator[]: The operator takes an argument.abort
 * The argument is a subscript. This function returns a reference 
 * to the element in the array indexed by the subscript.
 */
string &SimpleVector<string>::operator[](int sub)
{
    // If the 'sub' is out of range, the call the
    // subscriptError function.
    if (sub > arraySize - 1 || sub < 0)
        subscriptError();
    // Otherwise, return the values.
    return arrayPtr[sub];
}

/***
 * Function push_back: The function accepts an argument about
 * and then pushes it to the end of the array.
 */
void SimpleVector<string>::push_back(const string &value)
{
    // Increment the size of the array.
    int newArraySize = arraySize + 1;

    // Allocate a new array with the new size.
    string *newArray = new string[newArraySize];

    // Copy 'this' array to the new array.
    for (int count = 0; count < arraySize; count++)
        newArray[count] = this->arrayPtr[count];

    // Append the value to the new array.
    newArray[newArraySize - 1] = value;

    // Delete 'this' current array.
    delete [] this->arrayPtr;

    // Make 'this' object store the new array.
    this->arrayPtr = newArray;
    this->arraySize= newArraySize;
}

/***
 * Function pop_back: The function removes the last element
 * from the array.
 */
void SimpleVector<string>::pop_back()
{
    // If the current array has no element, then
    // call the function popbackError.
    if (this->arraySize == 0)
        popbackError();

    // The size of the new array.
    int newArraySize = this->arraySize - 1;

    // Allocate a new array with new array size.
    string *newArray = new string[newArraySize];

    // Copy the elements of 'this' array into
    // the new array except the last element.
    for (int count = 0; count < newArraySize; count++)
        newArray[count] = this->arrayPtr[count];

    // Delete 'this' current array.
    delete [] this->arrayPtr;

    // Make 'this' object hold data of the new array.
    this->arrayPtr = newArray;
    this->arraySize = newArraySize;
}

/***
 * Function displayArray: The function prints the values in
 * the array to the screen.
 */
void SimpleVector<string>::displayArray() const
{
    if (arraySize == 0)
        cout << "The array is empty.\n";
    else
    {
        for (int count = 0; count < arraySize; count++)
            cout << arrayPtr[count] << endl;
    }
}

 /***
 * Destructor: The destructor deletes dynamically allocated
 * memory in arrayPtr.
 */
SimpleVector<string>::~SimpleVector()
{
    if (arrayPtr != nullptr)
        delete [] arrayPtr;
}
#endif