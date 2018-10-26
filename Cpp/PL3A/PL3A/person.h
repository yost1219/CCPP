/*
A simple and complete C++ program to demonstrate friend Class
<iostream>
class A {
private:
int a;
public:
A() { a = 0; }
friend class B;     // Friend Class
};

class B {
private:
int b;
public:
void showA(A& x) {
// Since B is friend of A, it can access
// private members of A
std::cout << "A::a=" << x.a;
}
};

int main() {
A a;
B b;
b.showA(a);
return 0;
}

Output:

A::a = 0
*/


class Person //design a class "person"
{
private: //that has private data members for first name, last name, age, and gender
	std::string first_name;
	std::string last_name;
	int age;
	std::string gender;

public: //implement public functions to get and set values of these private data members
		//(example: std::string getFname(), void setName(std::string fName), as well as your constructor(s) and destructor.
	Person(std::string fName, std::string lName, int a, std::string g) //constructor
	{
		first_name = fName;
		last_name = lName;
		age = a;
		gender = g;
	}
	//~Person() //destructor
	//{
	//}
	void get_fName(std::string fName) //constructor
	{
		first_name = fName;
	}
	void get_lName(std::string lName) //constructor
	{
		last_name = lName;
	}
	void get_age(int a) //constructor
	{
		age = a;
	}
	void get_gender(std::string g)
	{
		gender = g;
	}
	std::string fName()
	{
		return first_name;
	}
	std::string lName()
	{
		return last_name;
	}
	int a()
	{
		return age;
	}
	std::string g()
	{
		return gender;
	}
};











