#ifndef EDISTANCE_H
#define EDISTANCE_H
#include <string>

class EDistance{
	public:
		EDistance(std::string, std::string);
		~EDistance();
		static int penalty(char a, char b);
		static int min(int a, int b, int c);
		int optDistance();
		std::string alignment();
		friend std::ostream& operator<<(std::ostream&, EDistance&);
		
	private:
		int** opt;
		std::string xString, yString;
};

#endif
