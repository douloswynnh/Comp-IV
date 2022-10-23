#include <iostream>
#include "Universe.h"
#include "CelestialBody.h"

int main(int argc, char** argv){
	Universe universe;
	universe.readFile();
	
	universe.drawUniverse();
	
}
