CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic 
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost = -lboost_regex -lboost_date_time

all: 	ps7

ps7: 	main.o
	$(CC) main.o -o ps7 $(Boost)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)
	
clean:
	rm *.o
	rm ps7
