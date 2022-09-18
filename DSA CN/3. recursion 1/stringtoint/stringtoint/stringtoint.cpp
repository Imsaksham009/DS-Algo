#include<iostream>
#include<math.h>

using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    int size = 0;
    for (int i = 0; input[i] != '0'; i++)
        size++;

    if (size == 0)
        return 0;

    int ans = stringToNumber(input + 1);

    int n = (int)input[0] - 48;

    return ans + n * (int)pow(10, size - 1);
}

int main() {
    char ch[] = { '1','2','3','\0'};

    int x = stringToNumber(ch);
    cout << x<<endl;
    return 0;
}