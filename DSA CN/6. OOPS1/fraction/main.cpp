#include <iostream>
#include "fraction.cpp"
#include "fraction.h"

using namespace std;


int main(){

    Fraction f1(2,5);
    Fraction f2(5,2);

    f1.add(f2);

    f1.display();

    return 0;

}