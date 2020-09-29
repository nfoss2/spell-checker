#pragma once
#ifndef CLEANWORD_
#define CLEANWORD_
#include "Node.h"
#include "MyList.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cleanWord(string word);
string checkChar(string word);
bool checkBlank(string word);
string mkLower(string word);



string cleanWord(string word) {
	word = checkChar(word);
	word = mkLower(word);
	return word;
}

string checkChar(string word) {
	string temp = word;
	string good = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890'";
	
	
	for (char c : good) {
		temp.erase(std::remove(temp.begin(), temp.end(), c), temp.end());
	}
	for (char c : temp) {
		word.erase(std::remove(word.begin(), word.end(), c), word.end());
	}
	return word;
}

/*for (int i = 0; i < word.length(); i++) {
		char str = word[i];
		string
		if (!isalpha(str) && !isdigit(str) && !str.compare("'")) {
			word.remove(i, (i + 1));
		}
	}*/


bool checkBlank(string word) {
	if (word.compare("")) {
		return true;
	}
	else
		return false;
}


string mkLower(string word) {
	for (int i = 0; i < word.length(); i++) {
		char str = word[i];
		if (isalpha(str)) {
			word[i] = tolower(str);
		}
	}
	return word;
}



#endif
