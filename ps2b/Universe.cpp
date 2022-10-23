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
		//(*(SolarSystem).at(i)).windowSize(texture.getSize().x,texture.getSize().y);
		window.draw(*(SolarSystem.at(i)));
		}
		
		
		window.display();
	}
}

void Universe::step(double time, double deltaTime){
	if(!texture.loadFromFile("background.jpg")){
		std::cout << "no background file" << std::endl;
	}
	
	sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "Universe");
	sprite.setTexture(texture);
	sf::Music music;
  	if(!music.openFromFile("music.ogg"))
  	{
  	  std::cout <<  "no music" << std::endl; 
  	}
  	music.play();
	
	for(int i = 0; i< time; i+= deltaTime){
		sf::Event event;
		
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.draw(sprite);
		
		for (int j =0; j<numberOfPlanets; ++j){
			for(int k =0; k<numberOfPlanets; ++k){
				if(j != k){
					(*(SolarSystem).at(j)).windowSize(texture.getSize().x,texture.getSize().y);
					
					deltaX = (*(SolarSystem).at(k)).getxPos() - (*(SolarSystem).at(j)).getxPos();
					deltaY = (*(SolarSystem).at(k)).getyPos() - (*(SolarSystem).at(j)).getyPos();
					
					r = sqrt((deltaX * deltaX) + (deltaY * deltaY));
					
					(*(SolarSystem).at(j)).setNetForce((*(SolarSystem).at(k)).getMass(), r * r);
					
					xForce = (*(SolarSystem).at(j)).getNetForce() * (deltaX / r);
					yForce = (*(SolarSystem).at(j)).getNetForce() * (deltaY / r);
					
					(*(SolarSystem).at(j)).setxForce(xForce);
					(*(SolarSystem).at(j)).setyForce(yForce);
					
					(*(SolarSystem).at(j)).setxAcceleration();
					(*(SolarSystem).at(j)).setyAcceleration();
					
					(*(SolarSystem).at(j)).setxVel(deltaTime);
					(*(SolarSystem).at(j)).setyVel(deltaTime);
				}
			}
			
			newXPos = (*(SolarSystem).at(j)).getxPos() + (deltaTime * (*(SolarSystem).at(j)).getxVel());
			newYPos = (*(SolarSystem).at(j)).getyPos() - (deltaTime * (*(SolarSystem).at(j)).getyVel());
			
			(*(SolarSystem).at(j)).setxPos(newXPos);
			(*(SolarSystem).at(j)).setyPos(newYPos);
			window.draw(*(SolarSystem).at(j));
			
		}
		window.display();
	}
	//drawUniverse();	
}


























