#include <cerrno>
#include "makebin.h"

const int lineSize = 8192;
const int wdSize = 256;


void convbin(char *inBuf, std::streamsize inSize, ofstream &fout) {
    char inStr[wdSize];
    istrstream ist(inBuf, inSize);
    int it;
    while (ist >> inStr) {
        it = atoi(inStr);
        fout.write((char *) &it, ITSZ);
    }
}

void convert_bin(const string& ifname) {
    using sequence::cspade_args;

    ifstream fin(ifname.c_str());
    ofstream fout(cspade_args.binf);
    char inBuf[lineSize];
    std::streamsize inSize;
    if (!fin) {
        throw runtime_error("cannot open in file");
    }
    if (!fout) {
        throw runtime_error("cannot open out file");
    }

    while (fin.getline(inBuf, lineSize)) {
        inSize = fin.gcount();
        convbin(inBuf, inSize, fout);
    }
}
