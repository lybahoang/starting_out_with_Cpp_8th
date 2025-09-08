// Specification file for the Phone class.
#ifndef PHONE_H
#define PHONE_H
#include <string>
using namespace std;

class Phone
{
private:
    string brand;
    string color;
    string model;

public:
    // Default constructor.
    Phone();

    // Constructor.
    Phone(const string &, const string &, const string &);

    // Mutator functions.
    void setBrand(const string &);
    void setColor(const string &);
    void setModel(const string &);

    // Accessor functions.
    const string &getBrand() const;
    const string &getColor() const;
    const string &getModel() const;

    // Other functions.
    void displayInfo() const;
};
#endif