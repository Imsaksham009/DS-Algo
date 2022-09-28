#include<bits/stdc++.h>

using namespace std;

class Dynamic{
    private:
        int *arr;
        int index;
        int size;

        
    public:

        //Constructor
        Dynamic();

        //for adding elements
        void add(int);

        //copy constructor
        Dynamic(const Dynamic &);


        //printing array
        void print();

        //destructor
        ~Dynamic(){
            cout<<"destructor called"<<endl;
            delete [] arr;
        }

        
};

Dynamic::Dynamic()
    :arr{new int [5]},index{0},size{5}{

    }

Dynamic::Dynamic(const Dynamic &source){
    this->arr = new int [source.size];
    for(int i{0};i<source.index;i++)
        this->arr[i] = source.arr[i];
    this->size = source.size;
    this->index = source.index;   
}    

void Dynamic::add(int n){

    if(index == size){
        int *newArr = new int[2 * size];
        for(int i{0};i<size;i++){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
        size*=2;
    }
    arr[index] = n;
    index++;
}    

void Dynamic::print(){
    for(int i{0};i<index;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main(){
    Dynamic d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(10);
    d1.add(50);
    d1.add(70);
    d1.add(80);
    d1.print();
    Dynamic d2(d1);
    d2.add(90);
    d2.add(100);
    d2.add(190);
    d2.add(290);
    d2.add(390);
    d2.print();
    return 0;
}