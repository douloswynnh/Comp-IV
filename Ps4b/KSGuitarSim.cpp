#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamplesFromString(StringSound gs) {
	std::vector<sf::Int16> samples;
	
	gs.pluck();
	int duration = 8;
	int i; 
	for (i = 0; i< SAMPLES_PER_SEC * duration; i++){
		gs.tic();
		samples.push_back(gs.sample());
	}
	return samples;
}

int main(){
	sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
	sf::Event event;
	double freq;
	int notes = 37;
	std::vector<sf::SoundBuffer> sb(notes);
	std::vector<sf::Sound> sd(notes);
	std::vector<std::vector<sf::Int16> > samples(notes);
	
	for(int i = 0; i<notes; i++){
		freq = 440 * pow(2, (i-24)/12.0);
		StringSound gs = StringSound(freq);
		samples.at(i) = makeSamplesFromString(gs);
		sb.at(i).loadFromSamples(&samples.at(i)[0], samples.at(i).size(), 2, SAMPLES_PER_SEC);
		sd.at(i).setBuffer(sb.at(i));
	}
	
	std::cout << "Loading is done" << std::endl;
	std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
	while (window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
			window.close();
			
			for (int i = 0; i<37; i++){
				if (event.type == sf::Event::TextEntered){
					if(event.text.unicode == keys.at(i)){
						sd.at(i).play();
					}
				}
			}
			window.clear();
			window.display();
		}
	}
	return 0;
}

























