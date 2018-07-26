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
#include <strstream>

enum Pruning {
    None = 0, L2 = 1, Zero = 2, Follow = 4
};

const long MBYTE = (1024*1024);
const int ITSZ = sizeof(int);

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

namespace sequence {
    struct arg_t {
        char name[300];
        char binf[300];
        char dataf[300];
        char idxf[300];
        char conf[300];
        char it2f[300];
        char seqf[300];
        char classf[300];

        int num_partitions = 1;
        double min_support_one = 0.5;
        int min_support_all = -1;
        int use_ascending = -2;
        bool use_class = false;
        bool do_l2 = false;
        bool use_hash = false;
        int min_gap = 1;
        double maxmem = 128;
        bool recursive = false;
        Pruning pruning_type = Pruning::Zero;
        int max_gap = INT_MAX;
        bool use_window = false;
        int max_seq_len = 100;
        int max_iset_len = 100;

        bool twoseq = false;
        bool use_diff = false;
        bool use_newformat = true;
        bool no_minus_off = true;
    };

    extern arg_t cspade_args;
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
using std::ofstream;
using std::istrstream;

// Logger and mem logger
extern ostringstream logger;
extern ostringstream result;
extern ostringstream memlog;
extern ostringstream summary;

//extern char *optarg;

extern int cmp2it(const void *a, const void *b);






#endif //CSPADE_ORIGINAL_UTILS_H
