/*LAB SIX - DYNAMIC ALLOCATION and SORTING

INPUT :
(1) READ IN THE SIZE OF THE ARRAY THAT YOU WANT from the CONSOLE.
(2) READ IN THE CONTENTS OF THE ARRAY from a FILE

WHAT SHOULD IT DO ?
THIS PROGRAM SHOULD BE ABLE to  DYNAMICALLY  ALLOCATE an ARRAY the  SIZE requested, and then, SORT in ASCENDING ORDER.
Note : YOU MAY USE A SECOND ARRAY TO STORE and REORDER DATA.

   OUTPUT :
		  (1) The ORIGINAL ARRAY
		  (2) The Sorted Array                                               */


#include "sortarr.h"

int main()
{
	string fName;
	int nD = 0,bP=0;
	arr* myArr;

	fName = "data.txt";			// file name of data source

	while (nD != -1) {			// run continually until user input -1
		cout << "Please input the number you want to sort (-1 means stop):  ";
		cin >> nD;
		cout << "\nAnd the begining position:  ";
		cin >> bP;
		myArr = new arr(fName, nD,bP);			// new object by user inputing
		myArr->sort();
		myArr->print();
		cout << "-----------------------------------------------------------------------------------" << endl<<endl;
	}



	system("pause");
}





