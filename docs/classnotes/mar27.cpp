//initializing multidimensional arrays
#include <iostream>
#include <array>
#include <algorithm> //need for sorting (NOT old arrays)
#include <iomanip> //setw
#include <string> //to avoid an error
#include <ctime> //for random numbers

using namespace std;

const size_t rows{11};
const size_t columns{7};

void printArray(array<array<double, columns>, rows>&);
double salesP1(array<array<double, columns>, rows>&);
double salesP2(array<array<double, columns>, rows>&);
double spSal1(double sal);
string spTitle1(string title);
int genRand(int fl, int ceil);

int main() {
	//this is how we seed a random number. the s in srand stands for seed. 
	srand(time(NULL)); //this will produce a double number
	double d;

	cout << rand()%49+1 << endl << endl; //this will return a random number, but you don't get to restrict its bounds unless you use modulo -- in this case anything less than 50. because we don't want 0, then we modulo 49 and add 1

	array<array<int, 3>, 2> arr1{
		15, 1, 23, //try to display your values in the correct columns and rows, rather than in a list form
		46, 89, 12
	}; //mult dim arr w/3c2r
	//in js it'd look smth like:
	/*
		arr1 = [[15, 1, 23], [46, 89, 12]];
	*/

	int arr2[2][3] = {
		7, 8,
		9, 10,
		11, 12
	};

	//dynamic arrays are only generated during runtime (important so that you can destroy them later), whereas static arrays will waste a bit of space
	//prof was a gamer back in the day, ignoring his grades to play games. but the only game he had available to him. was tetris. but he DID beat everyone else in the math department in tetris.
	//"how many hours do you spend a day playing games?" um. //sweats

	//arrays are useful bc they hold similar data types together. this is like their main Thing
	array <int, 5> arr3{32, 21, 2, 1, 5};
	//int arr3[5] = {32, 31, 2, 1, 5}; //old way. but now you have to write your own short functions

	int n = sizeof(arr3) /* will return 20 bc it returns the number of bytes */ / sizeof(arr3[0]) /* therefore you must divide it by the byte-size of the first item */; 
	//int n2 = sizeof(arr1[0]) / sizeof(arr1[0][0]);
	int n2 = sizeof(arr1[0][0]);

	/* looping through 1d arrs */
	double ttl_1{0.0};

	cout << "Contents of the array arr3[] using loop by index: " << endl;
	for (int p{0}; p < size(arr3); p++) {
		cout << arr3[p] << "\t";
		ttl_1 += arr3[p]; //sum up to ttl_1
	};

	cout << "\nSum of arr3[]: " << ttl_1 << endl;
	cout << "Average of arr3[]: " << ttl_1/arr3.size() << "\n\n\n";

	double ttl_2{0.0};
	cout << "Contents of the array arr3[] using the loop by item in the array arr3: " << endl;
	//the processing time btwn this and the prev loop style is the same
	for (int& /* remember to use the ampersand so that you pass it by reference. apparently in the past, it wouldn't work, but they patched that out! */ item : arr3) {
		cout << item << "\t";
		ttl_2 += item; //sum up to ttl_2
	}

	//sort by ascending
	sort(arr3.begin(), arr3.end()); 
	//sort by descending is just add an extra param
	sort(arr3.begin(), arr3.end(), greater<int>());
	//this is useful for, say, finding the max n min values of smth, but this will alter the array itself, which you don't always want. there's allegedly functions for this, but the prof can't find them right now. truly unfortunate that stackexchange doesn't exist i guess. it's probably under <algorithm>

	cout << "Size of the array arr1 (sizeof(arr1)): " << n << endl; //multi-dimensional arrays have fixed sizes, whereas multi-dimensional vectors can have varied sizes
	cout << "Size of each el in the arr1[] (sizeof(arr1[0][0])): " << n2 << endl;
	cout << "Then the number of els in the array arr1 is (sizeof(arr1)/sizeof(arr1[0][0])): " << n/n2 << endl;

	/* looping through 2d arr */
	cout << "\nContents of the multi-dimensional array arr1[][]: \n";
	//the indexes version is good for choosing points in the array
	for (int i{0}; i < arr1.size(); i++) { //i are the rows
		for (int j{0}; j < arr1[i].size(); j++) { //j are the cols
			cout << arr1[i][j] << "\t";//<< ((j < arr1[i].size()-1) ? "\t" : "\n");
		}
		cout << "\n";
	}

	//printArray(arr1);

	//to add an element to a VECTOR, they get appended to the obj. pretend it's a stack (a type of data structure), so you're adding things to the top, pushing all the others down. hence: push_back() is used to add els to a vector. to remove an el, it's pop_back()
	//you can only push and pop one at a time. you can also insert() to inject smth at any index point n it'll automatically push everything else back


	array<array<double, 9>, 2>; //these usually come from files
	string emp1[9]{
		"Sales Person 1", "Sales Person 2", "WH Manager", "WH ASsistant Manager", "WH Worker 1", "Accountant", "Manager"
	};

	return 0;
}


int genRan(int fl, int ceil) {
	return rand()%ceil + (fl+1);
}

void printArray(array<array<double, columns>, rows>& a) {
	for (auto const& row : a) {
		for (auto const& el : row) {
			cout << setw(15) << el;
		}
		cout << endl;
	}
}