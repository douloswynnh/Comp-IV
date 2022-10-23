#ifndef Triangle_H
#define Triangle_H

#include <string>
#include <SFML/Graphics.hpp>

class Triangle : public sf:: Drawable
{
	public:
		Triangle(double);
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		double length;
		
		sf:: ConvexShape triangle2;
		
		Triangle *triangleLeft;
		Triangle *triangleRight;
		Triangle *triangleUnder;
		
		void move(int x, int y);
		sf::Vector2f getPosition();
		
		void setOrigin(sf::Vector2f);
		void setFill(sf::Color);
		void addLeftChild(Triangle *triangle2);
		void addRightChild(Triangle *triangle2);
		void addUnderChild(Triangle *triangle2);
		
		Triangle* getLeft();
		Triangle* getRight();
		Triangle* getUnder();
		
};
#endif
//Triangle_H
