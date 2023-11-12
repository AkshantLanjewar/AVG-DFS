#include "vectorAdjacency.h"

//This is the definition for a tracked vertex within the VectorAdjacency structure
typedef struct VectorAdjacencyNode {
    // this is the numerical ID of the vector we are tracking (ex 1, 2, ...)
    int vectorId;

    //This is the IntVec of adjacent vectors (used for simplified convinience)
    IntVec adjacentVectors;
} VectorAdjacencyNode;

//This is the definition for an instance of the struct that tracks vert adjacency
typedef struct VectorAdjacencyInstance {
    //The amount of vertex's we are tracking
    int length;

    //The nodes associated with the adjacency tracking
    VectorAdjacencyVector* data;
} VectorAdjacencyInstance;

//This is a helper function aimed at inializing a VectorAdjacencyNode as ez as possible
VectorAdjacencyVector initalizeVector(int vectorId)
{
    VectorAdjacencyNode* newNode = malloc(sizeof(VectorAdjacencyNode));
    if(newNode == NULL)
        return NULL;

    newNode->vectorId = vectorId;
    newNode->adjacentVectors = intMakeEmptyVec();
    return newNode;
}

/** initAdjacencyList(int numVectors)
 *  This is the function that creates a vector adjacency list for an n number of vectors being tracked
 *  Params:
 *      - numVectors: This is the total amount of vectors we want to track
*/
VectorAdjacency initAdjacencyList(int numVectors)
{
    VectorAdjacencyInstance* newInstance = malloc(sizeof(VectorAdjacencyInstance));
    if(newInstance == NULL)
        return NULL;

    newInstance->length = numVectors;
    newInstance->data = malloc(sizeof(VectorAdjacencyVector) * numVectors);
    
    //handle allocation fail
    if(newInstance->data == NULL) {
        free(newInstance);
        return NULL;
    }

    //now go through and populate the instance data with scaffolded nodes
    for(int i = 0; i < numVectors; i++) {
        int vectorId = i + 1;
        VectorAdjacencyVector trackingVector = initalizeVector(vectorId);

        newInstance->data[i] = trackingVector;
    }

    return newInstance;
}

/** addVectorAdjacency(VectorAdjacency myVectors, int vectorId, int vectorEdge)
 *  This is the function that adds a vector to another vectors adjacency list
 *  Params:
 *      - myVectors: This is the adjacency list 
 *      - vectorId: This is the ID of the vector who we are adding a adjacent child too
 *      - vectorEdge: This is the id of the vertex that is adjacent to the vectorId
*/
void addVectorAdjacency(VectorAdjacency myVectors, int vectorId, int vectorEdge)
{
    if(myVectors->data == NULL)
        return;

    //first let us go though the nodes and find the node with the matching vectorId
    for(int i = 0; i < myVectors->length; i++) {
        VectorAdjacencyVector vector = myVectors->data[i];
        if(vector->vectorId != vectorId)
            continue;

        intVecPush(vector->adjacentVectors, vectorEdge);
    }
}

/** printAdjacencyList(int vectorId)
 *  This is the function that prints out the adjacency list for a specific vectorId
 *  Params:
 *      - vectorId: This is the ID of the adjacency list we want to print
*/
void printAdjacencyList(VectorAdjacency myVectors, int vectorId)
{
    if(myVectors->data == NULL)
        return;

    //first let us go though the nodes and find the node with the matching vectorId
    for(int i = 0; i < myVectors->length; i++) {
        VectorAdjacencyVector vector = myVectors->data[i];
        if(vector->vectorId != vectorId)
            continue;

        printf("%d [", vectorId);
        for(int x = 0; x < intSize(vector->adjacentVectors); x++) {
            int value = intData(vector->adjacentVectors, x);
            printf("%d", value);

            if(x != intSize(vector->adjacentVectors) - 1)
                printf(", ");
        }
        
        printf("]\n");
    }
}