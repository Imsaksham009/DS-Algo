#include <iostream>

using namespace std;


class Polynomial {
private:
    int* deg;


public:
    int size;
    //constructor
    Polynomial();

    //setting co-efficient function
    void setCoefficient(int, int);

    //operator + overload
    Polynomial operator*(const Polynomial&);


    //print
    void print() {
        for (int i{ 0 }; i < size; i++) {
            if (this->deg[i] != 0) {
                cout << deg[i] << "x" << i << " ";
            }
        }
    }

    // ~Polynomial(){
    //     delete [] deg;
    // }

};

//default constructor
Polynomial::Polynomial() {
    deg = new int[5];
    size = 5;
    for (int i{ 0 }; i < size; i++) {
        deg[i] = 0;
    }
    cout << endl;
}

//set co-efficient
void Polynomial::setCoefficient(int index, int n) {

    if (index >= size) {
        int* newdeg = new int[index + 1];
        //for setting 0

        for (int i{ 0 }; i < size; i++) {
            newdeg[i] = deg[i];
        }
        for (int i{ size }; i <= index; i++) {
            newdeg[i] = 0;
        }

        delete[] deg;
        deg = newdeg;
        size = index + 1;
    }

    deg[index] = n;
}

//operator +

Polynomial Polynomial::operator*(const Polynomial& p2) {
    Polynomial pnew;

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < p2.size; j++) {
            int deg1 = i + j;
            int mult = this->deg[i] * p2.deg[j];
            int co_efficient = pnew.deg[deg1] + mult;
            if (co_efficient != 0)
                pnew.setCoefficient(deg1, co_efficient);
        }
    }


    return pnew;
}



int main() {
    Polynomial p1;
    Polynomial p2;
    p1.setCoefficient(0, 2);
    p1.setCoefficient(1, 7);
    //p1.setCoefficient(2, 4);
    p2.setCoefficient(0, 1);
    p2.setCoefficient(1, 3);
    //p2.setCoefficient(2, 5);



    Polynomial p3;
    p3 = p1 * p2;

    p3.print();
    return 0;
}
