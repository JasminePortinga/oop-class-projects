// writing on a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib> // contains function prototype for rand

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(0)));  //Generate a random number based on the computer timer.
	string fileName{ "Array for Project 7.txt" }, line;
	double arr[11][7];

	//	ofstream outFile("example.txt");
/*	
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		outFile << "This is a random number: " << (1 + rand() % 100) << endl;
		outFile << "This is another random number: " << (1 + rand() % 100) << endl;
		//		outFile << "This is another line.\n";
		outFile.close();
	}
*/
	ifstream inFile(fileName);
	getline(inFile, line);
	line = "";

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			int i{ 0 };
			int j{ 0 };

			string val1;
			string val2;
			string val3;
			string val4;
			string val5;
			string val6;
			string val7;

			float num1;
			float num2;
			float num3;
			float num4;
			float num5;
			float num6;
			float num7;

			if (line == "\n" || line == "\r")
				cout << "Next line" << endl << endl;

			stringstream inputString(line);
			getline(inputString, val1, ',');
			arr[i][0] = atof(val1.c_str());
			getline(inputString, val2, ',');
			arr[i][1] = atof(val2.c_str());
			getline(inputString, val3, ',');
			arr[i][2] = atof(val3.c_str());	
			getline(inputString, val4, ',');
			arr[i][3] = atof(val4.c_str());
			getline(inputString, val5, ',');
			arr[i][4] = atof(val5.c_str());
			getline(inputString, val6, ',');
			arr[i][5] = atof(val6.c_str());
			getline(inputString, val7, ' ');
			arr[i][6] = atof(val7.c_str());

			cout << arr[0][1] << " + " << arr[0][3] << " = " << arr[0][1] + arr[0][3] << endl;

			line = "";
			i++;
		}  //END of WHILE
//			cout << line << '\n';
//			cout << val1 << " " << val4 << endl;
//			cout << arr[3][1] << " + " << arr[3][3] << " = " << arr[3][1] + arr[3][3] << endl;
//		}
		inFile.close();
	}

	else cout << "Unable to open file";
	return 0;
}