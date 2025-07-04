// Implementation file for the Phone class.
#include "Phone.h"
#include <iostream>
using namespace std;

/**
 * Default constructor: Assigns empty strings for all member variables.
 */
Phone::Phone()
{
    brand = "";
    color = "";
    model = "";
}

/**
 * Constructor: Accepts arguments about the phone's brand, color, and model assigns them
 * into the corresponding member variables.
 * @param phoneBrand: The brand of the phone.
 * @param phoneColor: The color of the phone.
 * @param phoneModel: The model of the phone.
 */
Phone::Phone(const string &phoneBrand, const string &phoneColor, const string &phoneModel)
{
    brand = phoneBrand;
    color = phoneColor;
    model = phoneModel;
}

/**
 * Function setBrand: Accepts an argument about the phone's brand and assigns it into
 * the 'brand' member variable.
 * @param newBrand: The brand of the phone.
 * @return: void.
 */
void Phone::setBrand(const string &newBrand)
{
    brand = newBrand;
}

/**
 * Function setColor: Accepts an argument about the phone's color and assigns it into
 * the 'color' member variable.
 * @param newColor: The color of the phone.
 * @return: void.
 */
void Phone::setColor(const string &newColor)
{
    color = newColor;
}

/**
 * Function setModel: Accepts an argument about the phone's model and assigns it into
 * the 'model' member variable.
 * @param newModel: The model of the phone.
 * @return: void.
 */
void Phone::setModel(const string &newModel)
{
    model = newModel;
}


/**
 * Function getBrand: Returns the phone's brand.
 */
const string &Phone::getBrand() const
{ return brand; }

/**
 * Function getColor: Returns the phone's color.
 */
const string &Phone::getColor() const
{ return color; }

/**
 * Function getModel: Returns the phone's model.
 */
const string &Phone::getModel() const
{ return model; }

/**
 * Function displayInfo: Displays all phone's information.
 */
void Phone::displayInfo() const
{
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Color: " << color;
}