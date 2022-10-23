#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <cmath>
#include <memory>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define G 6.67e-11

class CelestialBody: public sf::Drawable 
{
	public:
		CelestialBody(double);
		CelestialBody(double, double, double, double, double, std::string);
		
		void windowSize(double, double);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;	
		friend std::ostream& operator <<(std::ostream&, CelestialBody&);
		friend std::istream& operator >>(std::istream&, CelestialBody&);
		
		void setMass(double);
		void setxPos(double);
		void setyPos(double);
		void setxVel(double);
		void setyVel(double);
		void setDeltaX(double);
		void setDeltaY(double);
		void setxForce(double);
		void setyForce(double);
		void setxAcceleration();
		void setyAcceleration();
		void setNetForce(double, double);
		
		double getMass();
		double getxPos();
		double getyPos();
		double getxVel();
		double getyVel();
		double getDeltaX();
		double getDeltaY();
		double getxForce();
		double getyForce();
		double getxAcceleration();
		double getyAcceleration();
		double getNetForce();
									
	private:
		
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Image image;
		std::string planetName;
		double mass, radius, xPos, xVel, yPos, yVel, distance, winX, winY;
		double deltaTime, xForce, yForce, xAcc, yAcc, deltaX, deltaY, NetForce;
							
};
#endif
//CELESTIALBODY_H
