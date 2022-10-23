#include "CelestialBody.h"
using namespace sf;

//consturtor with one parameter 
CelestialBody::CelestialBody(double radius){
	this->radius = radius;
}

//constructor with parameters
CelestialBody::CelestialBody(double xPos, double yPos, double xVel, double yVel, double, std::string planetName)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->xVel = xVel;
	this->yVel = yVel;
	this->planetName = planetName;
}

//window size 
void CelestialBody::windowSize(double x, double y){
	winX = x;
	winY = y;
}

//overidden operator for inputting files 
std::istream& operator >> (std::istream &input, CelestialBody &cBody){
	input >> cBody.xPos >> cBody.yPos >> cBody.xVel >> cBody.yVel >> cBody.mass >> cBody.planetName;
	
	if(!cBody.image.loadFromFile(cBody.planetName))
	{
		std::cout << "Error" << std::endl;
		
	}
	cBody.texture.loadFromImage(cBody.image);
	cBody.sprite.setTexture(cBody.texture);
	return input;
}

//draw x and y position on window
void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	double scaled = (radius*2)/winX;
       double x = xPos/scaled;
       double y = yPos/scaled;
	
	sf::Sprite sprite2 = sprite;
	sprite2.setPosition(x+(winX/2),y+(winY/2));
	target.draw(sprite2);
}

//overidden operator for outputting files
std::ostream& operator <<(std::ostream &os, CelestialBody &cBody)
{
	os << "PlanetName:" << cBody.planetName << std::endl;
	os << "Pos x:" << cBody.xPos << std::endl;
	os << "Pos y:" << cBody.yPos << std::endl;
	os << "Vel x:" << cBody.xVel << std::endl;
	os << "Vel y:" << cBody.yVel << std::endl;
	os << "Mass" << cBody.mass << std::endl;
	return os;	
}

void CelestialBody::setMass(double mass) {
	this->mass = mass;
}

void CelestialBody::setxPos(double xPos){
	this->xPos = xPos;
}

void CelestialBody::setyPos(double yPos){
	this->yPos = yPos; 
}

void CelestialBody::setxVel(double xVel){
	this->xVel = xVel;
} 

double CelestialBody::getMass(){
	return mass;
}

double CelestialBody::getxPos(){
	return xPos;
}

double CelestialBody::getyPos(){
	return yPos;
}

double CelestialBody::getxVel(){
	return xVel;
}

double CelestialBody::getyVel(){
	return yVel;
}


















































