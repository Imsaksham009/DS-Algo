#include <iostream>
#include <string>
using namespace std;

#include <unordered_map>
using namespace std;
string uniqueChar(string str) {
	// Write your code here
	unordered_map<char,int> keeper;

	for(int i{0};i<str.size();i++)
	{
		keeper[str[i]]++;
	}
	string out;

	for(int i{0};i<str.size();i++)
	{
		if(keeper[str[i]] > 0)
		{
			out = out + str[i];
			keeper[str[i]] = 0;
		}
	}

	return out;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}