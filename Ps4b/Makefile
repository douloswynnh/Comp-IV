CC = g++
CFLAGS = -Wall -Werror -ansi --pedantic -g -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
OBJ = CircularBuffer.o KSGuitarSim.o StringSound.o
DEPS = CircularBuffer.h StringSound.h
LIBS = 
EXE = StringSound


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) $(CFLAGS) 

KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) -c KSGuitarSim.cpp

CircularBuffer.o: CircularBuffer.cpp
	$(CC) -c CircularBuffer.cpp

StringSound.o: StringSound.cpp
	$(CC) -c StringSound.cpp

	
clean:
	rm $(OBJ) $(EXE)
