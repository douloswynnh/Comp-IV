CC = g++
CFLAGS = -std=c++11 -g -Og -Wall -Werror -pedantic -lsfml-graphics -lsfml-window -lsfml-system
OBJS = EDistance.o main.o
DEPS = EDistance.h
LIBS = 
EXE = EDistance

all: $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS) $(CFLAGS) 

main.o: main.cpp
	$(CC) -c main.cpp

EDistance.o: EDistance.cpp EDistance.h
	$(CC) -c EDistance.cpp
	
clean:
	rm $(OBJS) $(EXE)
