#ifndef UNIVERSE_H
#define UNIVERSE_H


#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "CelestialBody.h"

class Universe
{
	public:
		void readFile();
		void drawUniverse();
	
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		int numberOfPlanets;
		
		double radius;
		
		std::vector<std::shared_ptr<CelestialBody> > SolarSystem;
};

#endif 
//UNIVERSE_H
