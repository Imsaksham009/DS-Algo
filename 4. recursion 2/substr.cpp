#include <iostream>
#include <string>
#include<math.h>

using namespace std;

int subStr(string s,string* out){
    if(s.empty()){
        out[0] = "";
        return 1;
    }

    int size = subStr(s.substr(1),out);

    for(int i{0};i<size;i++){
        out[size + i] = s[0] + out[i];
    }
    return 2 * size;
}

int main(){
    string ip;
    cout<<"Enter the string: ";
    cin>>ip;
    int n = ip.size();
    int output_size = pow(2,n);
    string* out = new string[1000];
    int size = subStr(ip,out);
    for(int i{0};i<size;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    delete[] out;
    return 0;
}