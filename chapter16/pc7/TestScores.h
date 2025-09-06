#ifndef TEST_SCORES_H
#define TEST_SCORES_H

class TestScores
{
protected:
    double *scoreArray;         // Pointer to an array of scores.
    int arraySize;              // The size of the array.
    void subscriptError(int);   // Handles invalid subscript.
    void scoreError(double);    // Handles invalid score values.
public:
    // Exception classes.
    class InvalidScore
    {
    private:
        double score;
    public:
        InvalidScore(double s)
            { score = s; }
        double getInvalidScore() const
            { return score; }
    };

    class InvalidSubscript
    {
    private:
        int subscript;
    public:
        InvalidSubscript(int sub)
            { subscript = sub; }
        int getInvalidSubscript() const
            { return subscript; }
    };

    // Default constructor.
    TestScores()
        { scoreArray = nullptr; arraySize = 0; }
    
    // Constructor.
    TestScores(double *inputArray, int size);

    // Copy constructor.
    TestScores(const TestScores &other);

    // Overloaded operator.
    double &operator[](int subscript);

    // Other functions.
    double getAverageScore() const;

    // Destructor.
    ~TestScores();
};
#endif