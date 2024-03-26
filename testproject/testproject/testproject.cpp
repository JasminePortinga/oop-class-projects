// Notes 25 march 2024
// ARRAYS!!! FINALLY!!!! I CAN CODE IN PEACE!!!!!
// 1. arrays are contiguous lists of elements. whatever contiguous means here. that's a key word apparently
// ex: array <int, 5> arr1 {0, 1, 2, 3, 4} (array: type integer, size 5)
// we have new ways of making arrays using ~templates~
// array templates are called STL: Standard Template Library
// we love templates. c++ was hideous without it.
// anyway. we know how this works. arr[0] gets the first element, arr[1] gets the second, blahblahblah. just like in js
// so far no ide will check the outer bounds of an array, so if we try to do something outside of the bounds of an array, we'll end up w/a RUNTIME error, array_out_of_bound, meaning more elements than the array size. [static] arrays have FIXED SIZES
// array size must be > 0
// some of the groups did not check for errors. the blame falls on the group leader when the prof tries to initialize everything to 0 and he gets an error bc the leader's job is to check for errors.
// anyway, you can use size_t, which means an unsigned integer. they didn't have size_t 30, 40 years ago omg the files sync across ides
// be CAREFUL when you're sorting arrays bc you will rearrange the Entire Array Object. good practice is to duplicate the array and then sort the dupe
// i do think it's funny that i'm the sort of person who usually takes notes by hand writing notes on my computer rn
// this is also where we get the pragma stuff, like hence #pragma once
// when you call #pragma once, it means you call on it Only Once
// pragma is NOT STANDARD, meaning that it might not run on a different gnu, like linux. it's a microsoft-only thing, so be careful
// pragma is the same as #include; it's useless w/o #ifndef
// pseudo-code only describes the main function. mention where the functions and classes come from and stuff and in parentheses do (see UML)
//

// remember, it's hard to debug things if you don't do #include in your header files and stuff
#include <iostream>
#include <string>
#include <cmath>
#include <array> //if you don't include this, then you will be Forced to do arrays the Old Way. Evilly.
#include <iomanip>
#include <algorithm> //need this for sorting
//#include <cstdlib> //you could do this, but be careful bc it might bloat your project

using namespace std;

// void showdata(array<int, arraySize>&);
const size_t arraySize{10};               // size of the array MUST be constant. doesn't have to be global, but the prof uses them in other functions
void sortArr(array<int, arraySize> &arr); // pass by ref

int main()
{
    // int arr1[arraySize] = {2, -6, 4, -8, 10, 12, 89, 68, 45, 37}; //this is the old way. you COULD do it, but like. why would you. you can't use sort that way.
    // cout << "hi" << endl;
    // static means you have to declare the array size from the start
    static array<int, arraySize> arr1{2, -6, 4, -8, 10, 12, 89, 68, 45, 37}; 
    // these don't Have to be static btw. but if you DO, then you MUST supply the size of the array and it MUST be an integer
    static array<int, arraySize> arr2{};                         
    // we didn't used to have this, before template arrays! we'd have to write functions for it and it was hideous.            
    cout << "the size of the array is " << arr1.size() << endl;              
    cout << "the third el of the arr arr1 is " << arr1.at(3) << endl;        // alt is
    cout << "the last el of the array is " << arr1.back() << endl;
    cout << "now sorting the array.\n";
    // sortArr(arr1); //this is bad and evil, btw. someone gives you a list and you mess up their list, you are fired.
    /*cout << "the size of the array is " << arr1.size() << endl; //we didn't used to have this, before template arrays! we'd have to write functions for it and it was hideous.
    cout << "the third el of the arr arr1 is " << arr1.at(3) << endl; //alt is
    cout << "the last el of the array is " << arr1.back() << endl;*/

    //arrays have a really big overhead bc you'll never be able to use all of it. arrays are just a tool for us to pull data and stuff. as a result, we use linked lists and stuff in order to keep things from getting too slow

    cout << "\n\nThe address of arr[1] is " << &arr1 << endl << endl; //these are hex codes. you can convert these to binary. notice how the last 4 digits do things. this is important for, like, a machine language class, converting from number to hex to binary
    //in hexidecimal, A = 10, B = 11, C = 12, D = 13, E = 14, and F = 15
    for (int i{0}; i < arr1.size(); i++) //this version lets you do things based off your current index
    //for (int i : arr1)
    {
        arr2[i] = arr1[i];
        cout << setw(10) << &arr1[i]; //these hex code physical address numbers go up by 4 each bc an integer takes up 4 bytes. this is how we trace data and rebuild it from a physical hard drive.
        //arr2 += i;
    }
    cout << "\n\n";
    arr2 = arr1; //is this cool can we do this
    //the answer is yes we Can do that ^ but i suspect that if you had a differently sized array, something terrible would happen
    // for (int i{65}; i < (65+26); i++) {cout << char(i);}
    sortArr(arr2); // sort the DUPE
    // DOOOOOOOOOOOOOOOOO NOT EVERRRRRRRRRRRRRRRRRRRRRRRRR DELETE YOUR GROUPMATES' CODE. COMMENT IT OUTTTTTTTTTTTT

    // static arrays are NOT the same as static functions
    const static array<int, 3> arr3{-1, 0, 1};
    // int dynArr{5};
    // array<int, dynArr> arr4{};

    //int arrTemp[arraySize]; // this is a mystery integer that will help us later.
    for (int i : arr2)
    { // same as "for (blank of blank)" in js, wherein you can't do anything specific to the index
        cout << setw(10) << i;
    }


    //now for multi-dimensional arrays. you can only have two dimensions to these
    //now we need to start having tables for things. they're basically excel files; this is why spreadsheets are like compsci Lite(tm)
    //rows and columns become Fields
    const int colSize{3}, rowSize{3};
    //this stuff is hard and nasty hardcoded, so that's why you have <fstream> to pull up n read files. csv~
    //to learn perl, you have to know linux; before you can know linux and unix, you have to know shell coding
    array<array<int, colSize>, rowSize> proj1{ //you'll have the col first, then row
        12, 32, 42,
        54, 32, 88,
        95, 65, 103
    };
        int ttl{0};


    array<int, 3> arTmp{1, 2, 3};
    for(int i{0}; i < arTmp.size() - 4; i++) {
        ttl += ttl + arTmp[i];
    }


    return 0;
}

void sortArr(array<int, arraySize> &arr)
{
    sort(arr.begin() /* you cannot use a plain number here. it must be something that has to do w/the array, so you can do something like arr.at(2) if you want */, arr.end() /* to only sort the first 4 elements, you add a "-3" after the arr.end() */); // normal sort
}

void dupeArr(array<int, arraySize> &arr) {

}
