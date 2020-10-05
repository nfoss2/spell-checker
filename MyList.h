#pragma once
#ifndef MYLIST_
#define MYLIST_
#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using namespace std;

template <class T>
class myList {
protected:
	node <T>* head;
	node <T>* tail;
	int size;

public:
	myList() : head(nullptr), tail(nullptr), size(0) {}
	~myList();
	void insert(T item);
	void append(T item);
	void remove();
	void print(ofstream &outfile);
	T front();
	bool find(string word, unsigned long int &compCor, unsigned long int &compNotCor);
	bool isEmpty() {
		return size == 0;
	}
	int getSize() {
		return size;
	}
	void clear();
	T* toArray();
};


//deconstructor
template <class T>
myList<T>::~myList() {
	clear();
}

template <class T>
void myList<T>::clear() {
	while (!isEmpty()) {
		remove();
	}
}

template <class T>
void myList<T>::append(T item) {
	node <T>* tmp = new node <T>(item);

	if(head == nullptr) {
		head = tmp;
	}

	if(tail == nullptr) {
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}

	size++;
}

//this function is the regular insert function
template <class T>
void myList<T>::insert(T item) {
	node <T>* tmp = new node <T>(item);

	if(tail == nullptr) {
		tail = tmp;
	}

	tmp->next = head;
	head = tmp; 
	size++;
}



//this function revomes the front item in the linked list
template <class T>
void myList<T>::remove() {
	if (head != nullptr) {
		node <T>* tmp = head;
		head = tmp->next;
		delete tmp;
		size--;
	}

	if(head == nullptr) {
		tail = nullptr;
	}
}


//this function is the regular find function 
template <class T>
bool myList<T>::find(string word, unsigned long int &compCor, unsigned long int &compNotCor) {
	unsigned long int temp(0);
	
	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {

		temp += 1;

		if (tmp->data.std::string::compare(word) == 0) {
			compCor += temp;
			return true;
		}	
	}
	compNotCor += temp;
	return false;
}

//this function prints a list to a file
template <class T>
void myList<T>::print(ofstream &outfile) {
	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		outfile << tmp->data << endl;
	}
}

//this function returns the first element of list
template <class T>
T myList<T>::front() {
	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		return tmp->data;
	}
}

template <class T>
T* myList<T>::toArray() {
	T* retVal = new T[size];

	int i = 0;

	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		retVal[i++] = tmp->data;
	}

	return retVal;
}

#endif


