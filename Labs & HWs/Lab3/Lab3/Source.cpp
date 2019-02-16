/*
LAB THREE - MODIFICATION to Lab #1
(1) Print EACH Student's Highest and Lowest Grade and the Associated Test Number

For example, GIVEN the Student's Grades are placed in order of the Tests, that is, the results for  Test 1 first, Test 2 second, etc.
Then for these GRADES: 87  78  99  100  34  56  78  89  77  93

Your search would evaluate:
(1) Student's Highest Grade was 100 received on Test 4 and   Student's Lowest Grade was 34 received on Test 5.
(2) Modularize the code functionality of the Program
(3) If the Student's Average was not also printed in the Original, Print it now
(4) All Other Output from Lab #1 will remain the Same.
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct SG {
	float arraySG[10];   // keep 10 grades
	float highGd, lowGd, aveGd;  // keep highest, lowest and average grade of specific students
	string name;
	char LG;
};


void init(SG[], string);    // load the data from file "grades.txt"
void grade(SG[]);   // calculate the highest, lowest, average grades and leter grades for each students
void output(SG[]);    // cout data in structure in format

void main()
{
	// Declare variables
	SG stud[10];


	ifstream myfile;

	// Initialize stud

	init(stud, "grades.txt");
	grade(stud);
	output(stud);

	system("pause");
}

// calculate the highest, lowest, average and letter grades
// input: student structure
// return: void
void grade(SG st[])
{
	bool coursesC[10];    // set the identifier of courses completation
	for (int i = 0; i < 10; i++) coursesC[i] = true;   // set the default value for each course
	// check each class for each student, if any class grade = 0 then set specific couses[i] as false
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (st[i].arraySG[j] == 0) coursesC[i] = false;

	for (int i = 0; i < 10; i++)
	{
		// initilate the highest, lowest and average grade members in student structures
		st[i].highGd = st[i].arraySG[0];
		st[i].lowGd = st[i].arraySG[0];
		st[i].aveGd = 0;
		// calculate the highest, lowest and average grade values in different students
		for (int j = 0; j < 10; j++)
		{
			if (st[i].highGd < st[i].arraySG[j])st[i].highGd = st[i].arraySG[j];
			if (st[i].lowGd > st[i].arraySG[j])st[i].lowGd = st[i].arraySG[j];
			st[i].aveGd += st[i].arraySG[j];
		}
		st[i].aveGd = st[i].aveGd / 10;
		// according to the average grades, assign the leter grades 
		if (coursesC[i] == true)
		{
			if (st[i].aveGd >= 90)
				st[i].LG = 'A';
			else if (st[i].aveGd >= 80)
				st[i].LG = 'B';
			else if (st[i].aveGd >= 70)
				st[i].LG = 'C';
			else if (st[i].aveGd >= 60)
				st[i].LG = 'D';
			else st[i].LG = 'F';
		}
		else
		{
			st[i].LG = 'W';
		}
	}


}

// load data from file 
// input: student structure and file name string which includes data
// return: void
void init(SG st[], string path)
{
	int i = 0;   // used to indicate which student
	string temp;
	ifstream infile;
	infile.open(path, ifstream::in);
	if (infile.is_open())       // check if the file is opened successfully
	{
		while (!infile.eof())     // load data until the end of file
		{
			getline(infile, st[i].name, ',');   // load the first element of each line, name of students
			// load each grades for each students
			for (int j = 0; j < 10; j++)
			{
				getline(infile, temp, ',');
				st[i].arraySG[j] = stof(temp);   // convert the string to float data type
			}
			i++;
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
}

// output formatly
// input: student structure
// return: void
void output(SG std[10])
{
	int name_width = 10;
	int grade_width = 8;
	int prec = 2;

	cout << setprecision(prec) << showpoint;
	cout << endl;
	cout << left << setw(name_width) << "Name";
	for (int k = 0; k < 10; k++) cout << left << setw(grade_width) << k + 1;
	cout << setw(grade_width) << "High" << setw(grade_width) << "Low" << setw(grade_width) << "Ave" << setw(grade_width) << "Grade" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(name_width) << std[i].name;
		for (int j = 0; j < 10; j++)
			cout << setw(grade_width) << fixed << std[i].arraySG[j];
		cout << setw(grade_width) << std[i].highGd << setw(grade_width) << std[i].lowGd << setw(grade_width) << std[i].aveGd;
		cout << setw(grade_width) << std[i].LG;
	}
}
