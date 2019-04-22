#include "circularlist.h"

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


