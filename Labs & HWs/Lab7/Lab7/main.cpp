#include "sortarr.h"

int main()
{
	string fName;
	int nD = 0, bP = 0;
	arr* myArr;

	fName = "data.txt";			// file name of data source

	while (nD != -1) {			// run continually until user input -1
		cout << "Please input the number you want to sort (-1 means stop):  ";
		cin >> nD;
		cout << "\nAnd the begining position:  ";
		cin >> bP;
		myArr = new arr(fName, nD, bP);			// new object by user inputing
		myArr->sort();
		myArr->clear();
		myArr->print();
		cout << "-----------------------------------------------------------------------------------" << endl << endl;
	}



	system("pause");
}
