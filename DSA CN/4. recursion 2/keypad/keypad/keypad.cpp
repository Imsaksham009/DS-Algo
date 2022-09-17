#include<iostream>
using namespace std;


int keypad(int num, string* out) {
	if (num == 0) {
		out[0] = "";
		return 1;
	}

    string mapping[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    int size = keypad(num / 10, out);
    int n = num % 10;

    for (int i{ 0 }; i < mapping[n].size()-1; i++) {
        out[size + i] = out[i];
    }

	for (int i{ 0 }; i < 3; i++) {
		for (int j{ 0 }; j < 2*size; j = j+3) {
			out[i+j] =  
		}
	}

    return 3 * size;
}


int main() {
	int num;
	cin >> num;

	string* out = new string[10000];
	int count = keypad(num, out);

	for (int i{ 0 }; i < count; i++)
		cout << out[i] << endl;

	delete[] out;
	return 0;
}