//Natalie Foss 
//Program 1 main file
//Prog1.cpp
//COSC 2030
//9/15/2020

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "timer.h"
#include "Node.h"
#include "MyList.h"
#include "CleanWord.h"
#include "SkipWord.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std;


int main() {
	myList<string> dictionary;
	myList<string> misspelled;
	fstream infile1, infile2;
	string word;
	unsigned long int compCor = 0, compNotCor = 0;
	int correct(0), skipped(0);
	bool tf;

	dictionary.initialize();

	infile1.open("dict.txt");
	if (infile1.is_open()) {
		while (infile1 >> word) {
			dictionary.insertOpt(word); 
		}
	}

	infile2.open("book.txt");
	//start of timed section
	Timer timer;
	timer.Start();
	
	//this is spellcheck
	while (!infile2.eof()) {
		infile2 >> word;
		word = cleanWord(word);
		tf = skipWord(word, skipped);
		if (tf) {
			//could check against misspelled to make faster
			tf = dictionary.findOpt(word, compCor, compNotCor); //.findOpt()
			if (tf) {
				correct += 1;
			}
			else {
				misspelled.insert(word);
			}
		}
	}
	misspelled.correct();
	infile1.close();
	infile2.close();
	timer.Stop();
	//end of timed section


		int aveComp = compCor / correct;
		int aveNotComp = compNotCor / misspelled.getSize();
		cout << "dictionary size: " << dictionary.getSizeDict() << endl;
		cout << "done checking and these are the results" << endl << "finished in time: " << timer.Time() << endl;
		cout << "There are " << correct << " words found in the dictionary" << endl;
		cout << "	" << compCor << " compares. average: " << aveComp << endl;
		cout << "There are " << misspelled.getSize() << " words NOT found in the dictionary" << endl;
		cout << "	" << compNotCor << " compares. average: " << aveNotComp << endl;
		cout << "There were " << skipped << " words not checked.\n";

		//writing out misspelled words
		ofstream outfile;
		outfile.open("misspelled.txt");
		misspelled.print(outfile);
		cout << "done writing out to file.";
		outfile.close();
		
		misspelled.~myList();
		dictionary.~myList();
		
		return 0;
	
}
