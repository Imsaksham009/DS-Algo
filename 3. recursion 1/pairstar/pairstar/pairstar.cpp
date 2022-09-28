#include <iostream>

using namespace std;

void pairStar(char input[]) {
    // Write your code here
    int size = 0;
    for (int i = 0; input[i] != '\0'; i++)
        size++;

    if (size == 0)
        return;


    pairStar(input + 1);


    if (input[0] == input[1])
    {
        for (int i = size; i > 0; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
        size++;
    }

}

int main()
{
    char ch[50];
    cin >> ch;
    pairStar(ch);
    cout << ch;

}
