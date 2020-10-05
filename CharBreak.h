#ifndef CHARBREAK_
#define CHARBREAK_
#include "Node.h"
#include "DictData.h"
#include <string>
using std::string;
using namespace std;

#define compareInt(a, b)   ((a < b) ? -1 : (a > b) ? 1 : 0)

class CharBreak {
    private:
        static const int maxSize = 20;

        int findStart(int start, int end, int startHops);
        int findPos(int start, int end, string word, node <DictData>* &startPos);
        int checkEndpnts(int start, int end, string word, node <DictData>* &startPos);

/*
        int compareInt(int a, int b) {
            if(a < b) {
                return -1;
            } else if(a > b) {
                return 1;
            } else {
                return 0;
            }
        };
*/


    public:
        int size;
        node <DictData>* searchPos[maxSize];
        string searchWord[maxSize];
        int searchHops[maxSize];
        
        
        CharBreak();
        CharBreak(node <DictData>* *searchList, int len);
        
        void initialize(node <DictData>* *searchList, int len);
        int getStartPos(string word, node <DictData>* &startPos, int startHops);
        
};

CharBreak::CharBreak() {
    size = 0;

    for(int i=0; i<maxSize; i++) {
        searchPos[i] = nullptr;
    }
}

CharBreak::CharBreak(node <DictData>* *searchList, int len) : CharBreak() {
    initialize(searchList, len);
}


void CharBreak::initialize(node <DictData>* *searchList, int len) {
    if(len <= maxSize) {
        size = len;

       for(int i=0; i<size; i++) {
            searchPos[i] = searchList[i];
            searchWord[i] = searchList[i]->data.word;
            searchHops[i] = searchList[i]->data.numHops;
        }
    }
    else {
        size = maxSize;

        int incr = ((float) len) / (size - 1) + 0.5;
        if(incr < 1) {
            incr = 1;
        }

        for(int i=0; i<size-1; i++) {
            int tmp = i * incr;

            if(tmp >= len) {
                tmp = len-1;
            }

            searchPos[i] = searchList[tmp];
            searchWord[i] = searchList[tmp]->data.word;
            searchHops[i] = searchList[tmp]->data.numHops;
        }

        // make sure the last one is captured
        int i = size-1, tmp=len-1;
        searchPos[i] = searchList[tmp];
        searchWord[i] = searchList[tmp]->data.word;
        searchHops[i] = searchList[tmp]->data.numHops;

    }
}


int CharBreak::findStart(int start, int end, int startHops) {
    int mid=0;

    while(start <= end) {
        mid = (start+end) >> 1;

        switch(compareInt(searchHops[mid], startHops)) {
            case -1:
                start = mid+1;
                continue;
            
             case 0:
                return mid;

           case 1:
                end = mid-1;
                continue;
        }
    }

    start--;

    return start;
}

int CharBreak::findPos(int start, int end, string word, node <DictData>* &startPos) { 
    int mid;

    while(start <= end) {
        mid = (start+end) >> 1;

        switch(searchWord[mid].compare(word)) {
            case -1:
                start = mid+1;
                continue;
            
             case 0:
                return 0;

           case 1:
                end = mid-1;
                continue;
        }
    }
 
    start--;
    startPos = searchPos[start];

    return 1;
}


int CharBreak::checkEndpnts(int start, int end, string word, node <DictData>* &startPos) {
    switch(searchWord[start].compare(word)) {
        case 0:
            return 0;
        
        case -1:
            switch(searchWord[end].compare(word)) {
                case 0:
                    return 0;

                case 1:
                    startPos = searchPos[start];
                    return 1;

                default:
                    return -1;
            }

        default:
            return -1;
    }       
}

int CharBreak::getStartPos(string word, node <DictData>* &startPos, int startHops) {
    switch(size) {
        case 0:
            return -1;
        
        case 1:            
            switch(searchWord[0].compare(word)) {
                case 0:
                    return 0;
                
                default:
                    return -1;
            }
                
        case 2:
            return checkEndpnts(0, 1, word, startPos);
       
        default:
            int start, end=size-1;

            if(startHops > searchHops[0]) {
                start = findStart(1, end, startHops);
            }
            else {
                start = 0;
            }

            switch(checkEndpnts(start, end, word, startPos)) {
                case 0:
                    return 0;

                case -1:
                    return -1;

                default:
                    break;
            }

            return findPos(start, end, word, startPos);

    }
}

#endif
