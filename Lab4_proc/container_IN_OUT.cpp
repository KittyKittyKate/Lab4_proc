#include <fstream>
#include "container.h"
using namespace std;
namespace collection_of_wisdom {
	// Сигнатуры требуемых внешних функций
	wisdom *In(ifstream &ifst);// Ввод содержимого контейнера из указанного потока
	int Count_Comma(wisdom &s);
	void In(container &c, ifstream &ifst) {
		while (!ifst.eof()) {
			if ((c.cont[c.lenght] = In(ifst)) != 0){ c.lenght++; }
		}
	};
	void Out(wisdom &s, ofstream &ofst);
	// Вывод содержимого контейнера в указанный поток
	void Out(container &c, ofstream &ofst) {
		ofst << "Container contains " << c.lenght
			<< " elements." << endl;
		for (int i = 0; i < c.lenght; i++) {
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
			ofst << "Count of comma: " << Count_Comma(*(c.cont[i])) << endl;
		}
	};
	bool Compare(wisdom *first, wisdom *second);
	// Сортировка содержимого контейнера
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
			/*else
				ofst << endl;*/
		}
	};
} // end collection_of_wisdom namespace