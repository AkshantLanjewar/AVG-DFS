#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*
* intVec.h
* The purpose of this header is to create a reusable integer vector for C.
*/

#ifndef C101IntVec
#define C101IntVec

typedef struct IntVecNode * IntVec;

/**
 * This is the default initial capacity of an IntVec when created.
*/
static const int intInitCap = 4;

/**
 * Access Functions
*/

/** intTop(IntVec myVec)
 * This is the function that returns the top element of the given vector.
 * Preconditions
 *  - myVec.length > 0
*/
int intTop(IntVec myVec);

/** intData(IntVec myVec, int i)
 * This is the function that returns the element in the vector myVec at index i 
 * Preconditions
 *  - 0 <= i < intSize(myVec)
*/
int intData(IntVec myVec, int i);

/**
 * intSize(IntVec myVec)
 * This is the function that returns the size of the stored array in the IntVec
*/
int intSize(IntVec myVec);

/**
 * intCapacity(IntVec myVec)
 * This is the function that returns the storage capacity of the vector.
*/
int intCapacity(IntVec myVec);

/** intMakeEmptyVec(void)
 * This is the function that creates a new IntVec using the default values.
 * Postconditions
 *  - IntVec.capacity = 4
 *  - IntVec.length = 0
*/
IntVec intMakeEmptyVec(void);

/** intMakeEmptyVecN(int np1)
 * This is the function that creates a new IntVec with a custom capacity
 * Postconditions
 *  - IntVec.capacity = np1
 *  - IntVec.length = 0
*/
IntVec intMakeEmptyVecN(int np1);

/** intVecPush(IntVec myVec, int newE)
 * This is the function that adds an element to the end of the IntVec
 * Postconditions
 *  - IntVec.length += 1
 *  - if IntVec.length > IntVec.capacity, IntVec.capacity *= 2
*/
void intVecPush(IntVec myVec, int newE);

/** intVecPop(IntVec myVec)
 * This is the function that removes the top element of the IntVec
*/
void intVecPop(IntVec myVec);


#endif