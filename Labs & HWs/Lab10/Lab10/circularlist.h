#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

#endif