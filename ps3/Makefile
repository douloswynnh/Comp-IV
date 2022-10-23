CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:: 	TFractal
	
TFractal: main.o TFractal.o Triangle.o
	$(CC) main.o TFractal.o Triangle.o -o TFractal $(SFMLFLAGS)

TFractal.o: TFractal.cpp Triangle.cpp
	$(CC) -c $(CFLAGS) TFractal.cpp Triangle.cpp

Triangle.o: Triangle.cpp
	$(CC) -c $(CFLAGS) Triangle.cpp

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp
	
clean:
	rm *.o 
	rm TFractal
