CC = g++
CFLAGS = -Wall -Werror -ansi --pedantic -g
OBJS = RandWriter.o test.o
DEPS = RandWriter.h
LIBS = -lboost_unit_test_framework
EXE = TextWriter

all: $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS) $(CFLAGS) 

test.o: test.cpp
	$(CC) -c test.cpp

RandWriter.o: RandWriter.cpp RandWriter.h
	$(CC) -c RandWriter.cpp
	
clean:
	rm $(OBJS) $(EXE)
