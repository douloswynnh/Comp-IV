#include "Universe.h"

void Universe::readFile(){
	std::cin >> numberOfPlanets;
	std::cin >> radius;
	
	for(int i =0; i< numberOfPlanets; ++i){
		std::shared_ptr<CelestialBody> planet(new CelestialBody(radius));
		std::cin >> *planet;
		SolarSystem.push_back(planet);
		
	}
	
}

void Universe::drawUniverse(){
	if(!texture.loadFromFile("background.jpg")){
		std::cout << "no background file" << std::endl;
	}
	
	sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "Universe");
	sprite.setTexture(texture);
	
	while(window.isOpen()){
		sf::Event event;
		
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		
		window.draw(sprite);
		
		for(int i=0;i<numberOfPlanets; ++i){
		(*(SolarSystem).at(i)).windowSize(texture.getSize().x,texture.getSize().y);
		window.draw((*(SolarSystem.at(i))));
		}
		
		
		window.display();
	}
}
