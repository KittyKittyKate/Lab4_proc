#include <fstream>
#include <iostream>
#include "puzzle.h"
using namespace std;
namespace collection_of_wisdom {
	// ֲגמה טח פאיכא
	void In(puzzle &a, ifstream &ifst) {
		ifst.getline(a.answer, 20);
	};
	void Out(puzzle &a, ofstream &ofst) {
		ofst << "' Answer: " << a.answer;
	};
	
} // end collection_of_wisdom namespace