#include "sortarr.h"

arr::arr() {}

// the second constructor: initilizing the arrays, including read data from file
// input: filename - the string of file name that includes source data; numD - the number of digits need to read from file, 
//        that is indicated by user from console; bPos - the begining position of file where begin to read data, that is indicated by user from console; bPos
// return: none
// output: inilizing 2 arrays
arr::arr(string filename, int numD, int bPos)
{
	int temp;
	originalArr = new int[numD];
	sortedArr = new int[numD];

	numElements = numD;
	size = numD;
	inFile.open(filename, ios::in);
	if (inFile.fail()) {					// execption
		cout << "Openning fail!";
	}
	else
	{
		for (int t = 0; t < (bPos - 1); t++)inFile >> temp;		// positioning in file; using seekg() will cause misplace because the length of digital is inconsistent
		for (int i = 0; i < numD; i++) {						// load data from file to 2 arrays
			if (!inFile.eof()) {
				inFile >> *(originalArr + i);
				*(sortedArr + i) = *(originalArr + i);
			}
			else {							// execption
				cout << "Data reading reached the end of the file, and stopped!";
			}
		}
	}
}

// destructor: release resources
// input: none
// return: none
// output: release 2 arrays, close file
arr::~arr() {
	delete[] originalArr;
	delete[] sortedArr;
	inFile.close();
}

// sort: sort the array, sortedArr 
// input: none
// return: none
// output: unsorted array was sorted
// algorithm: insertion sort
void arr::sort()
{
	int key, j;
	for (int i = 1; i < size; i++) {					// go through the array
		key = *(sortedArr + i);								// set the key
		j = i - 1;
		while (j >= 0 && *(sortedArr + j) > key) {			// find the right position for key in sorted subarray 
			*(sortedArr + (j + 1)) = *(sortedArr + j);
			j--;											// move from right to left in sorted subarray
		}
		*(sortedArr + (j + 1)) = key;						// insert key 
	}
}

// print: output the result 
// input: none
// return: none
// output: cout original array and sorted array
void arr::print()
{
	cout << "\nThe original array is:\n";
	for (int i = 0; i < size; i++) {
		cout << originalArr[i] << "\t";
		if (i != 0 && (i + 1) % 10 == 0) cout << "\n";		// output 10 digits per line
	}
	cout << "\n";
	cout << "The sorted array is: \n";
	for (int i = 0; i < numElements; i++) {
		cout << sortedArr[i] << "\t";
		if (i != 0 && (i + 1) % 10 == 0) cout << "\n";		// output 10 digits per line
	}
	cout << "\n";
}

// clear: find the repeated element in sortedArr, and get rid of it, making sure unique element in sortedArr
// input: none
// return: none
// output: all of the emlements in sortedArr become unique
void arr::clear()
{
	int prev = *sortedArr;
	for (int i = 1; i < numElements; i++)
	{
		if (*(sortedArr + i) == prev) {
			this->delrepe(i);
			i--;
		}
		else prev = *(sortedArr + i);
	}
}

// delrepe: delete the repeated elements, and move subsequent elements forward
// input: the position of repeated element need to remove
// return: none
// output: remove the element which is specific in parameter
void arr::delrepe(int pos)
{
	for (int i = pos; i < numElements - 1; i++)
	{
		*(sortedArr + i) = *(sortedArr + i + 1);
	}
	numElements--;
}

