CC = gcc
CFLAGS = -Wall -g

#linking
dfs03: dfs03.o intVec.o
	$(CC) $(CFLAGS) dfs03.o intVec.o -o dfs03

intVecTest: intVecTest.o intVec.o
	$(CC) $(CFLAGS) intVecTest.o intVec.o -o intVecTest

intVecTest.o: intVecTest.c intVec.h
	$(CC) $(CFLAGS) -c intVecTest.c

dfs03.o: dfs03.c intVec.h
	$(CC) $(CFLAGS) -c dfs03.c

intVec.o: intVec.c intVec.h
	$(CC) $(CFLAGS) -c intVec.c

# Clean rule
clean:
	rm -f dfs03 dfs03.o intVec.o intVecTest.o