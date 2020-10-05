#pragma once
#ifndef MYDICTLIST_
#define MYDICTLIST_
#include "Node.h"
#include "DictData.h"
#include "MyOrderedList.h"
#include "CharBreak.h"
#include <string>
using std::string;
using namespace std;

class myDictList : public myOrderedList {
	private:
		CharBreak charBreaks[26];

	public:
		void initialize();
		bool find(string word, unsigned long int &compCor, unsigned long int &compNotCor);	
};

bool myDictList::find(string word, unsigned long int& compCor, unsigned long int& compNotCor) {
	if(word.length() == 1) {
		if(singleCharAllowed) {
			return true;
		} else {
			return false;
		}
	}

	unsigned long int attempts(0);
	string searchWord(word, 1);

	int charIndex = searchWord[0] - 'a';

	if(charIndex > 25) {
		return false;
	}
	
	startNode = head;
	startHops = startNode->data.numHops;

	if(inTopFoundWords(searchWord, attempts)) {
		compCor += attempts;
		return true;
	}
	else {
		if(charIndex >=0) {
			switch(charBreaks[charIndex].getStartPos(searchWord, startNode, startHops)) {
				case -1:
					compNotCor += attempts;
					return false;
				case 0:
					compCor += attempts;
					return true;
				default:
					break;
			}
		}
	
		bool breakLoop = false;

		for (node <DictData>* tmp = startNode;
			tmp != nullptr && !breakLoop;
			tmp = tmp->next) {
			attempts += 1;

			switch(searchWord.compare(tmp->data.word)) {
				case 1:
					continue;
				
				case 0:
					tmp->data.numFound++;

					updateTopFoundWords(tmp);

					compCor += attempts;
					return true;
				
				case -1:
					breakLoop = true;
			}
		}

		compNotCor += attempts;
		return false;
	}
}


void myDictList::initialize() {
	int currHops = 0;

	char currChar = head->data.word[0];

	myList<node<DictData>*> tmpList;
	tmpList.append(head);

	for (node<DictData>* i = head; i != nullptr; i = i->next) {
		i->data.numHops = currHops++;

		char tmpChar = i->data.word[0];

		if(tmpChar != currChar) {
			
			int index = currChar - 'a';

			if(index >= 0 && index < 26) {
				node<DictData>* *searchList = tmpList.toArray();
				
				charBreaks[index].initialize(searchList, tmpList.getSize());

				delete searchList;
			}

			tmpList.clear();

			currChar = tmpChar;
			tmpList.append(i);
		}
		else {
			tmpList.append(i);
		}
	}

	int index = currChar - 'a';

	if(index >= 0 && index < 26) {
		node<DictData>* *searchList = tmpList.toArray();
		
		charBreaks[index].initialize(searchList, tmpList.getSize());

		delete searchList;	
	}

}

#endif


