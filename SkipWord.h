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

bool skipWord(string word, int& skipped) {
	if (word.length() == 0) {
		return false;
	}
	if (isdigit(word[0]) || word[0] == '\'') {
		skipped += 1;
		return false;
	}
	return true;

}

#endif
