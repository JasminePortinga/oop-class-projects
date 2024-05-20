#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string dept, unit, empl_id;
int compCount[8][5];

void setDept(string);
string getDept();
void setUnit(string);
string getDeptUnit();
unsigned int getDeptCount(string);
unsigned int getUnitCount(string);
string toString();

int main()
{
	//	company comp;
	//	cout << comp.toString() << endl;

	string fileName{ "Employee Sample Data.csv" };
	string line;
	//	string fileName{ "Array for Project 7.txt" }, line;
	ifstream inFile(fileName); //File contains sales data.

	array<string, 14> header;
	//	getline(inFile, line);    //Get the field names (first row of the file "Array for Project 7.txt".

	for (int i{ 0 }; i < header.size(); i++) {
		getline(inFile, header[i], ',');
	}
	//	std::cout << endl << setw(9) << header[0] << setw(21) << header[1] << setw(31) <<
	//		header[2] << setw(16) << header[3] << setw(25) << header[4] << setw(9) <<
	//		header[5] << setw(10) << header[6] << setw(5) << header[7] << setw(12) <<
	//		header[8] << endl;

	cout << endl << header[0] << "," << header[1] << "," <<
		header[2] << "," << header[3] << "," << header[4] << "," <<
		header[5] << "," << header[6] << "," << header[7] << "," <<
		header[8] << endl;

	//	getline(inFile, line);    //Skip the header.
	//	line = "";

	ofstream outFile("Final - Spring 2024.csv");  //Create an output file.

	//Write the column header to the output file.
	outFile << header[0] << "," << header[1] << "," <<
		header[2] << "," << header[3] << "," << header[4] << "," <<
		header[5] << "," << header[6] << "," << header[7] << "," <<
		header[8] << endl;


	int lineTtl{ 0 };   //count the number of records.
	const size_t num{ 10 };

	if (inFile.is_open())
	{
		//		outFile << "" << endl;

		float ttlUnt{ 0 };

		while (getline(inFile, line))
		{
			string val[14];
			float num[13];

			stringstream inputString(line);

			getline(inputString, val[0], ',');
			getline(inputString, val[1], ',');
			getline(inputString, val[2], ',');
			getline(inputString, val[3], ',');
			getline(inputString, val[4], ',');
			getline(inputString, val[5], ',');
			getline(inputString, val[6], ',');
			getline(inputString, val[7], ',');
			num[0] = atof(val[7].c_str());
			getline(inputString, val[8], ',');
			getline(inputString, val[9], ',');
			getline(inputString, val[10], ',');
			num[1] = atof(val[10].c_str());
			getline(inputString, val[11], ',');
			num[2] = atof(val[11].c_str());
			getline(inputString, val[12], ',');
			getline(inputString, val[13], ',');

			//			cout << setw(9) << val[0] << setw(21) << val[1] << setw(31) << val[2] <<
			//				setw(16) << val[3] << setw(25) << val[4] << setw(9) << val[5] <<
			//				setw(10) << val[6] << setw(5) << num[0] << setw(12) << val[8] << endl;

			cout << val[0] << "," << val[1] << "," << val[2] <<
				"," << val[3] << "," << val[4] << "," << val[5] <<
				"," << val[6] << "," << num[0] << "," << val[8] <<
				val[9] << "," << val[10] << "," << val[11] << "," << val[12] <<
				"," << val[13] << endl;

			if (outFile.is_open())
			{
				outFile << val[0] << "," << val[1] << "," << val[2] << "," << val[3] <<
					"," << val[4] << "," << val[5] << "," << val[6] << "," <<
					num[0] << "," << val[8] <<
					val[9] << "," << val[10] << "," << val[11] << "," << val[12] <<
					"," << val[13] << endl;
			}

			//			line = "";
		}//END of WHILE
	}//END of IF

	outFile.close();

	cout << "\nThe number of employee is: " << getDeptCount(fileName) << endl << endl;
	getUnitCount(fileName);

	for (int i{ 0 }; i < 8; i++) {
		for (int j{ 0 }; j < 5; j++)
			switch (i)
			{
			case 0:
				cout << setw(20) << ((j == 0) ? "Accounting:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 1:
				cout << setw(20) << ((j == 0) ? "Engineering:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 2:
				cout << setw(20) << ((j == 0) ? "Finance:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 3:
				cout << setw(20) << ((j == 0) ? "Human Resouces:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 4:
				cout << setw(20) << ((j == 0) ? "IT:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 5:
				cout << setw(20) << ((j == 0) ? "Marketing:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			case 6:
				cout << setw(20) << ((j == 0) ? "Sales:" : " ") << setw(25) << ((j == 0) ? "Corporate" : (j == 1) ? "Manufacturing" :
					(j == 2) ? "Research & Development" : (j == 3) ? "Speciality Products" : (j == 4) ? "TOTAL: " : " ") << setw(15) <<
					compCount[i][j] << ((j == 4) ? "\n\n" : "\n");
				break;
			default:
				//			cout << setw(20) << ((j == 0) ? "Total:" : " ")<< setw(10) << compCount[i][5] << setw(15) << compCount[i][j] << endl;
				break;
			}
	}

	return 0;
}


void setDept(string dep) {
	dept = dep;
}

string getDept() {
	return dept;
}

void setUnit(string unt) {
	unit = unt;
}

string getDeptUnit() {
	return unit;
}

unsigned int getDeptCount(string file) {       //return the total employees in a department.
	ifstream inFile(file); //File contains sales datda.
	string line;
	getline(inFile, line);    //Remove the first line of the file inFile.
	int count{ 0 }, countAcct{ 0 }, countEngr{ 0 }, countFin{ 0 }, countHr{ 0 }, countIt{ 0 },
		countMarkt{ 0 }, countSales{ 0 }, countDept{ 0 }, countUnit{ 0 };

	if (inFile.is_open())
	{
		float ttlUnt{ 0 };

		while (getline(inFile, line))
		{
			string val[14];
			float num[14];

			stringstream inputString(line);

			getline(inputString, val[0], ',');
			getline(inputString, val[1], ',');
			getline(inputString, val[2], ',');

			getline(inputString, val[3], ',');
			getline(inputString, val[4], ',');

			if (val[3] == "Accounting") {
				compCount[0][4]++;

				if (val[4] == "Corporate")
					compCount[0][0]++;
				else if (val[4] == "Manufacturing")
					compCount[0][1]++;
				else if (val[4] == "Research & Development")
					compCount[0][2]++;
				else if (val[4] == "Speciality Products")
					compCount[0][3]++;

				count++;
			}
			else if (val[3] == "Engineering") {
				compCount[1][4]++;
				if (val[4] == "Corporate")
					compCount[1][0]++;
				else if (val[4] == "Manufacturing")
					compCount[1][1]++;
				else if (val[4] == "Research & Development")
					compCount[1][2]++;
				else if (val[4] == "Speciality Products")
					compCount[1][3]++;

				count++;
			}
			else if (val[3] == "Finance") {
				compCount[2][4]++;
				if (val[4] == "Corporate")
					compCount[2][0]++;
				else if (val[4] == "Manufacturing")
					compCount[2][1]++;
				else if (val[4] == "Research & Development")
					compCount[2][2]++;
				else if (val[4] == "Speciality Products")
					compCount[2][3]++;

				count++;
			}
			else if (val[3] == "Human Resources") {
				compCount[3][4]++;
				if (val[4] == "Corporate")
					compCount[3][0]++;
				else if (val[4] == "Manufacturing")
					compCount[3][1]++;
				else if (val[4] == "Research & Development")
					compCount[3][2]++;
				else if (val[4] == "Speciality Products")
					compCount[3][3]++;

				count++;
			}
			else if (val[3] == "IT") {
				compCount[4][4]++;
				if (val[4] == "Corporate")
					compCount[4][0]++;
				else if (val[4] == "Manufacturing")
					compCount[4][1]++;
				else if (val[4] == "Research & Development")
					compCount[4][2]++;
				else if (val[4] == "Speciality Products")
					compCount[4][3]++;

				count++;
			}
			else if (val[3] == "Marketing") {
				compCount[5][4]++;

				if (val[4] == "Corporate")
					compCount[5][0]++;
				else if (val[4] == "Manufacturing")
					compCount[5][1]++;
				else if (val[4] == "Research & Development")
					compCount[5][2]++;
				else if (val[4] == "Speciality Products")
					compCount[5][3]++;

				count++;
			}
			else if (val[3] == "Sales") {
				compCount[6][4]++;

				if (val[4] == "Corporate")
					compCount[6][0]++;
				else if (val[4] == "Manufacturing")
					compCount[6][1]++;
				else if (val[4] == "Research & Development")
					compCount[6][2]++;
				else if (val[4] == "Speciality Products")
					compCount[6][3]++;

				count++;
			}
			compCount[4][0] = count;
		}  //END of WHILE
	}   //END of IF
	return count;
}


unsigned int getUnitCount() {       //return the total employees in a unit.
	return 0;
}

unsigned int getUnitCount(string file) {       //return the total employees in a department.
	ifstream inFile(file); //File contains sales datda.
	string line;
	getline(inFile, line);    //Remove the first line of the file inFile.
	int count{ 0 }, countAcct{ 0 }, countEngr{ 0 }, countFin{ 0 }, countHr{ 0 }, countIt{ 0 },
		countMarkt{ 0 }, countSales{ 0 }, countDept{ 0 }, countUnit{ 0 };

	if (inFile.is_open())
	{
		float ttlUnt{ 0 };

		while (getline(inFile, line))
		{
			string val[14];
			float num[14];

			stringstream inputString(line);

			getline(inputString, val[0], ',');
			getline(inputString, val[1], ',');
			getline(inputString, val[2], ',');
			getline(inputString, val[3], ',');

			getline(inputString, val[4], ',');
			if (val[4] == "Corporate") {
				count++;
			}
			else if (val[4] == "Manufacturing") {
				count++;
			}
			else if (val[4] == "Research & Development") {
				count++;
			}
			else if (val[4] == "Specialty Products") {
				count++;
			}
			else {
				count++;
			}
		}  //END of WHILE
	}   //END of IF
	return count;
}

string toString() {
	return "This function is called from the Base class company{}.\n";
}
