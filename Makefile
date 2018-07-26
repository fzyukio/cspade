CC  = g++
#CC = CC -DSGI -no_auto_include
CFLAGS  = -g
HEADER  = Array.h Itemset.h Lists.h Eqclass.h extl2.h partition.h\
	maxgap.h spade.h
OBJS	= Itemset.o Array.o Eqclass.o Lists.o extl2.o partition.o\
	maxgap.o
LIBS = -lm -lc
TARGET  = spade exttpose makebin getconf

default:	$(TARGET)

.SUFFIXES: .o .cc

clean:
	rm -rf *~ *.o; rm -rf bin/*

spade: sequence.cc $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o bin/spade sequence.cc $(OBJS) $(LIBS)

.cc.o:
	$(CC) $(CFLAGS) -c $<

tpose: tpose.cc $(OBJS)
	$(CC) $(CFLAGS) -o bin/tpose tpose.cc $(OBJS) $(LIBS)

exttpose: exttpose.cc calcdb.o ArrayT.o calcdb.h ArrayT.h
	$(CC) $(CFLAGS) -o bin/exttpose exttpose.cc calcdb.o ArrayT.o $(LIBS)

Database.o: Database.cc Database.h
	$(CC) $(CFLAGS) -c -o Database.o Database.cc

ArrayT.o: ArrayT.cc ArrayT.h
	$(CC) $(CFLAGS) -c -o ArrayT.o ArrayT.cc

getconf: calcdb.o getconf.cc calcdb.h
	$(CC) $(CFLAGS) -o bin/getconf calcdb.o getconf.cc $(LIBS)

calcdb.o: calcdb.cc calcdb.h
	$(CC) $(CFLAGS) -c -o calcdb.o calcdb.cc

makebin: makebin.cc
	$(CC) $(CFLAGS) -o bin/makebin makebin.cc

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
