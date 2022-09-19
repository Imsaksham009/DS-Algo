#include<bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
    int count = 0;
    int size = expression.size();
    for(int i{0};i<size;i++)
    {
       if(expression[i]!=')')
            s.push(expression[i]);
        else   
        {
 			while(s.top()!='(')
            {
                s.pop();
                count++;
            }
            s.pop();
            if(count == 0 || count == 1)
                return true;
        }
        count = 0;
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false")<<endl;
}