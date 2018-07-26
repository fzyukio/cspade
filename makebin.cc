#include <cerrno>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <strstream>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cmath>

#define ITSZ sizeof(int)
const int lineSize=8192;
const int wdSize=256;

using namespace std;

ifstream fin;
ofstream fout;

void convbin(char *inBuf, int inSize)
{
   char inStr[wdSize];
   istrstream ist(inBuf, inSize);
   int it;
   while(ist >> inStr){
      it = atoi(inStr);
      //cout << it  << " ";
      fout.write((char*)&it, ITSZ);
   }
   //cout << endl;
}

int main(int argc, char **argv)
{
   char inBuf[lineSize];
   int inSize;
   fin.open(argv[1]);
   if (!fin){
      throw std::runtime_error("cannot open in file");
   }
   fout.open(argv[2]);
   if (!fout){
      throw std::runtime_error("cannot open out file");
   }
   
   while(fin.getline(inBuf, lineSize)){
      inSize = fin.gcount();
      //cout << "IN SIZE " << inSize << endl;
      convbin(inBuf, inSize);
   }
}
