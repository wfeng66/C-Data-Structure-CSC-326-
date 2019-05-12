#pragma once
#include "lucky.h"

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
	while (current != last) {
		this->delCurr();
	}
}

template <class S>
void linkedlist<S>::initFile(string fname, int numD, int bPos)
{
	fstream inFile;
	S tvar;
	inFile.open(fname, ios::in);
	if (inFile.fail()) { // execption
		cout << "Openning fail!";
	}
	else
	{
		for (int t = 0; t < (bPos - 1); t++) inFile >> tvar; // positioningin file; using seekg() will cause misplace because the length of digital is inconsistent
			for (int i = 0; i < numD; i++) { // load data from file to 2 arrays
				if (!inFile.eof()) {
					inFile >> tvar;
					this->append(tvar);
				}
				else { // execption
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
void linkedlist<S>::printlist()
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
	if (current == first){			// the element is at the first
		first = current->next;
		current = first;
		current->prev = nullptr;
	}
	else if (current == last){		// the element is at the last
		last = current->prev;
		current = last;
		current->next = nullptr;
	}
	else
	{								// the element is in the middle
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->next;
	}
	count--;
	delete temp;
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
			if (current->info > current->next->info) {
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
		if (current->info == current->next->info) {
			this->delCurr();
			this->movebkwr(1);
		}
		this->movefwr(1);
	}
}

template <class S>
bool linkedlist<S>::search(int data)
{
	this->setTohead();
	while (1)
	{
		if (current->info == data) return true;			// find the element, return ture
		current = current->next;
		if (current == NULL)
			break;
	}
	return false;										// cannot find the element
}

template <class S>
bool linkedlist<S>::insert(int data)
{
	this->setTohead();
	if (data <= current->info) { // the value user inputed is less than the minimum of the list, the first node
		this->addnode(-1, data);
	}
	else if (data >= last->info) { // the value user inputed is greater than the maximum of the list, the last node
		this->addnode(1, data);
	}
	else {
		while (current != last) // the value user inputed is bettween the minimux and maximum of the list
		{
			if (current->info<data && current->next->info>data) this->addnode(0, data);
			current = current->next;
		}
	}
	return true;
}

template <class S>
void linkedlist<S>::addnode(int pos, int data)
{
	nodeType<S>* newNode;
	newNode = new nodeType<S>(data, nullptr, nullptr);
	if (pos == -1) { // add before the first node
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	else if (pos == 1) // add behind the last node
	{
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
	else if (pos == 0) // insert in the middle
	{
		newNode->prev = current;
		newNode->next = current->next;
		current->next = newNode;
		current->next->prev = newNode;
	}
	current = newNode;
	count++;
}

template <class S>
void perform(linkedlist<S>& mylist, int t) {
	int sdata;
	bool result;
	switch (t)
	{
	case 1:
		cout << "Please input the number you want to search: ";
		cin >> sdata;
		result = mylist.search(sdata);
		if (result == true) cout << "The list includes the number you inputed!\n";
		else cout << "The list does not include the number you inputed!\n";
		system("pause");
		break;
	case 2:
		cout << "Please input the number you want to insert: ";
		cin >> sdata;
		result = mylist.insert(sdata);
		if (result == true) cout << "Insert successfully!";
		else cout << "Insert fail!";
		break;
	case 3:
		cout << "Please input the number you want to delete: ";
		cin >> sdata;
		result = mylist.search(sdata);
		if (result == true) {
			mylist.delCurr();
			cout << "Delete successfully!!!";
		}
		else cout << "Sorry! The number you inputed does not exist in the list!";
		break;
	case 4:
		mylist.printlist();
		break;
	case 5:
		exit(0);
	default:
		break;
	}
}