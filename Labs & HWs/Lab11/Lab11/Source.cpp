#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

template <class Type>
class stackADT{
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
	Type* item;
	int size;
	int topitem;
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
}

template < class Type>
stackADT<Type>::stackADT(int num)
{
	this->initializeStack(num);
}

template < class Type>
stackADT<Type>::~stackADT()
{
	delete[] item;
}

template < class Type>
bool stackADT<Type>::isEmptyStack()
{
	if (topitem == 0) return true;
	else return false;
}

template < class Type>
bool stackADT<Type>::isFullStack()
{
	if (topitem == size) return true;
	else return false;
}

template < class Type>
void stackADT<Type>::push(Type data)
{
	if (this->isFullStack()){
		cout << "The stack is full, push fail!"<<endl;
	}
	else{
		*(item + topitem) = data;
		topitem++;
		cout << "Push successfully!" << endl;
	}
}

template < class Type>
Type stackADT<Type>::top()
{
	if (this->isEmptyStack()){
		cout << "The stack is empty!" << endl;
	}
	else
	{
		return item[topitem-1];
	}
}

template < class Type>
void stackADT<Type>::pop()
{
	if (this->isEmptyStack()){
		cout << "The stack is empty, pop operation fail!" << endl;
	}
	else
	{
		topitem--;
		cout << "Pop successfully!" << endl;
	}
}

template < class Type>
void stackADT<Type>::initializeStack(int num)
{
	item = new Type[num];
	size = num;
	topitem = 0;
}

