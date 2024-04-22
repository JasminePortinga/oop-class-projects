// LESSON: POINTERS
// *** be EXTREMELY CAREFUL w/these bc you can break your laptop, slowing it down Irrepairablyyyyyy ***

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;


void updatePtr(int*, int);
const size_t varSize = 5;
//the point of functions n classes: REUSABILITY & info-hiding
// if you're missing reusability from the final, then immediate 0

int main() {
	/* POINTERS point to ADDRESSES */
	// if you pass the pointer along, then you have to put the * in the front, or else you'll print out the address
	//cout << ptrNum << endl; // prints out the address
	//cout << *ptrNum << endl; //prints out the value

	//pointers are how we get to make built-in and dynamic arrays

	// everything we learn from this point on will be kind of abstract

	//int var{0};
	const int arr1[5]{3,4,5,6,7};
	//static array<int, varSize>var {3, 4, 5, 6, 7};
	int arr2[varSize]{8,9,10,11,12};
	//int *pointVar{0};
	// a constant integer must have a constant pointer
	// const int* pointVar; //the star points to the address
	// pointVar = var; //store address of var

	//converting arrays into opinters: see ex on canvas for apr 22
	array <int, 5> arr3{ 11, 13, 15, 17, 19};
	array <int, 5> arr4{12, 14, 16, 18, 20};

	vector<int> arrV1{1,2,3,4,5};
	vector<int> arrV2{6,7,8,9,10};

	const int* ptrA1{arr1}, * ptrA2{arr2};
	vector<int>* ptrV1{&arrV1}, * ptrV2{&arrV2};

	//when you swap arrays n pointers, um. be careful lest you overwrite smth you wanted.

	const int* pointVar{nullptr}; //nullptr is different from null. this points to a Pointer which points to null, which should keep you Safe
	// pointVar = var;
	// int* pointVar2{var2}; //init pointVar2 to var2[]. arrays are already addresses, so you don't need &

	int num1{1};
	int* pointVar3{&num1}; //need the ampersand, or else you're getting the address, the the value

	unsigned int arrLen;
	cout << "Enter the length of the new Dynamic Array (which pointVar3 should be pointing to): ";
	cin >> arrLen;

	//the new will be made during the RUNtime, rather than the COMPILING time. the program reserves some memory in the hard drive for whatever is made during the compile time, so the "new" will save you a Lot of Space in the program .exe itself. this spares you Overhead
	//we won't really understand Overhead(tm) until we work on a whole project and you have to Optimize your thing
	pointVar3 = new int[arrLen]; //create a dynamic array. notice the keyword "new". "new" is dangerous, which is good! that means it's powerful
	//pointVar3 = new array<int, arrLen>;
	//int Var3 = new int[arrLen]; //this is illegal. built-in arrays can NEVER be a dynamic array

	int countLen{0}; //count number of els in the pointer *pointVar3
	//init the pointer to pointVar3
	cout << "Initialize the point *pointVar3:\n"; 
	for (int j{0}; j < arrLen; j++) {
		pointVar3[j] = j+5;
		cout << setw(5) << pointVar3[j];
		countLen++;
	}
	

	cout << "*pointVar = " << *pointVar << endl << endl; //print the content of a pointer, add the * in front of it

	// you can't do this bc pointers can't point to values. they point to addresses
	//cout << "Changing value of *pointVar to 16: " << endl;
	//*pointVar = 16;
	pointVar = pointVar3; //you can do this tho, point pointers to other pointers

	//cout << "var = " << &var << endl;
	//cout << "address of array var = " << var << endl;
	cout << "el of *pointVar = " << *pointVar << endl;
	cout << "el + 2 in array var (\"*(pointVar+2)\"): " << *(pointVar+2) << endl;

	cout << "Update the values of the pointer *pointVar3:\n";
	//updatePtr(pointVar3, arrLen);
	//unsigned int arrLen{10}; //when i get to see the array then i'll change this

	for (int i{0}; i < arrLen; i++) {
		cout << "*(pointVar3 + " << i << ") = " << *(pointVar3 +i) << endl; //the parentheses is to help you print out the new value for printing
	}

	//unfortunately, according to the prof, the web doesn't have Any good info abt c++ pointers. deeply wretched and unfortunate

	//this is old-school; you Technically don't have to do this anymore. do it just to make sure. if you don't, then you'll end up w/holes in your hard drive.
	//like. how often do you optimize your hard drive, defragment it. omg i remember nerds in 8th grade teaching me abt this
	//with huge databases, with huge data storage needs, You Will Need to defrag your hard drive, bc all your data is stored in a billion different tiny little places
	pointVar = nullptr; //set each pointer to NULL before you delete it
	//pointVar2 = nullptr; 
	pointVar3 = nullptr;
	// do NOT leave any pointers dangling
	delete pointVar; //these things are Incredibly Hard To Manage. if you don't point them to null, then you delete smth in the hard memory; if you don't delete the pointer before exiting the program, function, or class, then you will make your own computer unusably slow bc now you just have these pointers Floating Around w/no idea how to remove them
	//delete pointVar2;
	delete pointVar3;

	return 0;
}

// useful in games, according to the prof, where you update scores w/pointers over runtime. you could also use db for that sort of thing, for permanent storage
//notice how you didn't have to pass any arrays!! just passed along a pointer
void updatePtr(int* ptr, int len) {
	cout << len << endl;
	for (int i{0}; i < len; i++) {
		*(ptr + i) = 20 * (*(ptr+i)); //multiply everything in the pointer by 3
	}
}

void swap(int array1[], int num, int array2[], int num2) {
	int hold;
	int arrTmp1[sizeof(array1)/sizeof(array1[0])], arrTmp2[sizeof(array2)/sizeof(array2[0])];
	for (int i{0}; i <=4; i++) {
		hold = array1[i];
		array1[i] = array2[i];
		array2[i] = hold;

		cout << "\t array1[" << i << "] = " << array2[i]; //etc
	}
}

//doing "this ->" and pointing to a function lets you cascade a function
//cascading functions lets you do stuff like "this.function()"
//requires you to do return *this;

// remember that all web coding is done via SCRIPTS.
// APPS on like your PHONE are COMPILED.