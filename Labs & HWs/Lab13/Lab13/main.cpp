// This program creates a double linked list which laods 10 numbers randomly from .txt file include 1000 integers.
// Then, sort it. 
// Users can display the list, search number, insert number, or delete number in the list.
#include "lucky.h"
#include "lucky.cpp"

int main()
{
	linkedlist<int> myList;
	//linkedlist<int> orderedList;
	int nD = 10, bP, task;
	string fName = "data.txt"; // file name of data source
	cout << "Welcome: \n\n";
	srand(time(NULL));
	bP = rand() % 800;
	myList.initFile(fName, nD, bP);
	myList.sort();
	while (true) { // run continually until user input -1
		//if (nD == -1) break;
		
		//printmenu();
		//system("cls");
		cout << "\n\nWelcom!\n\n";
		cout << "Please select the option: \n";
		cout << "\n1. Search a number;";
		cout << "\n2. Insert a number;";
		cout << "\n3. Delete a number;";
		cout << "\n4. Print the list;";
		cout << "\n5. Quit;\n";
		cin >> task;
		perform(myList, task);
	}
	system("pause");
}