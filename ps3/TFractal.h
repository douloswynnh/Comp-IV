#ifndef TFractal_H
#define TFractal_H

#include "./Triangle.h"
#include <string>
#include <SFML/Graphics.hpp>

class TFractal{
	public:
		void fTree(int depth, double length, int WindowWidth, int WindowHeight);
		Triangle *triangle2;
		Triangle *fTree(Triangle* triangle3, int depth);
		
		void setChildPosition(Triangle *triangle3);
			
};
#endif
//TFractal_H
