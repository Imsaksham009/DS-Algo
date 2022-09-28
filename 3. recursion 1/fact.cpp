#include<iostream>

using namespace std;

int fact(int n){
	if(n == 1)
		return 1; 

	cout<<n<<endl;
	return n * fact(n-1);

}


int main()
{
	int n = 5;
	int answer = fact(n);
	cout<<answer<<endl;
	return 0;
}

