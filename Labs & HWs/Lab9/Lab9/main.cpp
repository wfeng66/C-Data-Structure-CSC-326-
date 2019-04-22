#include "linkedlist.h"
#include "linkedlist.cpp"


int main()
{
	linkedlist<int> oriList;
	linkedlist<int> orderedList;
	int nD = 0, bP;
	string fName = "data.txt";			// file name of data source
	cout << "Welcome: \n\n";



	while (true) {			// run continually until user input -1
		cout << "Please input the number you want to sort (-1 means stop):  ";
		cin >> nD;
		if (nD == -1) break;
		cout << "\nAnd the begining position:  ";
		cin >> bP;
		oriList.initFile(fName, nD, bP);
		orderedList = oriList;
		oriList.print();
		cout << "-----------------------------------------------------------------------------------" << endl << endl;
		orderedList.sort();
		orderedList.print();
		orderedList.delduplicate();
		orderedList.print();
	}

	system("pause");

}

