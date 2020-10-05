#pragma once
#ifndef MYDICTIONARY_
#define MYDICTIONARY_
#include "Node.h"
#include "MyDictList.h"
#include "DictData.h"
#include "CleanWord.h"
#include "SkipWord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class myDictionary {
    private:
        myDictList alphaLists[26];
        int size;
        int skipped;

        void insert(string word);

    public:
        myDictionary() {size = 0; skipped=0;};
        ~myDictionary() {};

        void load(string filename);
        bool find(string word, unsigned long int& compCor, unsigned long int& compNotCor);
        int getSize(){
		    return size;
	    }   

};

void myDictionary::insert(string word) {
    int i = word[0] - 'a';

    if(word.length() == 1) {
        alphaLists[i].setSingleCharAllowed();
    }
    else {
        string searchWord(word, 1);

        DictData data(searchWord);

        alphaLists[i].insert(data);
    }

    size ++;
}

void myDictionary::load(string filename) {
	fstream infile;
    string word;
    
    infile.open(filename);
	if (infile.is_open()) {
		while (infile >> word) {
			word = cleanWord(word);
		    
            if(!skipWord(word, skipped)) {
		        insert(word); 
            }
		}
	}

    infile.close();

    for(int i =0; i<26; i++) {
        alphaLists[i].initialize();
    }
}

bool myDictionary::find(string word, unsigned long int& compCor, unsigned long int& compNotCor) {
    int i = word[0] - 'a';

    return alphaLists[i].find(word, compCor, compNotCor);
}

#endif