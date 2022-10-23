#include <iostream>
#include "EDistance.h"
#include <SFML/System.hpp>

int main(){
	sf::Clock clock;
	sf::Time t;
	
	std::string x,y; 
	std::cin >> x >> y;
	
	EDistance ed(x,y);
	
	std::cout << "Edit Distance: " << ed.optDistance() << std::endl;
	//std::cout << ed << std::endl;
	t = clock.getElapsedTime();
	
	std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
	
}
