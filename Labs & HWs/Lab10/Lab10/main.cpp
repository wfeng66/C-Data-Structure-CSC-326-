#include <iostream>
#include<stdio.h> 
#include<stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

template <class S>
struct nodeType
{
	S name;											// used to store patient name
	S diagnosis;									// used to store diagnosis result responding to the patient
	nodeType<S>* next;								// used to store the address of next nodes

	nodeType() { next = nullptr; }
	nodeType(const S d, nodeType<S>* nxt = nullptr) :name(d), next(nxt) {}
};

template <class S>
class linkedlist {
public:
	linkedlist();
	// defaul constructor, create a null linked list
	linkedlist(string fname, int len);
	// constructor
	// input: fname - string which stores the file name that includes patient name, len - integer number that indicates how many patient names should be loaded
	// result: initialize the circular list with designated number of patients names
	~linkedlist();
	// destructor, delete linked list
	bool isEmpty();
	// check if the list is empty
	// input: none
	// output: bool, return ture if the list is empty, else return false
	void initFile(string, int);
	// initializate the list from existing file, 
	// input: first int is the numbers of elements need to load, second int is the beginning position in the file	
	// output: void
	void append(S);
	// append the newnode to the end of the list
	// input: the value want to be append
	// output: void
	void delCurr();
	// delete current element
	// input: no
	// output: void
	void print();
	// print the circular list of that object
	// input: no
	// output: void
	void setTohead();
	// set the current point to the head of the list
	// input: no
	// output: void
	void setTotail();
	// set the current point to the tail of the list
	// input: no
	// output: void
	void movefwr(int);
	// set the current point forward number of elements
	// input: the number of elements you want to move forward
	// output: void
	void movebkwr(int);
	// set the current point backward number of elements
	// input: the number of elements you want to move backward
	// output: void
	void printCurr();
	// print out the data of element is pointed by current
	// input: no
	// output: void
	void setDiag(string);
	// set the value of diagnosis
	// input: string of the name of diagnosis that should be setted to diagnosis
	// output: no
	S getCurrname();
	// get the name of current patient
	// input: no
	// output: return the string storing the name of current patient
	int getCount();
	// get the total number of elements in the circular link
	// input: no
	// output: integer number that the total number of elements in the link

private:
	int count;
	nodeType<S> *current;
	nodeType<S> *last;
};

string diagnosis[] =
{
	"Influenza",
	"Cold",
	"Enterogastritis",
	"Pneumonia",
	"Arthritis"
};

int main()
{
	int nD = 10, bP, selected = 0, num = 0, diagsele = -1, begin = 1;
	string fName = "patients.txt";			// file name of data source	
	string diag;
	srand(time(NULL));
	linkedlist<string> waitinglist(fName, nD);
	linkedlist<string> results;
	waitinglist.setTohead();
	cout << "Welcome: \n\n";
	while (true)
	{
		cout << "\nWhat do you want to do?: " << endl;
		cout << "1. Next\t2. Diagnosis\t3. End" << endl;
		cin >> selected;
		switch (selected)
		{
		case 1:
			if (begin == 1){
				cout << "\nIt is turn for ";
				waitinglist.printCurr();
				cout << " ! " << endl;
				begin = 0;
			}
			else{
				waitinglist.delCurr();
				waitinglist.initFile(fName, 1);
				cout << "\nIt is turn for ";
				waitinglist.printCurr();
				cout << " ! " << endl;
			}
			break;
		case 2:
			cout << "Please select your diagnosis: \n";
			for (int i = 0; i < 5; i++) cout <<"\t"<<i<<" "<< diagnosis[i] << endl;
			cin >> diagsele;
			diag = diagnosis[diagsele];
			cout << "The diagnosis of ";
			waitinglist.printCurr();
			cout << " is: " << diagnosis[diagsele] <<endl;
			results.append(waitinglist.getCurrname());
			results.setDiag(diag);
			break;
		case 3:
			cout << "The work of today is end!!!";
			results.print();
			break;
		default:
			break;
		}
		if (selected == 3) break;
	}


	system("pause");

}


template <class S>
linkedlist<S>::linkedlist()
{
	current = nullptr;
	last = nullptr;
	count = 0;
}

template <class S>
linkedlist<S>::linkedlist(string fname, int len)
{
	current = nullptr;
	last = nullptr;
	count = 0;
	initFile(fname, len);
}

template <class S>
linkedlist<S>::~linkedlist()
{
	this->setTohead();
	while (current != last){
		this->delCurr();
	}
}


template <class S>
void linkedlist<S>::initFile(string fname, int numD)
{
	fstream inFile;
	S tvar;
	inFile.open(fname, ios::in);
	int bPos;

	if (inFile.fail()) {					// execption
		cout << "Openning fail!";
	}
	else
	{

		for (int i = 0; i < numD; i++) {						// load data from file 
			bPos = rand() % 200;
			for (int t = 0; t < (bPos - 1); t++) inFile >> tvar;		// positioning in file; using seekg() will cause misplace because the length of digital is inconsistent
			if (!inFile.eof()) {
				inFile >> tvar;
				this->append(tvar);
			}
			else {							// execption
				cout << "Data reading reached the end of the file, and stopped!";
			}
		}
	}

}

template <class S>
bool linkedlist<S>::isEmpty()
{
	return(first == nullptr);
}

template <class S>
void linkedlist<S>::append(S data)
{
	nodeType<S>* newNode;
	nodeType<S>* temp;
	if (last == nullptr)
	{
		newNode = new nodeType<S>(data);
		last = newNode;
		newNode->next = newNode;
		current = last;
		count++;
	}
	else
	{
		newNode = new nodeType<S>(data, last->next);
		temp = last->next;
		current = newNode;
		last->next = newNode;
		last = newNode;
		last->next = temp;
		count++;
	}
}


template <class S>
void linkedlist<S>::print()
{
	this->setTohead();
	cout << "\nPatient Name\tDiagnosis" << endl;
	cout << "---------------------------------" << endl;

	while (current != last)
	{
		cout << current->name << "\t" << current->diagnosis << endl;
		current = current->next;
	}
	cout << current->name << "\t" << current->diagnosis << endl;
	this->setTohead();
}


template <class S>
void linkedlist<S>::setTohead()
{
	current = last->next;
}

template <class S>
void linkedlist<S>::setTotail()
{
	current = last;
}

template <class S>
void linkedlist<S>::movebkwr(int num)
{
	for (int i = 0; i < (count - num); i++)
		current = current->next;
}

template <class S>
void linkedlist<S>::movefwr(int num)
{
	for (int i = 0; i < num; i++)
		current = current->next;
}

template <class S>
void linkedlist<S>::printCurr()
{
	cout << current->name;
}

template <class S>
void linkedlist<S>::delCurr()
{
	nodeType<S>* temp = current;
	last->next = current->next;
	current = last->next;
	delete temp;
	count--;
}

template <class S>
void linkedlist<S>::setDiag(string d)
{
	current->diagnosis = d;
}

template <class S>
S linkedlist<S>::getCurrname()
{
	return current->name;
}

template <class S>
int linkedlist<S>::getCount()
{
	return count;
}


