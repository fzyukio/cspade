#include <cerrno>
#include "makebin.h"

const int lineSize = 8192;
const int wdSize = 256;


void convbin(char *inBuf, int inSize, ofstream &fout) {
    char inStr[wdSize];
    istrstream ist(inBuf, inSize);
    int it;
    while (ist >> inStr) {
        it = atoi(inStr);
        fout.write((char *) &it, ITSZ);
    }
}

void convert_bin(const string& ifname, const string& ofname) {
    ifstream fin(ifname.c_str());
    ofstream fout(ofname.c_str());
    char inBuf[lineSize];
    int inSize;
    if (!fin) {
        throw runtime_error("cannot open in file");
    }
    if (!fout) {
        throw runtime_error("cannot open out file");
    }

    while (fin.getline(inBuf, lineSize)) {
        inSize = fin.gcount();
        //logger << "IN SIZE " << inSize << endl;
        convbin(inBuf, inSize, fout);
    }
}
