/*
LAB 4
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

class SG
{
public:
	SG();
	~SG();
	void load(ifstream&);
	void grade();
	void print();

private:
	float arraySG[10];   // keep 10 grades
	float highGd, lowGd, aveGd;  // keep highest, lowest and average grade of specific students
	string name;
	char LG;
};

SG::SG()
{
}

SG::~SG()
{
} 


// load data from file to SG's member, arraySG[10]
// input: ifstream object, which is file include data
// return: void
void SG::load(ifstream &infile)
{
	string temp;
	getline(infile, name, ',');   // load the first element of each line, name of students
	// load each grades for each students
	for (int j = 0; j < 10; j++)
	{
		getline(infile, temp, ',');
		arraySG[j] = stof(temp);   // convert the string to float data type
	}
}

// calculate the highest, lowest, average and letter grades
// input: noon
// return: void
void SG::grade()
{
	bool coursesC=true;    // set the identifier of courses completation

		// initilate the highest, lowest and average grade members in student structures
		highGd = arraySG[0];
		lowGd = arraySG[0];
		aveGd = 0;
		// calculate the highest, lowest and average grade values in different students
		for (int j = 0; j < 10; j++)
		{
			if (highGd < arraySG[j])highGd = arraySG[j];
			if (lowGd > arraySG[j])lowGd = arraySG[j];
			aveGd += arraySG[j];
			if (arraySG[j] == 0) coursesC = false;
		}
		aveGd = aveGd / 10;
		// according to the average grades, assign the leter grades 
		if (coursesC == true)
		{
			if (aveGd >= 90)
				LG = 'A';
			else if (aveGd >= 80)
				LG = 'B';
			else if (aveGd >= 70)
				LG = 'C';
			else if (aveGd >= 60)
				LG = 'D';
			else LG = 'F';
		}
		else
		{
			LG = 'W';
		}
}


// output formatly
// input: noon
// return: void
void SG::print()
{
	int name_width = 10;
	int grade_width = 8;

	cout << left << setw(name_width) << name;
	for (int j = 0; j < 10; j++)
		cout << setw(grade_width) << fixed << arraySG[j];
	cout << setw(grade_width) << highGd << setw(grade_width) << lowGd << setw(grade_width) << aveGd;
	cout << setw(grade_width) << LG;
}

void main()
{
	// Declare variables
	SG* stud = new SG[10];
	int i = 0;		// used to control which student
	int name_width = 10;
	int grade_width = 8;
	int prec = 2;
	const string path = "grades.txt";

	ifstream myfile;

	// Initialize stud
	cout << setprecision(prec) << showpoint;
	cout << endl;
	cout << left << setw(name_width) << "Name";
	for (int k = 0; k < 10; k++) cout << left << setw(grade_width) << k + 1;
	cout << setw(grade_width) << "High" << setw(grade_width) << "Low" << setw(grade_width) << "Ave" << setw(grade_width) << "Grade" << endl << endl;
	myfile.open(path, ifstream::in);
	if (myfile.is_open())       // check if the file is opened successfully
	{
		while (!myfile.eof())     // load data until the end of file
		{
			stud[i].load(myfile);
			stud[i].grade();
			stud[i].print();
			i++;
		}
		myfile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	system("pause");
}

