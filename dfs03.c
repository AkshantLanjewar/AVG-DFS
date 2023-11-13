#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "vectorAdjacency.h"

int main(int argc, char *argv[]) 
{
    int rArgc = argc - 1;
    bool undirectedMode = false;
    //what we are going to do here is allocated some space for a filename
    char fileLocation[2048] = {0};

    switch(rArgc) {
        case 1:
            if(strlen(argv[1]) > 2047) {
                fprintf(stderr, "Unfortunately the filename you typed is too long, keep it to under 2047 characters\n");
                return -2;
            }

            if(strcmp(argv[1], "-") == 0) 
            {
                fprintf(stdout, "Welcome to the filename selection screen, please type in a filename below to read from (NOTE: Must be less than 2048 characters long).\n");
                const char* inputStream = fgets(fileLocation, sizeof(fileLocation), stdin);
                if(inputStream == NULL)
                {
                    fprintf(stderr, "failed to read input from command line, try again \n");
                    return -3;
                }

                //making sure to remove the newline character
                fileLocation[strcspn(fileLocation, "\n")] = '\0'; 
            } 
            else
            {
                //copy the value from argv into the filelocation var
                strncpy(fileLocation, argv[1], sizeof(fileLocation) - 1);
                fileLocation[sizeof(fileLocation) - 1] = '\0'; //ensureing the null termination
            }

            break;
        case 2:
            if(strcmp(argv[1], "-U") == 0)
                undirectedMode = true;

            //copy argv 2 into the fileLocation var
            strncpy(fileLocation, argv[2], sizeof(argv[2]) - 1);
            fileLocation[sizeof(fileLocation) - 1] = '\0'; //ensuring the null termination
            break;
        case 0:
            fprintf(stderr, "Unfortunately you have entered an invalid set of input arguments, try again.\n");
            return -2;
        default:
            fprintf(stderr, "Unfortunately you have entered an invalid set of input arguments, try again.\n");
            return -2;
    }

    /**
     * Now we will open the file, and begin to construct our base data structures in order to parse the data
    */
    FILE *file; //pointer for the file we are going to open
    char fileLine[2048] = {0}; // This is the buffer for each line
    
    file = fopen(fileLocation, "r");
    if(file == NULL) 
    {
        fprintf(stderr, "Failed to open file, enter a valid filename and try again.\n");
        return -2;
    }

    VectorAdjacency adjacencyTracker = NULL;
    char leftLinePart[1024];
    char rightLinePart [1024];
    int numVertex = 0;

    while(fgets(fileLine, sizeof(fileLine), file)) {
        char* token;
        int count = 0;

        token = strtok(fileLine, " ");
        bool isFirstLine = true;
        while(token != NULL && count < 3) {
            switch(count) {
                case 0:
                    strcpy(leftLinePart, token);
                    break;
                case 1:
                    strcpy(rightLinePart, token);
                    isFirstLine = false;

                    break;
                case 2:
                    //handle weight here for DFS implementation
                    break;
                default:
                    break;
            }

            //iterate the next loop
            token = strtok(NULL, " ");
            count++;
        }

        if(isFirstLine == true) {
            numVertex = atoi(leftLinePart);
            adjacencyTracker = initAdjacencyList(numVertex);
        } else {
            //now we will parse the strings into numbers so that we can update the adjacency tracker
            int leftNumber = atoi(leftLinePart);
            int rightNumber = atoi(rightLinePart);
            //add the dependencies now accordingly
            addVectorAdjacency(adjacencyTracker, leftNumber, rightNumber);
            if(undirectedMode == true)
                addVectorAdjacency(adjacencyTracker, rightNumber, leftNumber);
        }
    }

    //now iterate through the num vertex's 
    for(int i = 0; i < numVertex; i++)
    {
        int realVertexId = i + 1;
        printAdjacencyList(adjacencyTracker, realVertexId);
    }

    fclose(file);
    return 0;
}