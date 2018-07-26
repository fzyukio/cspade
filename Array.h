#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstdlib>
#include <iostream>
#include <sys/types.h>

extern long MEMUSED;

class Array {
protected:
    int *theArray;
    unsigned int theSize;
    unsigned int totSize;
    //unsigned int theIncr;
public:

    //Array (int sz, int incr);
    Array(int sz);

    ~Array();

    int subsequence(Array *ar);

    //void add (int, unsigned int);
    void add_ext(int val, int off, int *ary) {
        ary[off + theSize] = val;
        theSize++;
    }

    int operator[](unsigned int index) {
        return theArray[index];
    };

    void setitem(int pos, int val) {
        theArray[pos] = val;
    };

    int totsize() {
        return totSize;
    }

    void set_totsize(int sz) {
        totSize = sz;
    }

    void set_size(int sz) {
        theSize = sz;
    }

    void reset() {
        theSize = 0;
    }

    int *array() {
        return theArray;
    }

    void set_array(int *ary) {
        theArray = ary;
    }

    //int subsequence(Array&);
    //int compare(Array&);
    friend std::ostream &operator<<(std::ostream &outputStream, Array &arr);

    static int Arraycompare(void *iset1, void *iset2) {
        Array *it1 = (Array *) iset1;
        Array *it2 = (Array *) iset2;
        return it1->compare(*it2);
    }

    int compare(Array &ar2);

    int item(unsigned int index) {
        return theArray[index];
    }

    unsigned int size() {
        return theSize;
    }

    void realloc(int newsz) {
        MEMUSED -= totSize * sizeof(int);
        totSize = newsz;
        theArray = (int *) ::realloc(theArray, totSize * sizeof(int));
        if (theArray == NULL) {
            std::cout << "MEMORY EXCEEDED\n";
            exit(-1);
        }
        MEMUSED += totSize * sizeof(int);
    }

    void compact() {
        realloc(theSize);
    }

    void optadd(int item) {
        theArray[theSize++] = item;
    }

    void add(int item) {
        if (theSize + 1 > totSize) {
            //totSize = (int) (totSize*1.5);
            //std::cout << " " << MEMUSED;
            realloc((int) (totSize * 1.5));
            //theArray = (int *)realloc(theArray, totSize*sizeof(int));
            //if (theArray == NULL){
            //   std::cout << "MEMORY EXCEEDED\n";
            //   exit(-1);
            //}
            //MEMUSED += totSize*sizeof(int);
            //std::cout << " " << MEMUSED << std::endl;
        }
        theArray[theSize] = item;
        theSize++;
    }
};

#endif //__ARRAY_H


