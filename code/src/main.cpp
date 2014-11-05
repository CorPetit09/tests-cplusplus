/*
 ** main.cpp
 ** Author: Samuel Jarque Abizanda
 ** Date: 04/11/2014
 **
 ** This a a test to check the memory alignment and to see
 ** how the size changes.
 ** 
 ** With this example and a 64 bits config, the difference sorting
 ** the params is 16 bytes. 
 ** It's important to keep the attributes sorted as a good practice
 ** because some times (for example, using system particles) we can
 ** save a lot of memory.
 ** Keep in mind that pointers change its size depending on the platform
 ** 
 */
#include "test_alignment.h"

int main(){

    CTestAlignment<char*, double, float, short, char, bool> testBest;
    CTestAlignment<short, char*, bool, double, char, float> testWorst;
    
    testBest.printInfo(1);
    testWorst.printInfo(2);

    return EXIT_SUCCESS;
}
