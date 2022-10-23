CC = g++
CFLAGS = -c

run: main.o Universe.o CelestialBody.o
	$(CC) main.o Universe.o CelestialBody.o -o NBody -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Universe.o: Universe.cpp
	$(CC) $(CFLAGS) Universe.cpp

CelestialBody.o: CelestialBody.cpp
	$(CC) $(CFLAGS) CelestialBody.cpp

clean:
	rm -rf *o NBody
	
