#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "CircularBuffer.h"

class StringSound {
	public:
		explicit StringSound(double frequency);
		explicit StringSound(std::vector<sf::Int16> init);
		~StringSound();
		void pluck();
		void tic();
		sf::Int16 sample();
		int time();
	private:
		CircularBuffer* CB;
		int numOfTic;
};
