#include <stdlib.h>
#include <stdio.h>

#include "intVec.h"

#ifndef C101VecAdjacency
#define C101VecAdjacency

// this is the struct that tracks a single vector's adjacencies
typedef struct VectorAdjacencyNode * VectorAdjacencyVector;
// this is the struct that tracks all of the vector's adjacencies
typedef struct VectorAdjacencyInstance * VectorAdjacency;

/**
 * Access Functions
*/

/** initAdjacencyList(int numVectors)
 *  This is the function that creates a vector adjacency list for an n number of vectors being tracked
 *  Params:
 *      - numVectors: This is the total amount of vectors we want to track
*/
VectorAdjacency initAdjacencyList(int numVectors);

/** addVectorAdjacency(VectorAdjacency myVectors, int vectorId, int vectorEdge)
 *  This is the function that adds a vector to another vectors adjacency list
 *  Params:
 *      - myVectors: This is the adjacency list 
 *      - vectorId: This is the ID of the vector who we are adding a adjacent child too
 *      - vectorEdge: This is the id of the vertex that is adjacent to the vectorId
*/
void addVectorAdjacency(VectorAdjacency myVectors, int vectorId, int vectorEdge);

/** printAdjacencyList(int vectorId)
 *  This is the function that prints out the adjacency list for a specific vectorId
 *  Params:
 *      - vectorId: This is the ID of the adjacency list we want to print
*/
void printAdjacencyList(VectorAdjacency myVectors, int vectorId);

#endif