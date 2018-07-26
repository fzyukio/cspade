cmake_minimum_required(VERSION 3.9)
project(cspade_original)

set(CMAKE_CXX_STANDARD 11)

add_executable(cspade_original
        Array.cc
        Array.h
        ArrayT.cc
        ArrayT.h
        Database.cc
        Database.h
        Eqclass.cc
        Eqclass.h
        extl2.cc
        extl2.h
        HashTable.cc
        HashTable.h
        Itemset.cc
        Itemset.h
        Lists.cc
        Lists.h
        maxgap.cc
        maxgap.h
        partition.cc
        partition.h
        sequence.cc
        spade.h
        exttpose.cc
        exttpose.h
        makebin.cc
        makebin.h
        getconf.cc
        getconf.h
        calcdb.cc
        calcdb.h
        utils.cpp
        utils.h)
