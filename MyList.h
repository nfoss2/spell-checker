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
private:
	node <T>* head;
	node <myList <T>* >* optHead;
	int sizeDict, size, optSize;

public:
	myList() : head(nullptr), size(0) {}
	~myList();
	void initialize();
	void insert(T item);
	void insert(myList <T> *list);
	void insertOpt(string word);
	void remove();
	void print(ofstream &outfile);
	string front();
	void correct();
	bool find(string word, unsigned long int &compCor, unsigned long int &compNotCor);
	bool findOpt(string word, unsigned long int& compCor, unsigned long int& compNotCor);
	bool isEmpty() {
		return size == 0;
	}
	int getSize() {
		return size;
	}
	int getSizeDict() {
		return sizeDict;
	}
	
};

//deconstructor
template <class T>
myList<T>::~myList() {
	if (optHead != nullptr) {
		for (node <myList <T>* >* tmp = optHead;
			tmp != nullptr;
			tmp = tmp->next) {
			delete tmp;
		}
	}
	while (!isEmpty()) {
		remove();
	}
	
}

//this function creates the optimized shell for the dictionary, it is a linked list of liked lists, sorted by the first letter.
template <class T>
void myList<T>::initialize() {
	cout << "start of inital";
	myList <string> *a = new myList <string>();
	insert(a);
	myList <string> *b = new myList <string>();
	insert(b);
	myList <string> *c = new myList <string>();
	insert(c);
	myList <string> *d = new myList <string>();
	insert(d);
	myList <string> *e = new myList <string>();
	insert(e);
	myList <string> *f = new myList <string>();
	insert(f);
	myList <string> *g = new myList <string>();
	insert(g);
	myList <string> *h = new myList <string>();
	insert(h);
	myList <string> *i = new myList <string>();
	insert(i);
	myList <string> *j = new myList <string>();
	insert(j);
	myList <string> *k = new myList <string>();
	insert(k);
	myList <string> *l = new myList <string>();
	insert(l);
	myList <string> *m = new myList <string>();
	insert(m);
	myList <string> *n = new myList <string>();
	insert(n);
	myList <string> *o = new myList <string>();
	insert(o);
	myList <string> *p = new myList <string>();
	insert(p);
	myList <string> *q = new myList <string>();
	insert(q);
	myList <string> *r = new myList <string>();
	insert(r);
	myList <string> *s = new myList <string>();
	insert(s);
	myList <string> *t = new myList <string>();
	insert(t);
	myList <string> *u = new myList <string>();
	insert(u);
	myList <string> *v = new myList <string>();
	insert(v);
	myList <string> *w = new myList <string>();
	insert(w);
	myList <string> *x = new myList <string>();
	insert(x);
	myList <string> *y = new myList <string>();
	insert(y);
	myList <string> *z = new myList <string>();
	insert(z);
	
	cout << "ending inital";

}

//this function is the regular insert function
template <class T>
void myList<T>::insert(T item) {
	node <T>* tmp = new node <T>(item);
	tmp->next = head;
	head = tmp; 
	size++;
}

template <class T>
void myList<T>::insert(myList <T> *item) {
	node <myList <T>* >* tmp = new node <myList <T>* >(item);
	tmp->next = optHead;
	optHead = tmp;
	optSize++;
}

//this function is the optimized insert function for the dictionary
template <class T>
void myList<T>::insertOpt(string word) {
	char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char first = word[0];
	int key(0);
	bool exit = false;
	while (!exit && key < 26) {
		if (alph[key] == first) {
			exit = true;
		}
		else {
			key++;
		}
	}

	int i = 0;
	for (node <myList <T>* >* tmp = optHead;
		tmp != nullptr;
		tmp = tmp->next) {
		
		if (i == key) {
			tmp->data->insert(word);
			break;
		}
		i++;
	}
	sizeDict++;
}

//this function revomes the front item in the linked list
template <class T>
void myList<T>::remove() {
	node <T>* tmp = nullptr;
	if (head != nullptr) {
		tmp = head;
		head = tmp->next;
		delete tmp;
		size--;
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

//this function is the optimized find function that goes to the matching inner linked list and does regular find there.
template <class T>
bool myList<T>::findOpt(string word, unsigned long int& compCor, unsigned long int& compNotCor) {
	char alph[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char first = word[0];
	int key(0);
	bool exit = false;
	
	//finds a key match for the first letter of the book word
	while (!exit && key < 26) {
		if (alph[key] == first) {
			exit = true;
		}
		else {
			key++;
		}
	}

	//goes to that position in the linked list dictionary then searches the matching inner linked list.
	int i = 0;
	for (node <myList <T>* >* tmp = optHead;
		tmp != nullptr;
		tmp = tmp->next) {

		if (i == key) {
			bool tf;
			tf = tmp->data->find(word, compCor,  compNotCor);
			return tf;
		}
		i++;
	}
	return false;
}


//this function prints a list to a file
template <class T>
void myList<T>::print(ofstream &outfile) {
	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		outfile << tmp->data;
		if (tmp->next != nullptr)
			outfile << " -> ";
		else
			outfile << " /\n";
	}
}

//this function returns the first element of list
template <class T>
string myList<T>::front() {
	for (node <T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		return tmp->data;
	}
}

template <class T>
void myList<T>::correct() {
	size--;
}
#endif


