//
// Created by Yukio Fukuzawa on 26/07/18.
//

#ifndef CSPADE_ORIGINAL_UTILS_H
#define CSPADE_ORIGINAL_UTILS_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

enum Pruning {
    None = 0, L2 = 1, Zero = 2, Follow = 4
};

const long MBYTE = (1024*1024);

#define min(a, b) ((a) < (b) ? (a) : (b))

#ifndef INFINITY
#define INFINITY INT_MAX
#endif

//join type
#define LJOIN 0
#define EJOIN 1
#define MJOIN 2

class EqGrNode;

namespace global {
    extern float FOLLOWTHRESH;
    extern long AVAILMEM;
    extern int DBASE_NUM_TRANS;
    extern int DBASE_MAXITEM;
    extern float DBASE_AVG_TRANS_SZ;
    extern float DBASE_AVG_CUST_SZ;
    extern int DBASE_TOT_TRANS;

    extern int num_partitions;
    extern int maxiter;
    extern int *backidx;            // in extl2.cc
    extern int *NumLargeItemset;    // in sequence.cc
    extern EqGrNode **eqgraph;      // -do-
    extern Pruning pruning_type;

    extern int NUMCLASS;
    extern int min_gap;
    extern int max_gap;
    extern int max_seq_len;
    extern int max_iset_len;
    extern int prepruning;
    extern int postpruning;
    extern int L2pruning;

    extern double MINSUP_PER;
    extern float FOLLOWTHRESH;
    extern long MEMUSED;
    extern long AVAILMEM;
}

using std::cout;
using std::cerr;
using std::endl;
using std::ostringstream;
using std::ifstream;
using std::vector;
using std::string;
using std::runtime_error;
using std::ostream;

// Logger and mem logger
extern ostringstream logger;
extern ostringstream result;
extern ostringstream memlog;
extern ostringstream summary;

extern char *optarg;
#endif //CSPADE_ORIGINAL_UTILS_H
