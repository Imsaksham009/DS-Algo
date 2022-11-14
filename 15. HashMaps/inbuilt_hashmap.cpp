#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


int main()
{
    unordered_map<string,int> myMap;
    myMap.insert(pair<string,int>("abc",10));

    myMap["abcded"] = 101;
    myMap["saksham"] = 7;

    // cout<<myMap["saksham"];

    if(myMap.count("abcde"))
        cout<<"Is Present";
    else cout<<"Not present";




}