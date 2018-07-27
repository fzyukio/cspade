CC  = g++
#CC = CC -DSGI -no_auto_include
CFLAGS  = -g -std=c++11
HEADER  = Array.h Itemset.h Lists.h Eqclass.h extl2.h partition.h\
	maxgap.h spade.h ArrayT.h utils.h exttpose.h makebin.h getconf.h calcdb.h
OBJS	= Itemset.o Array.o Eqclass.o Lists.o extl2.o partition.o\
	maxgap.o ArrayT.o utils.o exttpose.o makebin.o getconf.o calcdb.o
LIBS = -lm -lc
TARGET  = spade

default:	$(TARGET)

.SUFFIXES: .o .cc

copy:
	cp *.h *.cc /Users/yfukuzaw/workspace/pycspade/csrc/

clean:
	rm -rf *~ *.o; rm -rf bin/*

spade: sequence.cc $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o bin/spade sequence.cc $(OBJS) $(LIBS)

.cc.o:
	$(CC) $(CFLAGS) -c $<

Database.o: Database.cc Database.h
	$(CC) $(CFLAGS) -c -o Database.o Database.cc

ArrayT.o: ArrayT.cc ArrayT.h
	$(CC) $(CFLAGS) -c -o ArrayT.o ArrayT.cc

calcdb.o: calcdb.cc calcdb.h
	$(CC) $(CFLAGS) -c -o calcdb.o calcdb.cc

test:
	bin/makebin testdata/${NAME}.txt testdata/${NAME}.data
	bin/getconf -i testdata/${NAME} -o testdata/${NAME}
	bin/exttpose -i testdata/${NAME} -o testdata/${NAME} -s 0 -l -x
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -u 2 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -l 2 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -u 2 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -l 2 -u 2 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -l 2 -u 4 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -w 4 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -l 2 -u 4 -w 10 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -z 3 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -Z 3 -o
	bin/spade -e 1 -r -i testdata/${NAME} -s ${MINSUP} -z 3 -Z 4 -o


# dependencies
# $(OBJS): $(HFILES)
Array.o: Array.h
Lists.o: Lists.h
extl2.o: extl2.h
Itemset.o: Itemset.h
Eqclass.o: Eqclass.h
partition.o: partition.h
maxgap.o: maxgap.h
