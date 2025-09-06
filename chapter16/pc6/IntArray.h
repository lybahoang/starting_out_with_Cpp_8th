#ifndef INT_ARRAY_H
#define INT_ARRAY_H

class IntArray
{
protected:
    int *arrPtr;                // Pointer to an array.
    int arraySize;              // Holds the array size.
    void subscriptError(int);   // Handles invalid subscripts.
public:
    // Exception class.
    class InvalidSubscript
    {
    private:
        int subscript;
    public:
        InvalidSubscript(int s)
            { subscript = s; }
        int getInvalidSubscript() const
            { return subscript; }
    };

    // Default constructor.
    IntArray()
        { arrPtr = nullptr; arraySize = 0; }
    
    // Constructor.
    IntArray(int);

    // Copy constructor.
    IntArray(const IntArray &);
    
    // Destructor.
    ~IntArray();

    // Accessor function.
    int getSize() const
        { return arraySize; }
    
    // Overloaded operator.
    int &operator[](const int &);
};
#endif