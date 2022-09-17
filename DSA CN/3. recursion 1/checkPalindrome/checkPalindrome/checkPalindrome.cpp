#include <iostream>

using namespace std;


bool check(char s[], int start, int end) {
    if (start >= end)
        return true;
    if (s[start] == s[end]) {
        start++;
        end--;
        return check(s, start, end);
    }
    else
    return false;
}



bool checkPalindrome(char input[]) {
    // Write your code here
    int size = 0;
    for (int i = 0; input[i] != '\0'; i++)
        size++;

    int s = 0;
    int e = size - 1;

    return check(input, s, e);
}

int main() {
    char input[10];
    cin >> input;

    if (checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}




