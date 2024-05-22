#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

// year-end salary should be annual salary / 12 * bonus

using namespace std;

string dept, unit, empl_id;
int compCount[8][5];

int main()
{
	//	company comp;
	//	cout << comp.toString() << endl;

	string fileName{ "Employee Sample Data.csv" }, line;
	//	string fileName{ "Array for Project 7.txt" }, line;
	ifstream inFile(fileName); //File contains sales datda.

	array<string, 13> header;
	//	getline(inFile, line);    //Get the field names (first row of the file "Array for Project 7.txt".

	for (int i{ 0 }; i < header.size(); i++) {
		getline(inFile, header[i], ',');
	}

	//	std::cout << setw(9) << header[0] << setw(21) << header[1] << setw(31) <<
	//		header[2] << setw(16) << header[3] << setw(25) << header[4] << setw(9) <<
	//		header[5] << setw(10) << header[6] << setw(5) << header[7] << setw(12) <<
	//		header[8] << setw(12) << header[9] << setw(12) << header[10] << 
	//		setw(12) << header[11] << setw(12) << header[12] << endl;

	std::cout << header[0] << "," << header[1] << "," << header[2] << "," <<
		header[3] << "," << header[4] << "," << header[5] << "," << header[6] <<
		"," << header[7] << "," << header[8] << "," << header[9] << "," << header[10] <<
		"," << header[11] << "," << header[12] << endl;

	getline(inFile, line);    //Skip the header.
	line = "";

	ofstream outFile("Employee Sample Data Output.csv");  //Create an output file.

	if (outFile.is_open()) {
		outFile << header[0] << "," << header[1] << "," << header[2] << "," <<
			header[3] << "," << header[4] << "," << header[5] << "," << header[6] <<
			"," << header[7] << "," << header[8] << "," << header[9] << "," << header[10] <<
			"," << header[11] << "," << header[12] << endl;
	}

	int lineTtl{ 0 };   //count the number of records.
	int countAsi(0), countAsiM(0), countAsiF(0), countBlck(0), countBlckM(0), countBlckF(0),
		countCau(0), countCauM(0), countCauF(0), countLat(0), countLatM(0), countLatF(0),
		countM(0), countF(0);
	float mTtlSal(0), mAvgSal(0), fTtlSal(0), fAvgSal(0);

	const size_t num{ 10 };

	if (inFile.is_open())
	{
		//		outFile << "" << endl;
		float ttlUnt{ 0 };

		while (getline(inFile, line))
		{
			string val[14];
			float num[3];

			stringstream inputString(line);

			getline(inputString, val[0], ',');
			getline(inputString, val[1], ',');
			getline(inputString, val[2], ',');
			getline(inputString, val[3], ',');
			getline(inputString, val[4], ',');
			getline(inputString, val[5], ',');
			getline(inputString, val[6], ',');
			if (val[6] == "Asian" && val[5] == "Male")
				countAsiM++;
			else if (val[6] == "Black" && val[5] == "Male")
				countBlckM++;
			else if (val[6] == "Caucasian" && val[5] == "Male")
				countCauM++;
			else if (val[6] == "Latino" && val[5] == "Male")
				countLatM++;
			if (val[6] == "Asian" && val[5] == "Female")
				countAsiF++;
			else if (val[6] == "Black" && val[5] == "Female")
				countBlckF++;
			else if (val[6] == "Caucasian" && val[5] == "Female")
				countCauF++;
			else if (val[6] == "Latino" && val[5] == "Female")
				countLatF++;

			getline(inputString, val[7], ',');
			num[0] = atof(val[7].c_str());

			getline(inputString, val[8], ',');
			getline(inputString, val[9], ',');
			num[1] = atof(val[9].c_str());

			if (val[5] == "Female") {
				fTtlSal += num[1];
				countF++;
			}
			else if (val[5] == "Male") {
				mTtlSal += num[1];
				countM++;
			}
			getline(inputString, val[10], ',');
			num[2] = atof(val[10].c_str());

			getline(inputString, val[11], ',');
			getline(inputString, val[12], ',');
			getline(inputString, val[13], ',');

			//			cout << setw(9) << val[0] << setw(21) << val[1] << setw(31) << val[2] <<
			//				setw(16) << val[3] << setw(25) << val[4] << setw(9) << val[5] <<
			//				setw(10) << val[6] << setw(5) << num[0] << setw(12) << val[8] << 
			//				setw(12) << val[9] << setw(12) << num[1] << setw(12) << num[2] << 
			//				setw(12) << val[12] << setw(12) << val[13] << endl;

			cout << val[0] << "," << val[1] << "," << val[2] << "," << val[3] << "," <<
				val[4] << "," << val[5] << "," << val[6] << "," << num[0] << "," << val[8] <<
				"," << val[9] << "," << num[1] << "," << num[2] << "," << val[12] << "," <<
				val[13] << endl;

			if (outFile.is_open()) {
				outFile << val[0] << "," << val[1] << "," << val[2] << "," << val[3] << "," <<
					val[4] << "," << val[5] << "," << val[6] << "," << num[0] << "," << val[8] <<
					"," << val[9] << "," << num[1] << "," << num[2] << "," << val[12] << "," <<
					val[13] << endl;
			}  // END of IF(OutFile.is_open())

			line = "";
		}//END of WHILE
		fAvgSal = fTtlSal / countF;		//get Average Salary of Female
		mAvgSal = mTtlSal / countM;		//get Average Salary of Male
	}//END of IF(inFile.is_open())

	outFile.close();

	cout << endl;
	cout << setw(15) << "Ethnicity count:" << endl;
	cout << setw(15) << ' ' << setw(10) << "Female" << setw(10) << "Male" << endl;
	cout << setw(15) << "Asian: " << setw(10) << countAsiF << setw(10) << countAsiM << endl;
	cout << setw(15) << "Black: " << setw(10) << countBlckF << setw(10) << countBlckM << endl;
	cout << setw(15) << "Caucasian: " << setw(10) << countCauF << setw(10) << countCauM << endl;
	cout << setw(15) << "Latino:" << setw(10) << countLatF << setw(10) << countLatM << endl;
	cout << setw(15) << "======:" << endl;
	cout << setw(15) << "Total:" << setw(10) << countAsiM + countBlckM + countCauM + countLatM <<
		setw(10) << countAsiF + countBlckF + countCauF + countLatF << endl << endl;
	//	cout << "Total Female: " << countF << endl;
	//	cout << "Total Male: " << countM << endl;
	//	cout << "Total Female Salary: " << fTtlSal << endl;
	//	cout << "Total Male Salary: " << mTtlSal << endl;
	cout << "Average Female Salary: " << fAvgSal << endl;
	cout << "Average Male Salary: " << mAvgSal << endl;

	ofstream outEmplStat("Employee Sample Data Statistic.csv");  //Create an output file.

	if (outEmplStat.is_open()) {
		outEmplStat << "Ethnicity count:" << endl
			<< "," << ' ' << "," << "Female" << ',' << "Male" << endl
			<< "," << "Asian:" << "," << countAsiM << ',' << countAsiF << endl
			<< "," << "Black: " << ',' << countBlckM << ',' << countBlckF << endl
			<< "," << "Caucasian: " << ',' << countCauM << ',' << countCauF << endl
			<< "," << "Latino:" << ',' << countLatM << ',' << countLatF << endl
			<< "," << "======:" << ',' << endl
			<< "," << "Total:" << ',' << countAsiM + countBlckM + countCauM + countLatM << ','
			<< countAsiF + countBlckF + countCauF + countLatF << endl
			<< ',' << "Grand Total" << ',' << countAsiM + countBlckM + countCauM + countLatM + countAsiF + countBlckF + countCauF + countLatF <<
			endl << endl << endl
			<< "Average Salaries by Gender:\n"
			<< ',' << "Female" << ',' << "Male" << endl
			<< ',' << fAvgSal << ',' << mAvgSal << endl;
	}
	outEmplStat.close();

	return 0;
}

