#ifndef PS6_RandWriter_H_	
#define PS6_RandWriter_H_

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <fstream>

class RandWriter {
	private:
		std::string inputText, outputText, text;
		int k, outputLength;
		
		std::multimap<std::string, std::pair<char, int> > kgramMap;

	public:
		RandWriter(std::string, int);
		int orderK();
		int freq(std::string, char);
		int freq(std::string);
		char kRand(std::string);
		std::string generate(std::string, int);
		
		friend std::ostream& operator << (std::ostream&, RandWriter&);		
};

#endif
