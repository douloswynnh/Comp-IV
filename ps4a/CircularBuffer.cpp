#include "CircularBuffer.h"
#include <vector>

int CircularBuffer::size(){
	return vect.size();
}

bool CircularBuffer::isEmpty(){
	if(vect.empty())
		return true;
	else
		return false;
}

CircularBuffer::CircularBuffer(int capacity){
	if(capacity == 0){
		throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
		
	}
	cap = capacity;
}

bool CircularBuffer::isFull(){
	if(vect.size() == cap)
		return true;
	else
		return false;
}

void CircularBuffer::enqueue(int16_t x){
	if (isFull()){
		throw std::runtime_error("enqueue: can't enqueue to a full ring.");
	}
	vect.push_back(x);
}

int16_t CircularBuffer::dequeue(){
	int16_t t = peek();
	vect.erase(vect.begin());
	return t;
}

int16_t CircularBuffer::peek(){
	if (isEmpty()){
		throw std::runtime_error("CircularBuffer is empty.");
	}
	return vect.at(0);
}






















