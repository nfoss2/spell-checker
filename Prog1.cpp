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
#include "MyDictionary.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;

int main()
{
	myDictionary dictionary;
	myList<string> misspelled;
	fstream infile1, infile2;
	string word;
	unsigned long int compCor = 0, compNotCor = 0;
	int correct(0), skipped(0);

	cout << "Loading dictionary" << endl;
	dictionary.load("dict.txt");

	infile2.open("book.txt");

	cout << "Start timer" << endl;
	//start of timed section
	Timer timer;
	timer.Start();

	//this is spellcheck
	while (infile2 >> word) {
		word = cleanWord(word);
		if (!skipWord(word, skipped)) {
			if(dictionary.find(word, compCor, compNotCor)) {
				correct += 1;
			}
			else {
				misspelled.append(word);
			}
		}
	}

	timer.Stop();
	//end of timed section
	cout << "Stopped timer" << endl;
	infile2.close();

	int aveComp = compCor / correct;
	int aveNotComp = compNotCor / misspelled.getSize();
	cout << "dictionary size: " << dictionary.getSize() << endl;
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

	return 0;
}
