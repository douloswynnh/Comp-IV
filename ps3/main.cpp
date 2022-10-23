#include <iostream>
#include <stdexcept>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "TFractal.h"
#include "Triangle.h"

int main(int argc, char* argv[])
{
	if(argc!=3){
		std::cout << "input length of triangle and number of iteration";
		return -1;
	}
	
	std::string length(argv[1]);
	std::string iteration(argv[2]);
	
	double Length = std::atoi(length.c_str());
	int width{(int)Length * 6};
	int height{(int)Length * 4};
	double Iteration = std::atoi(iteration.c_str());
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Window");
			TFractal *obj = new TFractal();
			obj->fTree(Iteration, Length, width, height);
			Triangle* triangle5= obj->triangle2;
			
			while(window.isOpen()){
				sf::Event event; 
				while(window.pollEvent(event)){
					if(event.type == sf::Event::Closed){
						window.close();
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
						window.close();
					}
				}
				window.clear();
				window.draw(*triangle5);
				window.display();
			}
			
		return 0;	
}
