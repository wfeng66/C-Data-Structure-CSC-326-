#pragma once
#ifndef SORTARR_H
#define SORTARR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class arr
{
public:
	arr();						// default constructor
	arr(string, int, int);		// the second constructor
	~arr();						// destructor; delete 2 arrays and close file
	void sort();				// sort the array which is saved in sortedArr
	void print();				// print out the result
private:
	fstream inFile;				// input from source data file
	int *sortedArr;				// used for sorting		
	int *originalArr;			// used for keeping the original data read from file, without sorting
	int numElements;			// the number of elements in array
};

#endif