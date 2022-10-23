#include <iostream>
#include <stdexcept>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "TFractal.h"
#include "Triangle.h"

void TFractal::fTree(int depth, double length, int WindowWidth, int WindowHeight){
	triangle2= new Triangle(length);
	triangle2-> move ((WindowWidth/2) - (length/2),(WindowHeight/2)-(length/2));
	triangle2->addLeftChild(fTree(triangle2,depth));
	triangle2->addRightChild(fTree(triangle2,depth));
	triangle2->addUnderChild(fTree(triangle2,depth));
	
	setChildPosition(triangle2);
}

Triangle* TFractal::fTree(Triangle *triangle3, int depth){
	if(depth<=0){
		return nullptr;
	}
	
	double baseLength = triangle3->length;
	
	Triangle *triangleChild = new Triangle(baseLength/2);
	triangleChild->addLeftChild(fTree(triangleChild, depth-1));
	triangleChild->addRightChild(fTree(triangleChild, depth-1));
	triangleChild->addUnderChild(fTree(triangleChild, depth-1));
	
	return triangleChild;
}

void TFractal::setChildPosition(Triangle* baseTriangle){
	if(baseTriangle == nullptr|| baseTriangle->triangleLeft==nullptr){
		return;
	}
	
	sf::Vector2f basePosition{ baseTriangle->getPosition()};
	double baseLength{ baseTriangle->length};
	double childLength{ baseLength/2};
	
	baseTriangle->triangleLeft->move(basePosition.x-childLength/2, basePosition.y-childLength);
	baseTriangle->triangleRight->move(basePosition.x + baseLength, basePosition.y);
	baseTriangle->triangleUnder->move(basePosition.x, basePosition.y+baseLength);
	
	setChildPosition(baseTriangle->triangleRight);
	setChildPosition(baseTriangle->triangleLeft);
	setChildPosition(baseTriangle->triangleUnder);
} 





























