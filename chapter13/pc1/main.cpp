#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    Date today(9, 5, 2005);

    today.displayFormat1();
    cout << endl;
    today.displayFormat2();
    cout << endl;
    today.displayFormat3();

    return 0;
}