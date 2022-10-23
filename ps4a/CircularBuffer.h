#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stdint.h>
#include <vector>
#include <stdexcept>
#include <iostream>

class CircularBuffer{
	public:
		CircularBuffer(int capacity);
		int size();
		bool isEmpty();
		bool isFull();
		void enqueue(int16_t x);
		int16_t dequeue();
		int16_t peek();
		
	private:
		int cap;
		std::vector<int16_t> vect;
};

#endif 
