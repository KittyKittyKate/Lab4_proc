#include "container.h"
#include "wisdom.h"
#include <fstream>

using namespace std;

namespace collection_of_wisdom {
	void Out(wisdom &s, ofstream &ofst);
	void MultiMethod(container &c, ofstream &ofst) {
		ofst << "Multimethod." << endl;

		for (int i = 0; i < c.lenght - 1; i++) {
			for (int j = i + 1; j < c.lenght; j++) {
				switch (c.cont[i]->k) {
				case wisdom::APHORISM:
					switch (c.cont[j]->k) {
					case wisdom::APHORISM:
						ofst << "APHORISM and APHORISM." << endl;
						break;
					case wisdom::PROVERB:
						ofst << "APHORISM and PROVERB." << endl;
						break;
					case wisdom::PUZZLE:
						ofst << "APHORISM and PUZZLE." << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				case wisdom::PROVERB:
					switch (c.cont[j]->k) {
					case wisdom::APHORISM:
						ofst << "PROVERB and APHORISM." << endl;
						break;
					case wisdom::PROVERB:
						ofst << "PROVERB and PROVERB." << endl;
						break;
					case wisdom::PUZZLE:
						ofst << "PROVERB and PUZZLE." << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				case wisdom::PUZZLE:
					switch (c.cont[j]->k) {
					case wisdom::APHORISM:
						ofst << "PUZZLE and APHORISM." << endl;
						break;
					case wisdom::PROVERB:
						ofst << "PUZZLE and PROVERB." << endl;
						break;
					case wisdom::PUZZLE:
						ofst << "PUZZLE and PUZZLE." << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
				default:
					ofst << "Unknown type" << endl;
				}
				Out(*(c.cont[i]), ofst);
				Out(*(c.cont[j]), ofst);
				break;
			}
		}
	}}