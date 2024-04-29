// notes: 29 april 2024

//ch 9: more on classes
//we will talk abt static functions
	// static functions are good and important bc we can use them to access public members w/o summoning a handler
	// static vars can only be accessed by static functions
	// if you make a static function to, like, count instances of a class for example, then the var you're incrementing Must Also be static
		// it can be hard to debug errors which arise from non-matching static styles
	// you only NEED to put the keyword "static" into the header file
//more abt pointers, specifically the "this" pointer
//friend functions
	// omg "friend" is a keyword
	// a function is just a function, but it's not a Part of the class, so if you have one, you don't even need a class qualifier to access it
	// so why do we need friend functions? it just acts like a global function
	// the friend function can access things from inside the class! 
		// if we make it global, it can't access things from the class
	// think about it. most of the time you'll be making Big Projects. you're gonna wanna package a bunch of classes together, and they'll have to interact w/one another n stuff. 
		// smth. smth. this is related to subclasses and inheritance.
//pointers
//constructor overriding (we know this already. overloading n stuff)
//~destructor: explicit --> user's def of own destructor
	// if you use pointers in your class, MAKE SURE YOU MAKE A DESTRUCTOR
	// then, inside your class, DESTROY YOUR POINTER so that you don't leave it dangling
	// explicit destructors are like `~className`
	// the compiler WILL NOT clean out your dangling pointers.
//make a pointer inside a class, must destroy it Inside the class as well. normally we just delete pointers
//rule of 3, rule of 5: rule of 0



// Using the this pointer to refer to object members.
#include <iostream>
#include "Employee.h"
#include "Employee.cpp"
using namespace std;

int main() {
    Employee emp("jen","Chen"), emp2("Maria", "Gonzalez"), emp3("John", "Doe"); // instantiate and initialize testObject
    
    Employee* empTmp(&emp);
	Employee emp4(emp); //copy constructor, copy one object to the other
	//Employee[4] = {emp, emp2, emp3, emp4};

	// //you probably shouldn't do this. you'd have to be Extremely Careful
	// Employee* empTmp[4]; // this is an array of Pointers. each pointer can be ANYTHING w/in the "Employee"

    cout << "The number of object of the class Employee{}: " << 
        Employee::getCount() << endl;
        Employee::display();
        cout << getName();
        emp2.getPtr(empTmp);

        cout << "Last Name: " << emp3.getFirstName() << endl;

        emp.~Employee();
}



// //follow along 
// #include <iostream>
// #include <iomanip>
// #include <string>

// using namespace std;


// class Employee{
// public: 
// 	explicit Employee(int);
// 	Employee(const std::string&, const std::string&) {}; //constructor
// 	Employee* empPtr{ nullptr }; //the pointer
// 	~Employee() { //and the destructor
// 		delete empPtr;
// 	};
// 	void print() const;
// private: 
// 	int x{0};
// };

// //constructor

// Employee::Employee(int value) : x{value} {} //init x to value

// //print x using implicit then explicit this pointers;
// //the parentheses around *this are required
// void Employee::print() const {
// 	//implicitly use this pointer  to access the member x
// }

// int main() {
// 	Employee emp("Jen", "Chen"), emp2("Maria", "Gonzalez");
// 	Employee* empTmp(&emp2); //remember that pointers point to addresses
// 	//emp2.getPtr(empTmp);
// 	return 0;
// }