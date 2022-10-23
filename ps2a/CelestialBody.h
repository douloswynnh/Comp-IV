#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H


#include <memory>
#include <string>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CelestialBody: public sf::Drawable 
{
	public:
		CelestialBody(double);
		CelestialBody(double, double, double, double, double, std::string);
		
		void windowSize(double, double);	
		friend std::ostream& operator <<(std::ostream&, CelestialBody&);
		friend std::istream& operator >>(std::istream&, CelestialBody&);
		
		void setMass(double);
		void setxPos(double);
		void setyPos(double);
		void setxVel(double);
		void setyVel(double);
		
		double getMass();
		double getxPos();
		double getyPos();
		double getxVel();
		double getyVel();
		
	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Image image;
		std::string planetName;
		double mass, radius, xPos, xVel, yPos, yVel, distance, winX, winY;
							
};
#endif
//CELESTIALBODY_H
