//
// Created by Yukio Fukuzawa on 26/07/18.
//

#include <sstream>
#include "utils.h"


Pruning pruning_type = Pruning ::None;
long MEMUSED = 0;
long AVAILMEM = 128 * MBYTE;

int *NumLargeItemset;
EqGrNode **eqgraph;
int maxiter = 2;
int min_gap = 1;
int max_gap = INFINITY;
char outputfreq = 0;
char print_tidlist = 0;

int max_seq_len = 100;
int max_iset_len = 100;

//std::ofstream mout;
int DBASE_NUM_TRANS;
int DBASE_MAXITEM;
float DBASE_AVG_TRANS_SZ;
float DBASE_AVG_CUST_SZ;
int DBASE_TOT_TRANS;

double MINSUP_PER;
float FOLLOWTHRESH = 1.0;
int NUMCLASS = 1;

int L2pruning = 0;
int prepruning = 0;
int postpruning = 0;

std::ostringstream logger;
std::ostringstream memlog;
std::ostringstream summary;