CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic 
OBJ = FibLFSR.o PhotoMagic.o
DEPS = FibLFSR.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PhotoMagic


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) 

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
