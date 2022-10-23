#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

class FibLFSR {
public:

    FibLFSR(std::string seed); 					//constructor to create LFSR with the given initial seed
    int step(); 								// simulate one step and return the new bit as 0 or 1
    int generate(int k); 						// simulate k steps and return k-bit integer

    friend std::ostream& operator<<(std::ostream &outStream, const FibLFSR &b);
    std::vector<int> byte;

private:
    std::string seed;
    int tap,bit;
    
};

#endif //FIBLFSR_H
