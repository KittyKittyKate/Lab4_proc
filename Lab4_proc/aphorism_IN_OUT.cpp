#include <fstream>
#include <iostream>
#include "aphorism.h"
using namespace std;
namespace collection_of_wisdom {
	// ���� �� �����
	void In(aphorism &a, ifstream &ifst) {
		ifst.getline(a.author, 50);
	};
	void Out(aphorism &a, ofstream &ofst) {
		ofst << "' - " << a.author;
	};
} // end collection_of_wisdom namespace