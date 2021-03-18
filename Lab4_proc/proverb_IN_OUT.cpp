#include <fstream>
#include <iostream>
#include <string>
#include "proverb.h"
using namespace std;
namespace collection_of_wisdom {
	// Ввод из файла
	void In(proverb &p, ifstream &ifst)
	{
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); //Строка заносится в Line
		if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 50
			strcpy_s(p.country, 50, Line.c_str());
		}
		else {
			Line.resize(49);
			strcpy_s(p.country, 50, Line.c_str());
		}
		Line.clear();
	};
	void Out(proverb &p, ofstream &ofst)
	{
		ofst << "' - " << p.country;
	};
	
} // end collection_of_wisdom namespace