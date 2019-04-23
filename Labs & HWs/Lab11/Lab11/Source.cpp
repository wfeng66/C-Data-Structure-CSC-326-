#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

template <class Type>
class stackADT{
public:
	stackADT();
	stackADT(int);
	~stackADT();
	void initializeStack(int);
	bool isEmptyStack();
	bool isFullStack();
	void push(Type);
	Type top();
	void pop();
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

