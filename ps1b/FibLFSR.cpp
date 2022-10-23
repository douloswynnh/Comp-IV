#include "FibLFSR.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

FibLFSR::FibLFSR(string seed) {			//take in seed 
	for(int i = seed.size()-1; i>=0; i--){
		if(seed.at(i)=='1')
		{
			byte.push_back(seed.at(i)- '0');
		}
		else
		{
			byte.push_back((('0')- seed.at(i)));
		}
	}
    
}
int FibLFSR::step() {			//XOR 13,12,10 

    bit = byte.at(byte.size()-1) ^ (byte.at(13)) ^ (byte.at(12)) ^ (byte.at(10));
    byte.pop_back();
    byte.insert(byte.begin(), bit);
    return bit;
}


int FibLFSR::generate(int k) {	//binary to integer 

    int number = 0;
    for(int i=0; i<k; i++){
    	number *=2;
    	number += step();
	}
	return number;
}

ostream& operator<<(ostream &outStream, const FibLFSR &b ){	//output operator 
   for(int i = b.byte.size()-1; i>= 0; --i)
   {
   	outStream << (b.byte[i]);
   }
   return outStream;
}


