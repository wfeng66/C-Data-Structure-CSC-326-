#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include<stdio.h> 
#include<stdlib.h>
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
	nodeType(const S d, nodeType<S>* prv = nullptr, nodeType<S>* nxt = nullptr) :info(d), next(nxt), prev(prv) {}
};

template <class S>
class linkedlist {
public:
	linkedlist();
	// defaul constructor, create a null linked list
	~linkedlist();
	// destructor, delete linked list
	bool isEmpty();
	// check if the list is empty
	// input: none
	// output: bool, return ture if the list is empty, else return false
	void initFile(string, int, int);
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
	// print the linked list of that object
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
	void swap(nodeType<S>*, nodeType<S>*);
	// swap two nodes 
	// input: two pointers of nodes which should be exchanged positions
	// output: void
	void sort();
	// sort the linked list ascendingly
	// input: no
	// output: void
	void delduplicate();
	// delete the duplicated elements, before executing this function, the list has to be sorted first
	// input: no
	// output: void

private:
	int count;
	nodeType<S> *current;
	nodeType<S> *first;
	nodeType<S> *last;
};

#endif