//header files 
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"
#include <sstream>

//transforms image using FibLFSR
void transform(sf:: Image *pic, FibLFSR *byte){
	sf::Image image = *pic;
	sf::Vector2u size = pic->getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y),"Input");
	
	sf::Texture texture; 
	texture.loadFromImage(image);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sf::Color p;
	
	// create photographic negative image of upper-left image px square
	for(int x= 0;x<(int)image.getSize().x;x++)	{
		for (int y = 0; y< (int)image.getSize().y; y++) {
			p = pic->getPixel(x,y);
			p.r = 255 - p.r;
			p.g = 255 - p.g;
			p.b = 255 - p.b;
			
			p.r = p.r - byte->generate(10);
			p.g = p.g - byte->generate(10);
			p.b = p.b - byte->generate(10);
			
			pic->setPixel(x,y,p);
		}
	}	
	//output image rendering 
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");
	
	sf::Texture texture2;
	texture2.loadFromImage(*pic);
	
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	
	while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}
		while(window2.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window2.close();
		}

		window1.clear();
		window1.draw(sprite);
		window1.display();
		window2.clear();
		window2.draw(sprite2);
		window2.display();
	}
	
}

//main function
int main(int argc, char* argv[])
{
	FibLFSR l = FibLFSR(argv[3]);
	sf::Image image;
	
	if(!image.loadFromFile(argv[1]))
	{
		return -1;
	}
	else 
	{
		transform(&image, &l);
	}
	
	if(!image.saveToFile(argv[2]))
	{
		std::cout << "unable to save" << std:: endl;
	}

	return 0;
}
