
//Example: pointer_array_5.cpp with modification.

//    File name: pointer_array_5.cpp
//    Swapping elements of arrays using arrays and pointers.

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>

using namespace std;

const int maxsize = 20;

//int input(int[], int[]);
void output();
void footer();
void swapPtr(int* ptr1, int* ptr2);
void swap(int[], int, int[], int);
//void swap(array<int, 5> array1, array <int, 5> array2);

int main()
{
    int arr1[5] = { 1,3,5,7,9 };
    int arr2[5] = { 2,4,6,8,10 };

    array <int, 5> arr3{ 11,13,15,17,19 };
    array <int, 5> arr4{ 12,14,16,18,20 };

    array<int, 5>* arrPrt3{ &arr3 }, * arrPrt4{ &arr4 };

    vector<int> arrV1{ 1,2,3,4,5 };
    vector<int> arrV2{ 6,7,8,9,10 };

    int* ptrA1{ arr1 }, * ptrA2{ arr2 };
    vector<int>* ptrV1{ &arrV1 }, * ptrV2{ &arrV2 };

    output();
    swap(arr1, 5, arr2, 5);    //function with arrays as parameters.
    //swapPtr(ptrA1, ptrA2);        //function wit pointers as parameters
    footer();

    cout << "The original values of the array arr1{}: " << arr1[0] << "\t" <<
                arr1[1] << "\t" << arr1[2] << endl;

    return 0;
}


void output()
{
    cout << "This is a program to swap values of 2 arrays .\n";
    cout << "The value of array A and array B are swapped as follow:\n\n";
    cout << "\t Before swapped: " << "\t\t\t After swapped:\n";
}

//Swap 2 arrays using arrays
void swap(int array1[], const int num, int array2[], const int num2)
//void swap(array<int, 5> array1, array <int, 5> array2)
{
    int hold, i;
    //int arrTmp1[sizeof(array1) / sizeof(array1[0])];
    //int arrTmp2[sizeof(array2) / sizeof(array2[0])];
    
    //for (int i{ 0 }; i < (sizeof(array1) / sizeof(array1[0])); i++) {
    //    arrTmp1[i] = array1[i];
    //    arrTmp2[i] = array2[i];
    //}

    for (i = 0; i <= 4; i++)
    {
        hold = array1[i];
        array1[i] = array2[i];
        array2[i] = hold;

        cout << "   array1[" << i << "] = " << array2[i] << "\t array2[" << i << "] = " << array1[i]
            << "\t\t" << "array1[" << i << "] = " << array1[i]
            << "\t array2[" << i << "] = " << array2[i] << endl;
    }
}

//Swap 2 arrays using pointers
void swapPtr(int* ptr1, int* ptr2)
//void swap(array<int, 5> array1, array <int, 5> array2)
{
    int hold, i;

    for (i = 0; i <= 4; i++)
    {
        hold = ptr1[i];
        ptr1[i] = ptr2[i];
        ptr2[i] = hold;

        cout << "   array1[" << i << "] = " << ptr2[i] << "\t array2[" << i << "] = " << ptr1[i]
            << "\t\t" << "array1[" << i << "] = " << ptr1[i]
            << "\t array2[" << i << "] = " << ptr2[i] << endl;
    }
}

void footer()
{
    cout << endl;
    setw(60);
    cout << "\t************************************************************\n";
    cout << "\t*";
    setw(60);
    cout.width(60);
    cout << "*\n";
    cout.width(23);
    cout << "\t*\t\t\tEND OF PRESENTATION";
    cout.width(18);
    cout << "*\n";
    cout << "\t*";
    setw(60);
    cout.width(60);
    cout << "*\n";
    setw(60);
    cout << "\t************************************************************\n";

}