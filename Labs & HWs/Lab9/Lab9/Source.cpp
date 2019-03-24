#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class S>
struct nodeType
{
	S info;
	nodeType<S>* prev;
	nodeType<S>* next;

	nodeType() { next = prev = nullptr; }
	nodeType(const S d, nodeType<S>* prv = nullptr, nodeType<S>* nxt = nullptr) :info(d), next(nxt), prev(prv){}
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
	//void append(nodeType<S>*);					// append the newnode to the end of the list
	void append(S);
	void delCurr();						// delete current element
	void insert(nodeType<S>*, nodeType<S>*);      // first parameter is the ptr of newnode, the second is the ptr of position you are going to put the newnode at it
	void print();
	void setTohead();
	void setTotail();
	void movefwr(int);
	void movebkwr(int);
	void printCurr();
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
		oriList.setTohead();
		oriList.movefwr(2);
		oriList.delCurr();
		oriList.print();
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
	//nodeType<S>* temp;
	inFile.open(fname, ios::in);

	//temp = new nodeType<S>;
	//temp->next = nullptr;
	if (inFile.fail()) {					// execption
		cout << "Openning fail!";
	}
	else
	{
		for (int t = 0; t < (bPos - 1); t++) inFile >> tvar;		// positioning in file; using seekg() will cause misplace because the length of digital is inconsistent
		for (int i = 0; i < numD; i++) {						// load data from file to 2 arrays
			if (!inFile.eof()) {
				//inFile >> temp->info;
				//this->append(temp);
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
bool linkedlist<S>::isFull()
{
	return(current->next == last);
}

template <class S>
void linkedlist<S>::append(S data)
{
	//cout << "info: " << newNode->info <<"\t"<< "link: " << newNode->next << "\n";
	/*newNode->next = nullptr;
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		cout << first->info<<"\n";
		count++;
	}
	else
	{
		last->next = newNode;
		last = newNode;
		cout << first->info << "\t" << last->info << "\n";
		count++;
	}*/
	nodeType<S>* newNode;
	//newNode = new nodeType<S>;
	//newNode->info = data;
	//newNode->next = nullptr;
	if (first == nullptr)
	{
		//nodeType<S> newNode(data);
		newNode = new nodeType<S>(data);
		first = newNode;
		last = newNode;
		cout << first->info << "\n";
		count++;
	}
	else
	{
		//nodeType<S> newNode(data,current,nullptr);
		newNode = new nodeType<S>(data, current, nullptr);
		current = newNode;
		last->next = newNode;
		last = newNode;
		cout << first->info << "\t" << last->info << "\n";
		count++;
	}
}

template <class S>
void linkedlist<S>::print()
{

	current = first;
	//cout << current->info;
	

		while (current != nullptr)
		{
		cout << current->info << "\t";
		current = current->next;
		}
		cout << "\n"<< current;
		

}

template <class S>
void linkedlist<S>::setTohead()
{
	current = first;
}

template <class S>
void linkedlist<S>::setTotail()
{
	current = last;
}


template <class S>
void linkedlist<S>::movebkwr(int num)
{
	for (int i = 0; i < num;i++)
		current = current->prev;
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
	cout << current->info;
}

template <class S>
void linkedlist<S>::delCurr()
{
	nodeType<S>* temp = current;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current = current->next;
}