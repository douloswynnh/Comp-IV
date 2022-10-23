CC = g++
CFLAGS = -g -Wall -Werror -pedantic 
OBJ = CircularBuffer.o test.o
DEPS = CircularBuffer.h
Boost= -lboost_unit_test_framework
EXE = ./ps4a


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) $(Boost) 

CircularBuffer.o: CircularBuffer.cpp
	$(CC) -c CircularBuffer.cpp

	
clean:
	rm $(OBJ) $(EXE)
