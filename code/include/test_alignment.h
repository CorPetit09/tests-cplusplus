/*
 ** test_alignment.h
 ** Author: Samuel Jarque Abizanda
 ** Date: 04/11/2014
 **
 ** This is a template class to test the utility of memory alignment.
 ** We have an struct with the attributes passed to the template with
 ** the same order.
 ** 
 **
 */
#ifndef _TEST_ALIGNMENT_H
#define _TEST_ALIGNMENT_H

#include "utils.h"

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class CTestAlignment{

    struct TSizeEx{
        T1 type1;
        T2 type2;
        T3 type3;
        T4 type4;
        T5 type5;
        T6 type6;
    };

    TSizeEx size_ex;

public:

    CTestAlignment(){
        // Initialize values to 0
        INIT_ZERO(size_ex, TSizeEx);
    }

    void printInfo(int index = -1){
        // Print the memory address of each attribute and its size

        if (index >= 0){
            dbg("TSizeEx%d INFO (address, size)\n", index);
        } else{
            dbg("TSizeEx INFO (address, size)\n");
        }
        dbg("\tsize_ex (%#010x, %d)\n", &size_ex,       sizeof (size_ex));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T1>(), &size_ex.type1, sizeof (size_ex.type1));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T2>(), &size_ex.type2, sizeof (size_ex.type2));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T3>(), &size_ex.type3, sizeof (size_ex.type3));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T4>(), &size_ex.type4, sizeof (size_ex.type4));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T5>(), &size_ex.type5, sizeof (size_ex.type5));
        dbg("\t- %s (%#010x, %d)\n", GetTypeName<T6>(), &size_ex.type6, sizeof (size_ex.type6));
    }
};

#endif
