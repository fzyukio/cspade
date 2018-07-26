#ifndef __DATABASE_H
#define __DATABASE_H

#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cerrno>
#include "utils.h"

extern int use_seq;

#define DCBBUFSZ 2048
#define TRANSOFF 3

class CalcDb {
public:
    CalcDb(char *infile, int buf_sz = DCBBUFSZ);

    ~CalcDb();

    void get_next_trans_ext();

    inline void get_first_blk();

    inline void get_next_trans(int *&lbuf, int &numitem, int &tid, int &custid);

    int eof() {
        return (readall == 1);
    }

    int fd;
    int buf_size;
    int *buf;
    int cur_blk_size;
    int cur_buf_pos;
    int endpos;
    char readall;
};

inline void CalcDb::get_first_blk() {
    readall = 0;
    lseek(fd, 0, SEEK_SET);
    cur_blk_size = (read(fd, (void *) buf, (buf_size * ITSZ))) / ITSZ;
    if (cur_blk_size < 0) {
        throw runtime_error("get_first_blk");
    }
    cur_buf_pos = 0;
}

inline void CalcDb::get_next_trans(int *&lbuf,
                                   int &nitems, int &tid, int &cid) {
    if (cur_buf_pos + TRANSOFF >= cur_blk_size ||
        cur_buf_pos + buf[cur_buf_pos + TRANSOFF - 1] + TRANSOFF > cur_blk_size) {
        if (lseek(fd, 0, SEEK_CUR) == endpos) readall = 1;
        if (!readall) {
            // Need to get more items from file
            get_next_trans_ext();
        }
    }

    if (!readall) {
        cid = buf[cur_buf_pos];
        tid = buf[cur_buf_pos + TRANSOFF - 2];
        nitems = buf[cur_buf_pos + TRANSOFF - 1];
        lbuf = buf + cur_buf_pos + TRANSOFF;
        cur_buf_pos += nitems + TRANSOFF;
    }
}

#endif //__DATABASE_H





