#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class S>
struct nodeType
{
	S info;
	nodeType *link;
};

template <class S>
class linkedlist {
public:
	linkedlist();
	~linkedlist();
	bool isEmpty();
	bool isFull();
	void initConsole();
	void initFile(string, int, int);		// initializate the list from existing file, first int is the numbers of elements need to load, second int is the beginning position in the file
	void append(nodeType<S>*);					// append the newnode to the end of the list
	void del(nodeType<S>*);						// delete de
	void insert(nodeType<S>*, nodeType<S>*);      // first parameter is the ptr of newnode, the second is the ptr of position you are going to put the newnode at it
	int length();
	void print();
	void movefwr();
	void movebkwr();
	void swap(nodeType<S>*, nodeType<S>*);
private:
	int count;
	nodeType<S> *current;
	nodeType<S> *first;
	nodeType<S> *last;
};


int main()
{
	linkedlist<int> oriList;
	linkedlist<int> orderedList;
	int nD = 0, bP;
	string fName = "data.txt";			// file name of data source
	cout << "Welcome: \n\n";



	while (nD != -1) {			// run continually until user input -1
		cout << "Please input the number you want to sort (-1 means stop):  ";
		cin >> nD;
		cout << "\nAnd the begining position:  ";
		cin >> bP;
		oriList.initFile(fName, nD, bP);
		orderedList = oriList;
		oriList.print();
		//myArr->sort();
		//myArr->clear();
		//myArr->print();
		cout << "-----------------------------------------------------------------------------------" << endl << endl;
	}



	system("pause");

}



template <class S>
linkedlist<S>::linkedlist()
{
	current = nullptr;
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class S>
linkedlist<S>::~linkedlist()
{
}

template <class S>
void linkedlist<S>::initFile(string fname, int numD, int bPos)
{
	fstream inFile;
	S tvar;
	nodeType<S>* temp;
	inFile.open(fname, ios::in);

	temp = new nodeType<S>;
	temp->link = nullptr;
	if (inFile.fail()) {					// execption
		cout << "Openning fail!";
	}
	else
	{
		for (int t = 0; t < (bPos - 1); t++) inFile >> tvar;		// positioning in file; using seekg() will cause misplace because the length of digital is inconsistent
		for (int i = 0; i < numD; i++) {						// load data from file to 2 arrays
			if (!inFile.eof()) {
				// inFile >> *(originalArr + i);
				inFile >> temp->info;
				cout << temp->info<<"\t";
				this->append(temp);
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
bool linkedlist<S>::isFull()
{
	return(current->link == last);
}

template <class S>
void linkedlist<S>::append(nodeType<S>* newNode)
{
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		last->link = newNode;
		last = newNode;
		count++;
	}
}

template <class S>
void linkedlist<S>::print()
{
	current = first;
	while (current != nullptr)
	{
		cout << current->info << "\t";
		current = current->link;
	}
}