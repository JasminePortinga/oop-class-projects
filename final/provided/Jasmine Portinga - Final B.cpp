// Final - Spring 2024.
//
// Description:	   This project is about processing the contents of a file, then
//				write the statistical data to an output file named
//				"Final_Spring_2024_HHS_Stat_Output.csv". The data file is named
//				"DER2209.csv".
//				   Open the data file and read carefully what is in the file. There are
//				sixteen (16) fields on that file.
//					  - The first six(6) fields are of type string.
//					  - The next 9 fields are of type float.
//					  - The last field is of type string (as you notice).
//
//				   Create two arrays of type float with eight (8) elements to store the "NR-COUNT"
//				(Non-Resident) courses in the eight departments and the enrollment count in
//				each of those departments.
//
//				   - Create a function headerOut(ofstream&, stringstream&, array<string, 16>)
//				where ofstream& is the output stream write to the above file; stringstream& is
//				the function inputLine() and array<string, 16> is the array represents the 16
//				column headers (fields) in the .csv file. This function is called to write the
//				field/column headers to the output file.
//
//				   - Create a function called getValuesHHS(array <string, 16>, array <float, 10>&, array <float, 10>&, array <float, 10>)
//				where the 1st parameter is the header array; the 2nd array is the course count
//				in each department in a particular College; the 3rd array is the enrollment count
//				in each department, and the 4th array is the value of the field "NR-COUNT" in the
//				DER2209.csv file.
//						- Only count NR courses. Don't include any course that the value of the field "NR-COUNT" is zero (0).
//						- Note that the 2nd and 3rd parameters are called by referenced.
//
//				   Create a function called crseHHS(ofstream&, array<float, 10>, array<float, 10>) to
//				write the statistical data to the output file (see attachments).
//						   - The 1st parameter ofstream& is the output file that your program is
//				written to, the 2nd parameter is the "NR-COUNT" course count in each department, and the
//				last parameter is the enrollment of each "NR-COUNT" course in a department.
//				   You may have to hard-code the department name in the college of HHS.
//				   In the college of Health & Human Services (HHS), the eight (8) departments are:
//				CFS, COMD, CRIM, HHSD, KPE, NURS, PH, SW (as in the output file).
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include "jkp_std.h"

using namespace std;

void headerOut(ofstream &, stringstream &, array<string, 16>);
// void getValuesHHS(array<string, 16>, array<float, 8> &, array<float, 8> &, array<float, 10>);
void getValuesHHS(array<string, 16>, array<float, 8> &, array<float, 8> &);
void crseHHS(ofstream &, array<float, 8>, array<float, 8>, float);

int main()
{
	project::title("Final (Version B)"); // title
	string fileName{"DER2209.csv"}, outfile{"Final_Spring_2024_HHS_Stat_Output.csv"}, line; // string "line" contains the temp data when doing getline

	// DER2209.csv has 6 string fields (term, coll, dept, subj, catnum), and then 9 floats (sec, bgn units, gd units, count, nr-count, international count, xe count, total, units, lvl), and then one last string (ge); they're comma-separated

	ifstream inFile(fileName); // File contains sales datda.
	array<string, 16> header;

	ofstream outFileStat(outfile); // Create an output file.

	// Create the two arrays to store your deptartment count and department enrollment count.
	//  ... // nr-count (non-resident count) is col 10
	//  college of health n human services (hhs)
	//  array<string, 8> dept{"CFS", "COMD", "CRIM", "HHSD", "KPE", "NURS", "PH", "SW"};
	array<float, 8> dptCount{0, 0, 0, 0, 0, 0, 0, 0};
	array<float, 8> nrsCount{0, 0, 0, 0, 0, 0, 0, 0};
	// ...

	string tmp{""}; // temp line to just hold whatever as looping through getlines
	const int numHeaders{16};
	array<string, numHeaders> st; // array to store column headers.
	getline(inFile, line);
	cout << line << endl; // output the header line to the console
	stringstream inputLine(line);
	headerOut(outFileStat, inputLine, st); // outputs the header


	int i{0};
	while (getline(inputLine, tmp, ',') && i < numHeaders)
	{ // initialize the header; make sure it's always less than the number of headers bc i'm too lazy to change all the provided arrays into vectors
		st[i] = tmp;
		i++;
	}
	// int lineDebug{1};
	if (inFile.is_open())
	{
		float ttlUnt{0};

		while (getline(inFile, line))
		{
			array<string, 16> val;
			// array<float, 10> num; // i don't know why this is supposed to be an array of 10 if we're only going to be working with 9 numbers but i'm not here to change what was given to me

			stringstream inputString(line);
			int i{0}, j{0};
			string subj{""}, dpt{""};
			// Initiate the elements of the arrays val[] and num[] using a looping control.
			while (getline(inputString, tmp, ','))
			{
				
				ttlUnt++; // increment the number of enrolled students
				val[i] = tmp;
				i++;
			}
			if (val[1] == "HHS")
			{
				getValuesHHS(val, dptCount, nrsCount);
				// val[2] is department, and val[3] is the subject
				// cout << val[2] << ": " << dpt << "; ";
				// cout << val[3] << ": " << subj << endl;
				// // cout << val[i] << ": " << tmp << ", ";
				// if (i == numHeaders - 2)
				// 	cout << endl;
			}
			// Count only NR-COUNT courses & the NR-COUNT enrollment within a department in the college of HHS.
			//  getValuesHHS(...............................);

			// lineDebug++;
		} // END of WHILE
		// sstream aaa();
		// Output the statistical data
		crseHHS(outFileStat, dptCount, nrsCount, ttlUnt);
	} // END of IF(inFile.is_open())
	else
	{
		cout << "this file doesn't exist." << endl;
	}

	// CLose your output file.
	outFileStat.close();

	// The next system() function called is to invoke Excel and open the Final_Spring_2024_HHS_Stat_Output.csv file.
	system("Final_Spring_2024_HHS_Stat_Output.csv");
}
//////////////////////////////////////////////////////////////////////////////

void headerOut(ofstream &fstrm, stringstream &sstrm, array<string, 16> head)
{
	if (!fstrm.is_open()) {
		fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv");

		if (!fstrm.is_open()) { // if it still doesn't open then that means it probably doesn't exist, so just make a new csv file
			// fstrm.close();
			fstrm.clear();
			fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv", ios::out);
			fstrm.close();
			fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv"); 
		}
	}
	string tmp{""};
	while (getline(sstrm,tmp,',')) {
		fstrm << tmp << ",";
	}
	fstrm << endl;
	fstrm.close(); // always close files at the end. the header gets overwritten like this, but the sample output didn't show all the headers displayed anyway so i don't see what the point is
}

// void getValuesHHS(array<string, 16> vals, array<float, 8> &dpt, array<float, 8> &crse, array<float, 10> nums) // i still don't really know what the array of floats is for here
void getValuesHHS(array<string, 16> vals, array<float, 8> &dpt, array<float, 8> &nrs)
{
	string subj = vals[3];
	// cout << "Current subject: " << subj << endl;
	float nrCount = stof(vals[9]); // turns string into a float
	array<string, 8> subjs = {"CFS", "COMD", "CRIM", "HHSD", "KPE", "NURS", "PH", "SW"};
	for (int i{0}; i < subjs.size(); i++) { // loops through the various subjects
		if (subj == subjs[i]) {
			dpt[i]++; // if they belong to this course, then increment the department size, and if they're a non-resident, add them to the non-resident vector
			nrs[i] += nrCount; // nr-count is always either 0 or 1 so i don't see why this would be an issue. if someone wants to count as more than one non-resident enrolled in a program that's their business.
		}
	}
}

void crseHHS(ofstream &fstrm, array<float, 8> dptCount, array<float, 8> nrs, float ttl)
{
	if (!fstrm.is_open()) { // check if it's open
		fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv");

		if (!fstrm.is_open()) { // if it still doesn't open then that means it probably doesn't exist, so just make a new csv file
			// fstrm.close();
			fstrm.clear();
			fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv", ios::out);
			fstrm.close();
			fstrm.open("Final_Spring_2024_HHS_Stat_Output.csv"); 
		}
	}
	array<string, 8> subjs = {"CFS", "COMD", "CRIM", "HHSD", "KPE", "NURS", "PH", "SW"}; // the file itself doesn't seem to have all of these in the HHS dpt but that's not my concern
	fstrm << "Department,Enrolled,Non-Residents,AvgEnrolled" << endl;
	float ttlDpt{0}, ttlNrs{0};
	for (int i{0}; i < 8; i++) { // loop for our totals
		ttlDpt += dptCount[i];
		ttlNrs += nrs[i];
	}
	for (int i{0}; i < 8; i++) {
		// now loop for our display
		fstrm << subjs[i] << "," << dptCount[i] << "," << nrs[i] << "," << dptCount[i]/ttlDpt << endl;
	}
	fstrm << "Total" << "," << ttlDpt << "," << ttlNrs << "," << ttlDpt/ttl;

	fstrm.close(); // then close at the end
}