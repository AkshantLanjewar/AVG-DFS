#include "intVec.h"

typedef struct IntVecNode {
    /**
     * This is the array data that is allocated when the vector is constructed
    */
    int *data;

    /**
     * This is the amount of elements that are stored within the vector
    */
    int length;

    /**
     * This is the amount of elements the vector can support with the current memory allocation
    */
    int capacity;

    /**
     * Whether or not the vector has been constructed
    */
    bool constructed;
} IntVecNode;

/** intTop(IntVec myVec)
 * This is the function that returns the top element of the given vector.
 * Preconditions
 *  - myVec.length > 0
*/
int intTop(IntVec myVec)
{
    if(myVec->length < 1)
    {
        fprintf(stderr, "[IntVec Error]: Called intTop on an empty vector. Exiting program");
        exit(-1);
    }

    return myVec->data[0];
}

/** intData(IntVec myVec, int i)
 * This is the function that returns the element in the vector myVec at index i 
 * Preconditions
 *  - 0 <= i < intSize(myVec)
*/
int intData(IntVec myVec, int i)
{
    if(i < 0 || i > intSize(myVec))
    {
        fprintf(stderr, "[IntVec Error]: Index out of range in IntVec.");
        exit(-1);
    }

    return myVec->data[i];
}

/**
 * intSize(IntVec myVec)
 * This is the function that returns the size of the stored array in the IntVec
*/
int intSize(IntVec myVec)
{
    return myVec->length;
}

/**
 * intCapacity(IntVec myVec)
 * This is the function that returns the storage capacity of the vector.
*/
int intCapacity(IntVec myVec)
{
    return myVec->capacity;
}

/** intMakeEmptyVec(void)
 * This is the function that creates a new IntVec using the default values.
 * Postconditions
 *  - IntVec.capacity = 4
 *  - IntVec.length = 0
*/
IntVec intMakeEmptyVec()
{
    IntVecNode *newVector = malloc(sizeof(IntVecNode));
    if(newVector == NULL)
        return NULL;

    newVector->data = malloc(intInitCap * sizeof(int));
    if(newVector->data == NULL) {
        //handle the memory alloc failure
        free(newVector);
        return NULL;
    }

    newVector->length = 0;
    newVector->constructed = true;
    newVector->capacity = intInitCap;
    return newVector;
}

/** intMakeEmptyVecN(int np1)
 * This is the function that creates a new IntVec with a custom capacity
 * Postconditions
 *  - IntVec.capacity = np1
 *  - IntVec.length = 0
*/
IntVec intMakeEmptyVecN(int np1)
{
    IntVecNode *newVector = malloc(sizeof(IntVecNode));
    if(newVector == NULL)
        return NULL;

    newVector->data = malloc(np1 * sizeof(int));
    if(newVector->data == NULL) {
        //handle the memory alloc failure
        free(newVector);
        return NULL;
    }

    newVector->length = 0;
    newVector->constructed = true;
    newVector->capacity = np1;
    return newVector;
}

/** intVecPush(IntVec myVec, int newE)
 * This is the function that adds an element to the end of the IntVec
 * Postconditions
 *  - IntVec.length += 1
 *  - if IntVec.length > IntVec.capacity, IntVec.capacity *= 2
*/
void intVecPush(IntVec myVec, int newE)
{
    if(myVec->length == myVec->capacity)
    {
        myVec->capacity = myVec->capacity * 2;
        myVec->data = realloc(myVec->data, myVec->capacity * sizeof(int));
    }

    myVec->data[myVec->length] = newE;
    myVec->length = myVec->length + 1;
}

/** intVecPop(IntVec myVec)
 * This is the function that removes the top element of the IntVec
*/
void intVecPop(IntVec myVec)
{
    if(myVec->length <= 0)
        return;
    else if(myVec->length == 1)
    {
        myVec->data[0] = INT_MIN;
        myVec->length = 0;
        return;
    }

    for(int i = 0; i < myVec->length - 1; i++)
        myVec->data[i] = myVec->data[i + 1];

    myVec->length = myVec->length - 1;
}