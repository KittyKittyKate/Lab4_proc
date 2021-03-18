#include <fstream>
#include <iostream>
#include <string>
#include "aphorism.h"
using namespace std;
namespace collection_of_wisdom {
	// Ввод из файла
	void In(aphorism &a, ifstream &ifst) {
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); //Строка заносится в Line
		if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 50
			strcpy_s(a.author, 50, Line.c_str());
		}
		else {
			Line.resize(49);
			strcpy_s(a.author, 50, Line.c_str());
		}
		Line.clear();
	};
	void Out(aphorism &a, ofstream &ofst) {
		ofst << "' - " << a.author;
	};
} // end collection_of_wisdom namespace