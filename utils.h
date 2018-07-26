//
// Created by Yukio Fukuzawa on 26/07/18.
//

#ifndef CSPADE_ORIGINAL_UTILS_H
#define CSPADE_ORIGINAL_UTILS_H

#include <sstream>
#include "Eqclass.h"

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

//extern
extern double MINSUP_PER;

// Logger and mem logger
extern std::ostringstream logger;
extern std::ostringstream result;
extern std::ostringstream memlog;
extern std::ostringstream summary;

extern char *optarg;
#endif //CSPADE_ORIGINAL_UTILS_H
