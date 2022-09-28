#include<iostream>


class Fraction{
    private:
        int numerator;
        int denominator;

    public:

        //default constructor
        Fraction(int,int);

        //copy constructor
        Fraction(const Fraction &source);

        //Sum
        void add(Fraction);

        //display

        void display();


};

