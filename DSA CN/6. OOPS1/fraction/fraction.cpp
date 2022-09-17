#include <iostream>
#include "fraction1.cpp"

using namespace std;

//default constructor
Fraction::Fraction(int numerator = 0,int denominator = 0)
         :denominator{denominator},numerator{numerator}{
}

//copy constuctor

Fraction::Fraction(const Fraction &source){
    this->numerator=source.numerator;
    this->denominator=source.denominator;
}

//sum
void Fraction::add(Fraction f2){
    int lcm = this->denominator * f2.denominator;
    int sum = ((lcm/(this->denominator)) * this->numerator)+((lcm/(f2.denominator)) * f2.numerator);
    this->numerator = sum;
    this->denominator = lcm;
}

//display

void Fraction::display(){
    cout<<this->numerator<<"/"<<this->denominator<<endl;
    
}

int main(){

    Fraction f1(2,3);
    Fraction f2(5,2);

    f1.add(f2);

    f1.display();

    return 0;

}