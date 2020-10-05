#pragma once
#ifndef MYORDEREDLIST_
#define MYORDEREDLIST_
#include "Node.h"
#include "MyList.h"
#include "DictData.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using namespace std;

class myOrderedList : public myList<DictData> {
	protected:
		node <DictData>* topFoundWords[10];
		node <DictData>* minTopFound;

		bool singleCharAllowed;
	
		node <DictData>* startNode;
		int startHops;

		void updateTopFoundWords(node <DictData>* foundNode);
		void sortTopFoundWords(int startPos);
		void insertTopFoundWords(int pos, node <DictData>* foundNode);

		int compareNumFound(node <DictData>* n1, node <DictData>* n2);


	public:
		myOrderedList();

		void setSingleCharAllowed() {singleCharAllowed = true;}

		void insert(DictData item);
		bool find(string word, unsigned long int &compCor, unsigned long int &compNotCor);	
		bool inTopFoundWords(string word, unsigned long int &attempts);
	
};

myOrderedList::myOrderedList() {
	singleCharAllowed = false;

	minTopFound = nullptr;

	for(int i=0; i<10; i++) {
		topFoundWords[i] = nullptr;
	}

	startNode = nullptr;
	startHops = 0;
}

void myOrderedList::insert(DictData item) {

	if(head == nullptr) {
		head = new node <DictData>(item);
	}
	else if(item.word.compare(head->data.word) < 0) {
		node <DictData>* tmp = new node <DictData>(item);

		tmp->next = head;
		head = tmp;
	}
	else {
		for (node<DictData>* i = head; i != nullptr; i = i->next) {
			node <DictData>* tmpNext = i->next;

			int comp;

			if(tmpNext == nullptr || (comp = item.word.compare(tmpNext->data.word)) < 0) {
				node <DictData>* tmp = new node <DictData>(item);
				
				i->next = tmp;
				tmp->next = tmpNext;
				break;
			}
			else if(comp == 0) {
				break;
			}
		}
	}

	size++;
}


bool myOrderedList::find(string word, unsigned long int& compCor, unsigned long int& compNotCor) {
	
	unsigned long int attempts(0);
	
	for (node <DictData>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {

		attempts += 1;

		int comp = tmp->data.word.compare(word);

		if(comp == 0) {
			tmp->data.numFound++;

			compCor += attempts;
			return true;
		}
		else if(comp > 0) {
			break;
		}
	}

	compNotCor += attempts;
	return false;
}

bool myOrderedList::inTopFoundWords(string word, unsigned long int &attempts) {
	for(int i=0; i<10; i++) {
		attempts ++;

		if(topFoundWords[i] == nullptr) {
			break;
		}
		else {
			switch(word.compare(topFoundWords[i]->data.word)) {
				case 0:
					topFoundWords[i]->data.numFound++;
					sortTopFoundWords(i);
					return true;
			 
				case 1:
					if(startHops < topFoundWords[i]->data.numHops) {
						startNode = topFoundWords[i];
						startHops = topFoundWords[i]->data.numHops;
					}	
					continue;

				case -1:
					continue;		
			}
		}
	}

	return false;
}

// is complete but too many checks for speed
int myOrderedList::compareNumFound(node <DictData>* n1, node <DictData>* n2) {
	if(n1 == n2) {
		return 0;
	}
	else if(n1 == nullptr) {
		return -1;
	}
	else if(n2 == nullptr) {
		return 1;
	}
	else if(n1->data.numFound > n2->data.numFound) {
		return 1;
	}
	else if(n1->data.numFound < n2->data.numFound) {
		return -1;
	}
	else if(n1->data.numHops < n2->data.numHops) {
		return -1;
	}
	else if(n1->data.numHops > n2->data.numHops) {
		return 1;
	}
	else {
		return 0;
	}
}

void myOrderedList::updateTopFoundWords(node <DictData>* foundNode) {
	if(minTopFound == nullptr || minTopFound->data.compareNumFound(foundNode->data) < 0) {
		for(int i=0; i<10; i++) {
			if(topFoundWords[i] == nullptr) {
				topFoundWords[i] = foundNode;
				sortTopFoundWords(i);
				break;
			}
			else if(foundNode->data.compareNumFound(topFoundWords[i]->data) > 0) {
				insertTopFoundWords(i, foundNode);
				break;
			}
		}
	}
}

void myOrderedList::insertTopFoundWords(int pos, node <DictData>* foundNode) {
	for(int i=8; i>=pos; i--) {
		topFoundWords[i+1] = topFoundWords[i];
	}

	topFoundWords[pos] = foundNode;

	minTopFound = topFoundWords[9];
}

void myOrderedList::sortTopFoundWords(int startPos) {
	for(int i = startPos; i > 0; i--) {
		if(topFoundWords[i]->data.compareNumFound(topFoundWords[i-1]->data) > 0) {
			node <DictData>* tmp = topFoundWords[i-1];
			topFoundWords[i-1] = topFoundWords[i];
			topFoundWords[i] = tmp;
		}
	}
	
	minTopFound = topFoundWords[9];
}

#endif


