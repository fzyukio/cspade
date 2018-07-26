//
// Created by Yukio Fukuzawa on 26/07/18.
//

#include <sstream>
#include "utils.h"

namespace global {
    int num_partitions = 1;
    int maxiter = 2;
    int min_gap = 1;
    int max_gap = INFINITY;
    int max_seq_len = 100;
    int max_iset_len = 100;
    EqGrNode **eqgraph;
    int L2pruning = 0;
    int prepruning = 0;
    int postpruning = 0;
    Pruning pruning_type = Pruning ::None;
    int *NumLargeItemset;

    int DBASE_NUM_TRANS;
    int DBASE_MAXITEM;
    float DBASE_AVG_TRANS_SZ;
    float DBASE_AVG_CUST_SZ;
    int DBASE_TOT_TRANS;
    double MINSUP_PER;

    float FOLLOWTHRESH = 1.0;
    int NUMCLASS = 1;
    long MEMUSED = 0;
    long AVAILMEM = 128 * MBYTE;
}



std::ostringstream logger;
std::ostringstream result;
std::ostringstream memlog;
std::ostringstream summary;