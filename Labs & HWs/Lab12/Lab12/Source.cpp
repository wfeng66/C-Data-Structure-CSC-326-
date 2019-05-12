#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *prev;
	nodeType<Type> *next;

	nodeType() { next = prev = nullptr; }
	nodeType(const Type d, nodeType<Type>* prv = nullptr, nodeType<Type>* nxt = nullptr) :info(d), next(nxt), prev(prv) {}
};


template <class Type>
class stackADT {
public:
	stackADT();
	// Default constructor, do nothing
	// no input, no output
	stackADT(int);
	// Constructor, invokes initializeStack
	// no input, no output
	~stackADT();
	// Destructor, release item array
	// no input, no output
	void initializeStack(int);
	// Initialize empty array, dynamically creates empty stack that includes specified number of elements, size is setted as the number of input, topitem is setted as 0
	// input: integer of the number of elements 
	// output: no
	bool isEmptyStack();
	// Determines if the stack is empty
	// input: no
	// output: if the stack is empty, return ture; otherwise, return false
	bool isFullStack();
	// Determines if the stack is full
	// input: no
	// output: if the stack is full, return ture; otherwise, return false
	void push(Type);
	// Add new element into stack
	// input: the value of the element need to be add into stack
	// precondition: the stack is not full
	// output: no
	Type top();
	// Get the value of the top element in the stack
	// input: no
	// precondition: the stack is not empty
	// output: the value of the top element
	void pop();
	// Remove the top element from the stack
	// input: no
	// output: no
	// precondition: the stack is not empty
private:
	nodeType<Type> *bottomitem;
	nodeType<Type> *topitem;
	int count;
	int size;
};

void main()
{
	stackADT<int> mystack(5);
	int indata;
	if (mystack.isEmptyStack()) cout << "The stack is empty!" << endl;
	while (!mystack.isFullStack())
	{
		cout << "\nPlease enter the elements: ";
		cin >> indata;
		mystack.push(indata);
	}

	if (mystack.isFullStack()) cout << "\nThe stack is full." << endl;

	while (!mystack.isEmptyStack())
	{
		cout << mystack.top() << endl;
		mystack.pop();
	}
	if (mystack.isEmptyStack()) cout << "\nThe stack is empty." << endl;

	system("pause");
}

template < class Type>
stackADT<Type>::stackADT()
{
	bottomitem = nullptr;
	topitem = nullptr;
	size = 0;
	count = 0;
}

template < class Type>
stackADT<Type>::stackADT(int num)
{
	this->initializeStack(num);
}

template < class Type>
stackADT<Type>::~stackADT()
{
	while (!this->isEmptyStack())
	{
		this->pop();
	}
}

template < class Type>
bool stackADT<Type>::isEmptyStack()
{
	if (count == 0) return true;
	else return false;
}

template < class Type>
bool stackADT<Type>::isFullStack()
{
	if (count == size) return true;
	else return false;
}



template < class Type>
Type stackADT<Type>::top()
{
	if (this->isEmptyStack()) {
		cout << "The stack is empty!" << endl;
	}
	else
	{
		return topitem->info;
	}
}

template < class Type>
void stackADT<Type>::pop()
{
	if (this->isEmptyStack()) {
		cout << "The stack is empty, pop operation fail!" << endl;
	}
	else
	{
		if (count == 1) {
			nodeType<Type>* temp = topitem;
			topitem = nullptr;
			delete temp;
			count--;
			cout << "Pop successfully!" << endl;
		}
		else {
			nodeType<Type>* temp = topitem;
			topitem = topitem->prev;
			topitem->next = nullptr;
			delete temp;
			count--;
			cout << "Pop successfully!" << endl;
		}

	}
}


template < class Type>
void stackADT<Type>::initializeStack(int num)
{
	size = num;
	count = 0;
	bottomitem = nullptr;
	topitem = nullptr;
}


template <class Type>
void stackADT<Type>::push(Type data)
{
	if (this->isFullStack()) {
		cout << "The stack is full, push fail!" << endl;
	}
	else {
		nodeType<Type>* newNode;
		if (this->isEmptyStack())
		{
			newNode = new nodeType<Type>(data);
			topitem = newNode;
			bottomitem = newNode;
			count++;
		}
		else
		{
			newNode = new nodeType<Type>(data, topitem, nullptr);
			topitem->next = newNode;
			topitem = newNode;
			count++;
		}
		cout << "Push successfully!" << endl;
	}
}
