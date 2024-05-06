//File Name: Exchange.cpp

#include <iostream>
#include <iomanip> // Enable setprecision()
#include <string>  // Enables string modification
#include <vector>
// #include <fstream> //jasmine is tired of always having to print things to the terminal and wants a log.txt
#include "Exchange-5.h"
using namespace std;

Exchange::Exchange() {}

Exchange::Exchange(string cnty, vector<float>& curr) {
	countries.push_back(cnty);
	exch.push_back(curr);
}

// void Exchange::checkVec() {
//     fstream log;
//     log.open("log.txt");
//     if (!log.is_open()) {
//         log.clear();
//         log.open("log.txt", ios::out);
//         log.close();
//         log.open("log.txt");
//     }
//     log << "Checking the exchange vector..." << endl;
//     log << "--------------------------------" << endl;
//     for (int i{0}; i < exch.size(); i++) {
// //cout << "Layer 1: the vector of vectors: we are currently on item " << i << endl;
//         for (int j{0}; j < exch[i].size(); j++) {
//             log << "exch[" << i << "]" << "[" << j << "], has the value of: " << exch[i][j] << endl;
//         }
//     }
//     log << "--------------------------------" << endl;
//     log.clear();
//     log.close();
// }

void Exchange::vecInit(vector<vector<float>> vec) {
    exch = vec;
    

    // wrote this to check if the vector was being properly initialized
    // cout << "\n\nThis is the standard initialization procedure. let's loop through the values:\n";
    // for (int i{0}; i < exch.size(); i++) {
    //     cout << "Layer 1: the vector of vectors: we are currently on item " << i << endl;
    //     for (int j{0}; j < exch[i].size(); j++) {
    //         cout << "Layer 2: the vector of floats. We are currently on item " << j << ", which has the value of: " << exch[i][j] << endl;
    //     }
    // }
//Initialize the PRIVATE vector exch<> using the providing parameter.

}


//Add an overloading function with a 2-dimensional vector pointer to the above vecInit() function.
//Initialize the PRIVATE vector exch<> using this pointer. 

void Exchange::vecInit(vector<vector<float>>* vec) {
    //auto vecPtr = new vector<vector<float>>;
    for (vector<float> curr : *vec) { //for every currency this vector points to, add it to the private vector
        exch.push_back(curr);
        //cout << setw(15) << "current thing being pushed in is a vector, so its first value is: " << curr[0];
    }
    //checkVec();
    // wrote this to check if the vector was being properly initialized
    // cout << "\n\nThis is the initialization procedure using a pointer. let's loop through the new values of the private var \"exch\":\n";
    // for (int i{0}; i < exch.size(); i++) {
    //     cout << "Layer 1: the vector of vectors: we are currently on item " << i << endl;
    //     for (int j{0}; j < exch[i].size(); j++) {
    //         cout << "Layer 2: the vector of floats. We are currently on item " << j << ", which has the value of: " << exch[i][j] << endl;
    //     }
    // }
    
}

void Exchange::addCurr(vector<vector<float>> vec) {
   // exch.push_back(vec);
   for (vector<float> curr : vec) {
        exch.push_back(curr);
   }
    // cout << "Currency has been added. Let's check the vector:\n";
    //checkVec();
//Initialize the PRIVATE vector exch<> using the provided 2-dimensional vector parameter.

}


//void Exchange::cntyInit(parameter is a vector of type string.) {
//    void Exchange::cntyInit(std::vector<std::string>& cnty) {
void Exchange::cntyInit(std::vector<std::string> cnty) {
    countries = cnty;
//Initialize the PRIVATE vector countries<> using the providing vector parameter.

}

void Exchange::cntyInit(std::vector<std::string>* cnty) {
    // Initialize countries using the pointer vec
    for (auto count : *cnty) {
        countries.push_back(count);
    }
}


//Add an overloading function cntyInit() with a  string vector pointer as parameter.
//Initialize the PRIVATE vector countrie<> using this pointer.
//void Exchange::cntyInit(vector<string>*) {}



//The function addCoun() adds vector element to the PRIVATE vector countries<>.
//Use this function to add 'Cuban Peso' and 'Philippine Peso' to the PRIVATE 
//vector countries<>.

void Exchange::addCoun(vector<string> ctry) {
    for (auto count : ctry) { //extract each string from the vector you feed the function
        countries.push_back(count); //push that string into the countries vector
    }
//Add the providing vector parameter to the PRIVATE vector countries<>.

}


void Exchange::US_Foreign(double amt) {
    double user;
    //int counter = 0;
    int history;
    int counter{1}; //why was it initialized to 0 if we just add 1.
    //count += 1;
    cout << endl << endl;
    showCur(amt);
    // for (int i{1}; i <= countries.size(); i++) {
    //     Display(i);
    // }
    
    // cout << setw(21) << "US Dollar";
    // cout << setw(10) << "  " << "1           ";
	//cout << amt << endl;

	// while (counter < exch.size()) {
    //     cout << setw(3) << counter + 1;
    //     cout << setw(18) << countries[counter];
    //     cout << setw(10) << "  " << exch[counter][0];
	// 	cout << setw(10) << "  " << (amt * (exch[counter][0])) << endl;
    //     counter = counter + 1;
    // }
}

void Exchange::Foreign_US(double amt) {
	int choice;
    //showCur(100); // show all the currencies for choosing
    //Display();
    for (int i{1}; i <= countries.size(); i++) {
        Display(i);
        cout << endl;
    }
	cout << endl << "Choose a currency: ";
	cin >> choice;
    cout << endl;
    //Display(choice);
    //showCur(amt);
	cout << setw(35) << string("From US$ to " + string(countries[choice - 1])) << setw(15);
	cout << "$1" << setw(15) << round(100*(exch[choice - 1][0]))/100 << endl;

	cout << setw(35) << string("From " + countries[choice - 1] + " to US$ ") << setw(15);
	cout << amt << setw(15) << round(100*(amt / exch[choice - 1][0]))/100 << endl << endl;
}


void Exchange::Display(int i) {
    //cout << setw(5) << i << ". " << setw(20) << countries[i-1] << setw(10) << round(100*(exch[i-1][0]))/100 << setw(10) << round(100*(amt * exch[i-1][1]))/100 << endl;
    cout << setw(5) << i << ". " << setw(20) << countries[i-1];
    // for (string i : countries) {
    //     cout << i << endl;
    // }

    // cout << endl;
    // for (vector<float> i : exch) { //for every vector of floats in the exchange vector
    //     for (double j : i) { //now for every float val in that vector
    //         cout << j << ",     ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}


void Exchange::showCur(double amt) {
    //cout << "trying to show currencies.\n";
    // int n = 0;
    // int limit = countries.size();
    cout << setw(5) << " " <<setw(2) << " " << setw(20) << "US Dollars " << setw(10) << 1 << setw(10) << amt << endl;
    for (int i{1}; i <= countries.size(); i++) {
        Display(i);
        cout << setw(10) << round(100*(exch[i-1][0]))/100 << setw(10) << round(100*(amt * exch[i-1][1]))/100 << endl;
        // for (int j{0}; j < exch[i-1].size(); j++) {
        //     cout << setw(10) << (amt * exch[i-1][j]);
        // }
        //cout << endl;
    }
    // while (n < limit) {
    //     cout << n + 1;
    //     if (n <= 8) {
    //         cout << setw(18) << countries[n];
    //     }
    //     else {
    //         cout << setw(17) << countries[n];
    //     }
    //     n = n + 1;
    //     cout << endl;
    // }
}

