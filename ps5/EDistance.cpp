#include "EDistance.h"
#include <iostream>

EDistance::EDistance(std::string x, std::string y){
	xString = x + "-";
	yString = y + "-";
	
	opt = new int*[xString.length()];
	for (int i = 0; i < xString.length(); ++i){
		opt[i] = new int[yString.length()];
	}
}

EDistance::~EDistance(){
	for(int i = 0; i<xString.length(); ++i){
		delete [] opt[i];
	}
	delete [] opt;
}

int EDistance::penalty(char x, char y){
	return (x!=y);
}

int EDistance::min(int down, int right, int diagonal){
	return std::min(std::min(down, right), diagonal);
}

int EDistance::optDistance(){
	int num = 0;
	for(int i = xString.length()-1; i>=0; i--){
		opt[i][yString.length()-1] = num * 2;
		num++;
	}
	num = 0;
	for(int j = yString.length()-1; j>=0; j--){
		opt[xString.length()-1][j] = num * 2;
		num++;
	}
	
	for(int i = xString.length()-1; i >0; i--){
		for(int j = yString.length()-1; j>0; j--){
			int minNum = min(opt[i][j-1] + 2, opt[i-1][j] + 2, opt[i][j] + (penalty(xString.at(i-1), yString.at(j-1))));
			opt[i-1][j-1] = minNum;
		}
	}
	return opt[0][0];
}

std::string EDistance::alignment(){
	return std::string();
}

std::ostream &operator << (std::ostream &os, EDistance &ed){
	os << ed.xString << ed.yString;
	return os;
}
















