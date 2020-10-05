#pragma once
#ifndef SKIPWORD_
#define SKIPWORD_
#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using namespace std;

/*
bool skipWord(string word, int& skipped) {
	if (word.length() == 0) {
		return true;
	}

	char c = word[0];

	if (c == '\'' || ('0' <=c && c <='9') ) {
		skipped += 1;
		return true;
	}

	return false;
}
*/

bool skipWord(string word, int& skipped) {
	if (word.length() != 0) {

		switch(word[0]) {
			// isdigit())
			case '0': skipped++; return true;
			case '1': skipped++; return true;
			case '2': skipped++; return true;
			case '3': skipped++; return true;
			case '4': skipped++; return true;
			case '5': skipped++; return true;
			case '6': skipped++; return true;
			case '7': skipped++; return true;
			case '8': skipped++; return true;
			case '9': skipped++; return true;

			// quote
			case '\'': skipped++; return true;

			// everything else
			default: return false;
		}
		
	}
	else {
		return true;
	}
}

#endif
