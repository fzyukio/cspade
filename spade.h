#ifndef SPADE_H
#define SPADE_H

#include <climits>
#include "Itemset.h"
#include "Eqclass.h"

namespace sequence {
    struct arg_t {
        int num_partitions = 1;
        double min_support_one = 0.5;
        int min_support_all = -1;
        int use_ascending = -2;
        bool use_class = false;
        bool ext_l2_pass = false;
        bool use_hash = false;
        int min_gap = 1;
        double avaimem_mb = 128;
        bool recursive = false;
        Pruning pruning_type = Pruning::Zero;
        int max_gap = INFINITY;
        bool use_window = false;
        int max_seq_len = 100;
        int max_iset_len = 100;
    };

    extern arg_t args;

    extern void get_tmpnewf_intersect(Itemset *&ljoin, Itemset *&ejoin,
                                      Itemset *&mjoin, int &lcnt, int &ecnt, int &mcnt,
                                      Itemset *it1, Itemset *it2, int iter);

    extern void fill_join(Itemset *join, Itemset *hdr1, Itemset *hdr2);

    extern void
    pre_pruning(Itemset *&iset, unsigned int ptempl, Itemset *it1, Itemset *it2, char use_seq);

    extern void post_pruning(Itemset *&iset, unsigned int templ);

    extern Itemset *prune_decision(Itemset *it1, Itemset *it2, unsigned int ptempl, int jflg);
}

#endif
