#include <fstream>
#include <iostream>
#include <string>
#include "wisdom.h"
using namespace std;
namespace collection_of_wisdom {
	// Сигнатуры требуемых внешних функций
	void In(aphorism &a, ifstream &ifst);
	void In(proverb &p, ifstream &ifst);
	void Out(aphorism &a, ofstream &ofst);
	void Out(proverb &p, ofstream &ofst);
	void In(puzzle &a, ifstream &ifst);
	void Out(puzzle &a, ofstream &ofst);
	// Ввод параметров обобщенной мудрости из файла
	wisdom* In(ifstream &ifst)
	{
		wisdom *sp;
		string Line; //Временное решение на случай переполнения
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new wisdom;
			sp->k = wisdom::key::APHORISM;
			getline(ifst, Line); //Строка заносится в Line
			if (Line.length() < 100) { //Проверка на переполнение - если длина Line < 100
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->a, ifst);
				ifst >> sp->rate;
				return sp;
			}
			else{
				Line.resize(99);
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->a, ifst);
				ifst >> sp->rate;
				return sp;
			}
		case 2:
			sp = new wisdom;
			sp->k = wisdom::key::PROVERB;
			getline(ifst, Line); //Строка заносится в Line
			if (Line.length() < 100) { //Проверка на переполнение - если длина Line < 100
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->p, ifst);
				ifst >> sp->rate;
				return sp;
			}
			else {
				Line.resize(99);
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->p, ifst);
				ifst >> sp->rate;
				return sp;
			}
		case 3:
			sp = new wisdom;
			sp->k = wisdom::key::PUZZLE;
			getline(ifst, Line); //Строка заносится в Line
			if (Line.length() < 100) { //Проверка на переполнение - если длина Line < 100
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->z, ifst);
				ifst >> sp->rate;
				return sp;
			}
			else {
				Line.resize(99);
				strcpy_s(sp->expression, 100, Line.c_str());
				In(sp->z, ifst);
				ifst >> sp->rate;
				return sp;
			}
		default:
			char Junk[100]; //для мусора
			ifst.getline(Junk, 100); //Здесь - выражение
			ifst.getline(Junk, 100); //Здесь - уникальная характеристика
			ifst.getline(Junk, 100); //Здесь - оценка
			return 0;
		}
		Line.clear();
	};
	// Вывод параметров текущей мудрости в поток
	void Out(wisdom &s, ofstream &ofst) {
		ofst << "'" << s.expression;
		switch (s.k) {
		case wisdom::key::APHORISM:
			Out(s.a, ofst);
			break;
		case wisdom::key::PROVERB:
			Out(s.p, ofst);
			break;
		case wisdom::key::PUZZLE:
			Out(s.z, ofst);
			break;
		default:
			ofst << "Incorrect wisdom!" << endl;
		}
		ofst << ". My rate: " << s.rate << endl;
	};
	int Count_Comma(wisdom &s) {
		int comma = 0;
		int i = 0;
		while (s.expression[i] != '\0')
		{
			if (s.expression[i] == ',') {
				comma++;
			}
			i++;
		}
		return comma;
	};	bool Compare(wisdom *first, wisdom *second) {
		return Count_Comma(*first) > Count_Comma(*second);
	};
} // end collection_of_wisdom namespace