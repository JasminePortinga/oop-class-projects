// today we are going to do two things: 
	// inheritance and i/o
	// next week: polymorphism

// btw this wednesday's project is individual. thank god

// inheritance 
/// ex: class called "shape" as our base class
	// inheritance means we have sub-classes, and we can have subclasses that inherit from more than one class or other subclasses.
	// anyway, ex child class of "geometry (2d)", and child class "geometry (3d)"
	// ex child class of 2d geo of "circle" and "rectangle / parallelogram"
	// ex child class of 3d geo "cylinder/box/cube", "prism", etc.
// so it's, like. we inherit everything (biologically) from your parents. financially who knows, but biologically, we inherit everything from our parents. the same goes for classes
	// base classes do not inherit anything from their child classes. this is a one-way specialization street.
	// it's Just Like CSS! 
		// ...if you do them right and actually cascade your rules, that is.
// anyway here we have these things called "virtual functions": there are two types of them, btw
	// normal virtual functions, and Pure Virtual Function (they're an abstract class)
	// why do we need abstract classes? to make our parent classes!
	// like. what shape is parent class "shape"? who knows!!!!!!! 
	// anyway, virtual functions are important for letting the children overwrite the parent functions
		// serve as functions s/t child class function can overwrite the base class f'n
		// the difference is in the contents
	// for example, in Shape, we have a property called "area". in 2d, a = l*w; but in 3d, w = l*w*h and SA = sum of all surface ares
// so anyway base class shape has functions area(foot, foot); area(foot, foot, foot);
	// virtual function volume(l, w, h); all floats. this goes in the base class
		// key word: virtual, so that we can overwrite things
	// in 3d geo, volume(l,w,h) { return l* w * h; }; (but only for certain types of shapes lol)
		// you don't say "virtual" in the 3d geo version
	// if you don't overwrite your functions, then the compiler isn't gonna know which version of the function to use. this is bad, bc it defaults to the virtual function
		// if you just keep writing similar functions for things, then you increase the cost of things, and it'll take time to fetch things
// pure virtual functions = 0;
	// if you don't do that, then you're not making an abstract class. it defeats the purpose
// in real life, you'll have like 10, 15 levels deep of subsclasses. but we are starting small

// downcasting & upcasting
// downcasting is smth you need a good reason to do
	// it's when the parent class inherits smth from the child class
	// you need a good reason for this, bc it's weird. 
// upcasting is when you make your child class into a parent class in itself
// for example, if we protect smth in the parent class (rather than declare it private)
	// child classes can access everything BUT the constructors n destructors. that's like grabbing the organs out of our parents' bodies.
	// ...is steven playing magic the gathering?????
	// anyway, child classes can't access private members of a base class either. 
		// UNLESS these are members are declared 'protected'
	// private things: id numbers. 
	// see, this is why set() and get() are so important: so that children can have access
		// so then. why have protected classes? bc hackers can take advantage of this
	// so, you shouldn't have any protected 
// always remember the fact that calling functions has A Cost.

// prof: do any of you guys remember. netscape. i remember netscape. ahhhh those were the good old days.

// it matters not how LONG it takes for you to code a class. what matter is how often you REUSE it
// in a constructor, a colon stands for "inheritance"
/*
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& first, const string& last, const string& ssn, double sales, double rate, double salary
)   : CommissionEmployee(first, last, ssn, sales, rate) { // explicitly call base class constructor
	setBaseSalary(salary);
}
*/

// "cerror" is when you have the little popup error that tells you what the error is
// these get thrown
// ostringstream output; 
// strings can't have more than 255 chars, so if you need more than that. then you'll need a ostringstream. or a blob, but blobs are for ginormous things
// anyway, use ostringstream for longer strings


#include <iostream>
#include <iomanip>
// #include "filesystem.h"
// #include "fileapi.h"
#include <fstream>
// #include <iterator>
// #include <regex>
#include <string>
// #include "boost.filesystem"
// #include <experimental/filesystem>

using namespace std;

int main() {
	

	return 0;
}