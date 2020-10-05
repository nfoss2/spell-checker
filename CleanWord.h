#pragma once
#ifndef CLEANWORD_
#define CLEANWORD_
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cleanWord(string word);

/*
string cleanWord(string word) {
	string retStrg;

	for(char c : word) {
		if(isalpha(c)) {
			retStrg += tolower(c);
		}
		else if(isdigit(c)) {
			retStrg += c;
		}
		else if(c == '\'') {
			retStrg += c;
		}
	}
	
	return retStrg;
}
*/

string cleanWord(string word) {
	string retStrg;

	for(char c : word) {
		switch(c) {
			// isalpha()
			case 'a': retStrg += 'a'; continue;
			case 'b': retStrg += 'b'; continue;
			case 'c': retStrg += 'c'; continue;
			case 'd': retStrg += 'd'; continue;
			case 'e': retStrg += 'e'; continue;
			case 'f': retStrg += 'f'; continue;
			case 'g': retStrg += 'g'; continue;
			case 'h': retStrg += 'h'; continue;
			case 'i': retStrg += 'i'; continue;
			case 'j': retStrg += 'j'; continue;
			case 'k': retStrg += 'k'; continue;
			case 'l': retStrg += 'l'; continue;
			case 'm': retStrg += 'm'; continue;
			case 'n': retStrg += 'n'; continue;
			case 'o': retStrg += 'o'; continue;
			case 'p': retStrg += 'p'; continue;
			case 'q': retStrg += 'q'; continue;
			case 'r': retStrg += 'r'; continue;
			case 's': retStrg += 's'; continue;
			case 't': retStrg += 't'; continue;
			case 'u': retStrg += 'u'; continue;
			case 'v': retStrg += 'v'; continue;
			case 'w': retStrg += 'w'; continue;
			case 'x': retStrg += 'x'; continue;
			case 'y': retStrg += 'y'; continue;
			case 'z': retStrg += 'z'; continue;
		
			// isalpha() && tolower()
			case 'A': retStrg += 'a'; continue;
			case 'B': retStrg += 'b'; continue;
			case 'C': retStrg += 'c'; continue;
			case 'D': retStrg += 'd'; continue;
			case 'E': retStrg += 'e'; continue;
			case 'F': retStrg += 'f'; continue;
			case 'G': retStrg += 'g'; continue;
			case 'H': retStrg += 'h'; continue;
			case 'I': retStrg += 'i'; continue;
			case 'J': retStrg += 'j'; continue;
			case 'K': retStrg += 'k'; continue;
			case 'L': retStrg += 'l'; continue;
			case 'M': retStrg += 'm'; continue;
			case 'N': retStrg += 'n'; continue;
			case 'O': retStrg += 'o'; continue;
			case 'P': retStrg += 'p'; continue;
			case 'Q': retStrg += 'q'; continue;
			case 'R': retStrg += 'r'; continue;
			case 'S': retStrg += 's'; continue;
			case 'T': retStrg += 't'; continue;
			case 'U': retStrg += 'u'; continue;
			case 'V': retStrg += 'v'; continue;
			case 'W': retStrg += 'w'; continue;
			case 'X': retStrg += 'x'; continue;
			case 'Y': retStrg += 'y'; continue;
			case 'Z': retStrg += 'z'; continue;
		
			// isdigit())
			case '0': retStrg += '0'; continue;
			case '1': retStrg += '1'; continue;
			case '2': retStrg += '2'; continue;
			case '3': retStrg += '3'; continue;
			case '4': retStrg += '4'; continue;
			case '5': retStrg += '5'; continue;
			case '6': retStrg += '6'; continue;
			case '7': retStrg += '7'; continue;
			case '8': retStrg += '8'; continue;
			case '9': retStrg += '9'; continue;

			// quote
			case '\'': retStrg += '\''; continue;

			// everything else
			default: continue;
		}
	}
	
	return retStrg;
}

#endif
