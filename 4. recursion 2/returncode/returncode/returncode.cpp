#include <iostream>
#include <string.h>
using namespace std;

int codes(string input, string output[10000], string out) {

    if (input.empty()) {
        output[0] = out;
        return 1;
    }


    int number = (int)input[0];
    char letter = number + 48;
    int x = codes(input.substr(1), output, out + letter);

    for (int i{ 0 }; i < x; i++) {
        output[i + 1] = output[i];
    }


    int y = 0;

    if (input.size() >= 2)
    {
        int num1 = (int)input[0] - 48;
        int num2 = (int)input[1] - 48;
        int num3 = (num1 * 10) + num2;
        if (num3 <= 26 && num3 > 9)
        {
            char letter = num3 + 96;
            y = codes(input.substr(2), output, out + letter);
        }
    }
    return x + y;
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃ¢ÂÂt print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    string out;
    return codes(input, output, out);
}


int main() {
    string input;
    cin >> input;

    string* output= new string[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;

    delete[] output;
    return 0;
}

