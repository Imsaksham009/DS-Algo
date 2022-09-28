#include<iostream>

using namespace std;


void fun(int& i){
	i++;
}





int main(){
	int i = 10;
	int j = 25;
	int& p = i;
	int& k = j;
	
	cout<<i<<endl;
	fun(p);
	cout<<i<<endl;
	cout<<p<<endl;



	

	return 0;
}
