#ifndef DICTDATA_
#define DICTDATA_
#include <string>
using std::string;
using namespace std;

class DictData {
    public:
        string word;
        int numHops;
        int numFound;

    DictData() : numFound(0), numHops(0) {}
    DictData(string s) : DictData(s, 0, 0) {}
    DictData(string s, int fnd) : DictData(s, fnd, 0) {}
    DictData(string s, int fnd, int hops) : word(s), numHops(hops), numFound(fnd) {}
    ~DictData() {}

    int compareNumFound(DictData that);
};

int DictData::compareNumFound(DictData that) {
    int retVal = numFound - that.numFound;

    if(retVal == 0) {
        return numHops - that.numHops;
    }
    else {
        return retVal;
    }
}

#endif
