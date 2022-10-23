#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
#include "CelestialBody.h"

class Universe
{
	public:
		void readFile();
		void drawUniverse();
		void step(double, double);
	
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		int numberOfPlanets;
		
		double newYPos, newXPos;
		double radius, xForce, yForce, deltaX, deltaY, r;
		
		std::vector<std::shared_ptr<CelestialBody> > SolarSystem;
};

#endif 
//UNIVERSE_H
