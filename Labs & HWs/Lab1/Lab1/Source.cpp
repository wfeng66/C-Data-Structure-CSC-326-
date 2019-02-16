/*LAB ONE
Lab 1 you should design and implement a program that uses the structure below, (SG) and allocates an ARRAY OF 10 ELEMENTS/ STRUCTURES to contain the information.

Struct SG
{float arraySG[10];
string name;
char LG;
};

The Program should:
(Input) Read each of the Students' Names into the Structure from a FILE,  i.e., Name and 10 grades for each Student,
THEN, calculates the average grades from which a LETTER GRADE is determined and stores that grade in LG.
If the Student has less than 10 grades, then the Student should get a "W" grade.
( Output)  Each Name's Name, the 10 grades, and the given Letter-Grade neatly formatted in a tabular form.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct SG {
	float arraySG[10];		// keep 10 grades
	string name;
	char LG;
};

float avg(float arr[]);
void init(SG[], string);
void grade(SG[]);
void output(SG[]);

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

// calculate the average value for input array
// input: float array
// return: float value, the average
float avg(float arr[])
{
	float sum = 0, result;
	for (int k = 0; k < 10; k++) sum += arr[k];
	result = sum / 10;
	return result;
}


// calculate the letter grades for each students
// input: student structure
// return: void
void grade(SG st[])
{
	bool coursesC[10];    // set the identifier of courses completation
	for (int i = 0; i < 10; i++) coursesC[i] = true;     // set the default value for each course
	// check each classes for each students, if any class grade = 0 then set specific couses[i] as false
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (st[i].arraySG[j] == 0) coursesC[i] = false;
	// according to the average grade, assign the leter grades 
	for (int i = 0; i < 10; i++)
	{
		if (coursesC[i] == true)
		{
			if (avg(st[i].arraySG) >= 90)
				st[i].LG = 'A';
			else if (avg(st[i].arraySG) >= 80)
				st[i].LG = 'B';
			else if (avg(st[i].arraySG) >= 70)
				st[i].LG = 'C';
			else if (avg(st[i].arraySG) >= 60)
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
	int i = 0;		// used to indicate which student
	string temp;
	ifstream infile;
	infile.open(path, ifstream::in);
	if (infile.is_open())		// check if the file is opened sucessfully
	{
		while (!infile.eof())		// load data until the end of file
		{
			getline(infile, st[i].name, ',');		// load the first element of each line, name of students
			// load each grades for each students
			for (int j = 0; j < 10; j++)
			{
				getline(infile, temp, ',');
				st[i].arraySG[j] = stof(temp);		// convert the string to float data type

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
	int name_width = 13;
	int grade_width = 8;
	int prec = 2;

	cout << setprecision(prec) << showpoint;
	cout << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(name_width) << std[i].name;
		for (int j = 0; j < 10; j++)
			cout << setw(grade_width) << fixed << std[i].arraySG[j];
		cout << setw(grade_width) << std[i].LG << endl;
	}
	cout << endl;
}
