#include "linkedlist.h"


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
	this->setTohead();
	while (current != last){
		this->delCurr();
	}
}

template <class S>
void linkedlist<S>::initFile(string fname, int numD, int bPos)
{
	fstream inFile;
	S tvar;
	inFile.open(fname, ios::in);

	if (inFile.fail()) {					// execption
		cout << "Openning fail!";
	}
	else
	{
		for (int t = 0; t < (bPos - 1); t++) inFile >> tvar;		// positioning in file; using seekg() will cause misplace because the length of digital is inconsistent
		for (int i = 0; i < numD; i++) {						// load data from file to 2 arrays
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
	if (first == nullptr)
	{
		newNode = new nodeType<S>(data);
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		newNode = new nodeType<S>(data, last, nullptr);
		current = newNode;
		last->next = newNode;
		last = newNode;
		count++;
	}
}

template <class S>
void linkedlist<S>::print()
{

	current = first;
	cout << "prev\tinfo\tnext" << endl;

	while (current != nullptr)
	{
		cout << current->prev << "\t" << current->info << "\t" << current->next << "\t" << count << endl;
		current = current->next;
	}
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
	for (int i = 0; i < num; i++)
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
	count--;
}

template <class S>
void linkedlist<S>::swap(nodeType<S>* node1, nodeType<S>* node2)
{
	int temp = node1->info;
	node1->info = node2->info;
	node2->info = temp;
}


template <class S>
void linkedlist<S>::sort()
{
	for (int i = 0; i < count; i++) {
		this->setTohead();
		while (current != last) {
			if (current->info > current->next->info){
				swap(current, current->next);
			}
			this->movefwr(1);
		}
	}
}

template <class S>
void linkedlist<S>::delduplicate()
{
	this->setTohead();
	while (current != last) {
		if (current->info == current->next->info){
			this->delCurr();
			this->movebkwr(1);
		}
		this->movefwr(1);
	}
}