#include "StringSound.h"
#include "CircularBuffer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <vector>
#include <stdexcept>
#include <exception>

StringSound::StringSound(double frequency){
	numOfTic = 0;
	if(frequency <= 0){
		throw std::invalid_argument("Frequency must be positive number");
	}
	else {
		CB = new CircularBuffer(ceil(44100 / frequency));
		while (!CB->isFull()){
			CB->enqueue(0);
		}	
	}
}

StringSound::StringSound(std::vector<sf::Int16> init){
	numOfTic = 0;
	if (init.size() <= 0){
		throw std::invalid_argument("Size must be positive numver");
	}
	else{
		CB = new CircularBuffer(init.size());
		int i = 0;
		while (!CB->isFull()){
			CB->enqueue(init[i]);
			i++;
		}
	}
}

StringSound::~StringSound(){
}

void StringSound::pluck(){
	if(CB->isFull()){
		while(!CB->isEmpty()){
			CB->dequeue();
		}
	}
	while(!CB->isFull()){
		CB->enqueue((rand()% INT16_MAX)+ 1);
	}
}

void StringSound::tic(){
	CB->enqueue(0.5 * 0.996 *(CB->dequeue() + CB->peek()));
	numOfTic++;
	if (numOfTic == 100 && CB->size() >= 100){
		std::vector<sf::Int16> queue;
		int i = 0;
		while (i<100 && !CB->isEmpty()){
			queue.push_back(CB->dequeue());
			i++;
		}
		i = 0;
		while (i < 99 && !CB->isFull()){
			CB->enqueue(queue.at(i));
			i++;
		}
	}
}

sf::Int16 StringSound::sample(){
	return CB->peek(); 
}

int StringSound::time(){
	return numOfTic;
}















