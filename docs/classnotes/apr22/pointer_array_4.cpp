//File name: array_pointer_4.cpp wit modification

#include <iostream>
#include <array>
#include <algorithm>
#include <iomanip>
using namespace std;

void updatePtr(int*, int);
const size_t varSize = 5;

int main() {
    const int var[varSize]{ 3,4,5,6,7 };
    int var2[varSize]{ 8,9,10,11,12 };

    //    const array<int, 5> var{ 1, 2, 3, 4, 5 };
    const int* pointVar{ nullptr };   //Safe mode
    pointVar = var;    // store address of var
    
    int* pointVar2{ var2 };   //INitialize the pointVar2 to var2[].
    int* pointVar3{ nullptr }; //Initialize this pointer to NULL

    int arrLen;
    cout << "Enter the length of the new dynamic array (which the pointer *pointVar3 points to): ";
    cin >> arrLen;

    pointVar3 = new int[arrLen];    //Create a dynamic array. word "new"

    int countLen{ 0 };                //count the number of elements in the pointer *pointVar3.

    //Initialize the pointer *pointVar3.
    cout <<  "InitiaLize the pointer *pointVar3: ";
    for (int j{ 0 }; j < arrLen; j++) {
        pointVar3[j] = 2*j;    
        cout << setw(5) << pointVar3[j];
        countLen++;
    }

    cout << endl << "countLen = " << countLen << endl << endl;

    cout << "Now, we output the contents of the array var[]: \n";
    for (unsigned int i{ 0 }; i < varSize; i++) {   //Note that the size of the array var[] is 5.
        cout << "var = " << var[i] << endl;
    }

    cout << "Now, we output the contents of the pointer *pointVar using *(pointVar + i): \n";
    for (int i{ 0 }; i < varSize; i++) {
        cout << "*(pointVar2 + " << i << ") = " << *(pointVar2 + i) << endl;
    }

    //    cout << "Changing value of var to 7:" << endl;
    //        var = 7;

    cout << "Output the address of the array var[]: " <<    var << endl;

    cout << "*(pointVar + 2)= " << *(pointVar + 2) << endl << endl; //To print the content of a pointer, add the * before its name.
    cout << " pointVar[2]= " << pointVar[2] << endl << endl; //To print the content of a pointer, add the * before its name.

    //cout << "Changing value of *pointVar to 16:" << endl;
    // 
    //reset the values of the pointer *pointVar to *pointVar3.
    pointVar = pointVar3;

    cout << "var = " << var << endl;
    cout << "*pointVar = " << *pointVar << endl;

    cout << "Update the values of the pointer *pointVar3:\n";
    updatePtr(pointVar3, arrLen);

    for (int i{ 0 }; i < arrLen; i++) {
        cout << "*(pointVar3 + " << i << ") = " << *(pointVar3 + i) << endl;
    }

    pointVar = nullptr;        //Set each pointer to NULL before delete it.
    pointVar2 = nullptr;
    pointVar3 = nullptr;
    delete pointVar;
    delete pointVar2;
    delete pointVar3;

    return 0;
}

void updatePtr(int* ptr, int len) {
    cout << len << endl;
    for (int i{ 0 }; i < len; i++) {
        *(ptr + i) = 20 * (*(ptr + i));
    }
}