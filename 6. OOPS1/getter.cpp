#include<iostream>
#include<string>

using namespace std;

class Student{
	private:
		string name;
		int age;
		int rollNo;

	public:
		void get_details();

		//default constructor
		Student();

		// oveloaded constructor
		Student(string,int,int);	

		//copy constructor
		Student(const Student &);

};

//getters
void Student::get_details(){
	cout<<this->name<<endl;
	cout<<this->age<<endl;
	cout<<this->rollNo<<endl;
}




//default constructor
Student::Student(){
	this->name = "";
	this->age = 0;
}


//overloaded constructor
Student::Student(string name,int age,int rollNo){
	this->name = name;
	this->age = age;
	this->rollNo = rollNo;
}

//copy constructor

Student::Student(const Student &obj){
	this->name = obj.name;
	this->rollNo = obj.rollNo;
	this->age = obj.age;

}

int main()
{

	Student s1;
	Student s2("Saksham",21,23553);
	Student s3(s2);
	s3.get_details();
	return 0;
}

