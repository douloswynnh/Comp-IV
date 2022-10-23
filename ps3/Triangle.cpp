#include "Triangle.h"

Triangle::Triangle(double length)
{
	triangle2 = sf::ConvexShape();
	triangle2.setPointCount(3);
	triangle2.setPoint(0, sf::Vector2f(0,0));
	triangle2.setPoint(1, sf::Vector2f(length,0));
	triangle2.setPoint(2, sf::Vector2f(length/2, length));
	this->length = length;
	
	return;
	
}

//mutator functions
void Triangle::move(int x, int y){
	triangle2.move(sf::Vector2f(x,y));
} 

sf::Vector2f Triangle::getPosition(){
	return triangle2.getPosition();
}

void Triangle::setOrigin(sf::Vector2f origin){
	this->triangle2.setOrigin(origin);
}

void Triangle::setFill(sf::Color color){
	triangle2.setFillColor(color);
}

void Triangle::addLeftChild(Triangle *triangleL){
	this->triangleLeft = triangleL;
} 

void Triangle::addRightChild(Triangle *triangleR){
	this->triangleRight = triangleR;
} 

void Triangle::addUnderChild(Triangle *triangleU){
	this->triangleUnder = triangleU;
}

Triangle* Triangle::getLeft(){
	return triangleLeft;
}

Triangle* Triangle::getRight(){
	return triangleRight;
}

Triangle* Triangle::getUnder(){
	return triangleUnder;
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states)const{
	target.draw(triangle2);
	if(this->triangleUnder != nullptr) target.draw(*triangleUnder);
	if(this->triangleRight != nullptr) target.draw(*triangleRight);
	if(this->triangleLeft != nullptr) target.draw(*triangleLeft);
	
	
} 


















