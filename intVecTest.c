#include <stdio.h>
#include <assert.h>

#include "intVec.h"

int main() 
{
    fprintf(stdout, "This Module handles testing of the IntVec Library to make sure all the code works \n");

    //first step in the test we are going to test the creation of a default IntVec and a custom one
    IntVec defaultVector = intMakeEmptyVec();
    IntVec customVector = intMakeEmptyVecN(2);

    //check the default capacity is 4
    fprintf(stdout, "Testing default vector capacity = 4\n");
    assert(intCapacity(defaultVector) == 4);

    //check the custom capacity is 2
    fprintf(stdout, "Testing custom vector capacity = 2\n");
    assert(intCapacity(customVector) == 2);

    //now we want to add an item to each of the vectors
    intVecPush(defaultVector, 3);
    intVecPush(defaultVector, 1);

    intVecPush(customVector, 8);
    intVecPush(customVector, 4);
    intVecPush(customVector, 1);

    //check the default vector = 3
    fprintf(stdout, "We want to check the top element in the default vector is 1\n");
    assert(intTop(defaultVector) == 3);

    //check the top of default vector = 3 after popping one item
    intVecPop(defaultVector);
    fprintf(stdout, "We want to check that the top element is now 3\n");
    assert(intTop(defaultVector) == 1);

    //check that the size of the custom vector is 3
    fprintf(stdout, "Checking the custom vector length = 3\n");
    assert(intSize(customVector) == 3);

    //check the capacity of the custom vector is 4
    fprintf(stdout, "Checking capacity of custom = 4\n");
    assert(intCapacity(customVector) == 4);

    //check that custom[1] = 4
    fprintf(stdout, "Checking custom[1] = 4\n");
    assert(intData(customVector, 1) == 4);

    fprintf(stdout, "Tests complete, IntVec is working correctly\n");
    return 0;
}