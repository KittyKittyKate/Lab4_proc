#include <fstream>
#include "container.h"

using namespace std;

namespace collection_of_wisdom {
	wisdom *In(ifstream &ifst);
	int Count_Comma(wisdom &s);
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	void Out(wisdom &s, ofstream &ofst);
	bool Compare(wisdom *first, wisdom *second);
	void In(container &c, ifstream &ifst) {
		while (!ifst.eof()) {
			if ((c.cont[c.lenght] = In(ifst)) != 0){ c.lenght++; }
		}
	};
	void Out(container &c, ofstream &ofst) {
		ofst << "Container contains " << c.lenght << " elements." << endl;

		for (int i = 0; i < c.lenght; i++) {
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
			ofst << "Count of comma: " << Count_Comma(*(c.cont[i])) << endl;
		}
	};
	void Sort(container &c) {
		for (int i = 0; i < c.lenght - 1; i++) {
			for (int j = i + 1; j < c.lenght; j++) {
				if (Compare(c.cont[i], c.cont[j])) {
					wisdom *tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
				}
			}
		}
	};
	void OutAphorism(container &c, ofstream &ofst) {
		ofst << "Only aphorisms." << endl;

		for (int i = 0; i < c.lenght; i++) {
			if (c.cont[i]->k == wisdom::APHORISM) {
				ofst << i << ": ";
				Out(*(c.cont[i]), ofst);
				ofst << "Count of comma: " << Count_Comma(*(c.cont[i])) << endl;
			}
		}
	};
}