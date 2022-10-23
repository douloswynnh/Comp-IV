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
	os << "Radius" << cBody.radius << std::endl;
	os << "DeltaTime" << cBody.deltaTime << std::endl;
	os << "XForce" << cBody.xForce << std::endl;
	os << "YForce" << cBody.yForce << std::endl;
	os << "XAcceleration" << cBody.xAcc << std::endl;
	os << "YAcceleration" << cBody.yAcc << std::endl;
	return os;	
}

void CelestialBody::setxAcceleration(){
	xAcc = xForce / mass;
}

void CelestialBody::setyAcceleration(){
	yAcc = yForce / mass;
}

void CelestialBody::setxForce(double xForce){
	this->xForce = xForce;
}

void CelestialBody::setyForce(double yForce){
	this->yForce = yForce;
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

void CelestialBody::setxVel(double deltaTime){
	xVel = xVel + (deltaTime * xAcc);
} 

void CelestialBody::setyVel(double deltaTime){
	yVel = yVel - (deltaTime * yAcc);
} 

void CelestialBody::setNetForce(double prevMass, double r){
	NetForce = ((G*mass*prevMass)/r);
}

double CelestialBody::getxAcceleration(){
	return xAcc;
}

double CelestialBody::getyAcceleration(){
	return yAcc;
}

double CelestialBody::getxForce(){
	return xForce;
}

double CelestialBody::getyForce(){
	return yForce;
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

double CelestialBody::getNetForce(){
	return NetForce;
}


















































