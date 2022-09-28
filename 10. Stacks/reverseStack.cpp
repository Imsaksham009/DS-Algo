#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.empty())
        return;
    int temp = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        int a = input.top();
        extra.push(a);
        input.pop();
    }
    input.push(temp);
    while(!extra.empty()){
        int b = extra.top();
    	input.push(b);
        extra.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}