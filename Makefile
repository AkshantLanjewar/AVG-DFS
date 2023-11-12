CC = gcc
CFLAGS = -Wall -g

TARGET=dfs03
OBJS=dfs03.o intVec.o vectorAdjacency.o 

#linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

intVecTest: intVecTest.o intVec.o
	$(CC) $(CFLAGS) intVecTest.o intVec.o -o intVecTest

intVecTest.o: intVecTest.c intVec.h
	$(CC) $(CFLAGS) -c intVecTest.c

dfs03.o: dfs03.c vectorAdjacency.h intVec.h
	$(CC) $(CFLAGS) -c dfs03.c 

vectorAdjacency.o: vectorAdjacency.c vectorAdjacency.h intVec.h
	$(CC) $(CFLAGS) -c vectorAdjacency.c

intVec.o: intVec.c intVec.h
	$(CC) $(CFLAGS) -c intVec.c

# Clean rule
clean:
	rm -f dfs03 dfs03.o intVec.o intVecTest.o intVecTest vectorAdjacency.o