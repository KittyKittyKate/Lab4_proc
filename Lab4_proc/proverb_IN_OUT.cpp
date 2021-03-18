#include <fstream>
#include <iostream>
#include "proverb.h"
using namespace std;
namespace collection_of_wisdom {
	// ֲגמה טח פאיכא
	void In(proverb &p, ifstream &ifst)
	{
		ifst.getline(p.country, 50);
	};
	void Out(proverb &p, ofstream &ofst)
	{
		ofst << "' - " << p.country;
	};
	
} // end collection_of_wisdom namespace