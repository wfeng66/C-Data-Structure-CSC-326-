/*
LAB TWO - Design and implement a program using ARRAYS in TANDEM/ PARALLEL
Lab 2
Design and implement a program that DOES NOT use the structure (SG) to perform the same tasks as you accomplished in Lab #1.
This will require that you use ARRAYS in TANDEM/ PARALLEL. You will need to use at least THREE ARRAYS to accomplish this, i.e., a one two-dimensional array, one that is a string data-type to contain the NAME, one that is char to contain the LG /Letter Grade.
Once you determine what the Student's AVG is based on the average of the ten grades.  Each ROW of the TWO DIMENSIONAL ARRAY will contain TEN GRADES FOR EACH STUDENT.
THE RELATIONSHIP BETWEEN THE Student's Names and Letter Grades is positionally the same and RELATED TO THE ELEMENTS IN THE TWO-DIMENSIONAL ARRAY by the ROW.
FOR EXAMPLE, the Student whose Name is at location zero in the NAME array, is associated/linked to the Letter Grade in the zero-position of the LG Array and to the ZERO ROW of the TWO-DIMENSIONAL ARRAY.

GIVEN these declarations:
string NAME [10];
float GRADES [10][10];
char LG[10];

The Program should:
(Input) Read each of the Students' Names  from a FILE,  i.e., Name AND the 10 grades for each Student, into the TWO-DIMENSIONAL ARRAY, GRADES.
THEN, calculates the average grades from which a LETTER GRADE is determined and store that grade in LG array.
If the Student has less than 10 grades, then the Student should get a "W" grade when any GRADE IS A ZERO.
(Output)  Each STUDENT's NAME, the 10 grades, and the given Letter-Grade (LG) neatly formatted in a tabular form.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

float avg(float arr[][10], int);		// calculate average value of inputed array
void init(string, string[10], float[10][10]);		// load the data from file "grades.txt"
void grade(float[10][10], char[10]);		// calculate the letter grades for each students
void output(string[10], float[10][10], char[10]);		// cout data in format


int main()
{
	// Declare variables
	string stNames[10];
	float stGrades[10][10];
	char stLG[10];

	// Initialize stud
	init("grades.txt", stNames, stGrades);
	grade(stGrades, stLG);
	output(stNames, stGrades, stLG);
	system("pause");

	return 0;
}

// calculate the average value of inputed array
// input: array storing students' grades and i which represents particular student 
// return: the average grade of that student
float avg(float arr[][10], int i)
{
	float sum = 0, result;
	for (int k = 0; k < 10; k++) sum += arr[i][k];
	result = sum / 10;
	return result;
}

// calculate the letter grades
// input: students' grades array and letter grades array
// return: void
void grade(float gd[][10], char lg[])
{
	bool coursesC[10];    // set the identifier of courses completation
	for (int i = 0; i < 10; i++) coursesC[i] = true;		// set the default value for each course
	// check each class for each student, if any class grade = 0 then set specific couses[i] as false
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (gd[i][j] == 0) coursesC[i] = false;
	// according to the average grades, assign the leter grades 
	for (int i = 0; i < 10; i++)
	{
		if (coursesC[i] == true)
		{
			if (avg(gd, i) >= 90)
				lg[i] = 'A';
			else if (avg(gd, i) >= 80)
				lg[i] = 'B';
			else if (avg(gd, i) >= 70)
				lg[i] = 'C';
			else if (avg(gd, i) >= 60)
				lg[i] = 'D';
			else lg[i] = 'F';
		}
		else
		{
			lg[i] = 'W';
		}
	}
}

// load data from file 
// input: student structure and file name string which includes data
// return: void
void init(string path, string na[10], float gd[10][10])
{
	int i = 0;		// used to indicate which student
	string temp;
	ifstream infile;
	infile.open(path, ifstream::in);
	if (infile.is_open())		// check if the file is opened successfully
	{
		while (!infile.eof())		// load data until the end of file
		{
			getline(infile, na[i], ',');		// load the first element of each line, name of students
			// load each grades for each students
			for (int j = 0; j < 10; j++)
			{
				getline(infile, temp, ',');
				gd[i][j] = stof(temp);		// convert the string to float data type
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
// input: students' name array, grades array and letter grades array
// return: void
void output(string na[10], float gd[10][10], char lg[10])
{
	int name_width = 13;
	int grade_width = 8;
	int prec = 2;

	cout << setprecision(prec) << showpoint;
	cout << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(name_width) << na[i];
		for (int j = 0; j < 10; j++)
			cout << setw(grade_width) << fixed << gd[i][j];
		cout << setw(grade_width) << lg[i];
	}
	cout << endl;
}
