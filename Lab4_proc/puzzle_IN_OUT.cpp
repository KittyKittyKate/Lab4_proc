#include <fstream>
#include <iostream>
#include <string>
#include "puzzle.h"
using namespace std;
namespace collection_of_wisdom {
	// Ввод из файла
	void In(puzzle &a, ifstream &ifst) {
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); //Строка заносится в Line
		if (Line.length() < 20) { //Проверка на переполнение - если длина Line < 20
			strcpy_s(a.answer, 20, Line.c_str());
		}
		else {
			Line.resize(19);
			strcpy_s(a.answer, 20, Line.c_str());
		}
		Line.clear();
	};
	void Out(puzzle &a, ofstream &ofst) {
		ofst << "' - Answer: " << a.answer;
	};
	
} // end collection_of_wisdom namespace