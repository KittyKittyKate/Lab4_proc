#include <fstream>
#include <iostream>
#include <string>
#include "wisdom.h"

using namespace std;

namespace collection_of_wisdom {
	string In(aphorism &a, ifstream &ifst);
	string In(proverb &p, ifstream &ifst);
	string In(puzzle &a, ifstream &ifst);
	void Out(aphorism &a, ofstream &ofst);
	void Out(proverb &p, ofstream &ofst);
	void Out(puzzle &a, ofstream &ofst);
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	wisdom* In(ifstream &ifst)
	{
		wisdom *sp;
		int k = 0;
		bool Exit_Flag = true;
		string Full_Line;
		getline(ifst, Full_Line);
		string Data = FindData("Type of wisdom:", Full_Line);

		if (Data.compare("error") != 0 && Data.compare("empty") != 0) {//Если НЕ "ошибка"(данные не введены) И НЕ "пусто"(пустая строка).
			try {
				if (isdigit(Data[0]) == 0) {
					throw Data;//Если Data - строка, а не число.
				}
				if (static_cast<int>(stoi(Data, 0, 10)) > INT_MAX) {
					cout << "ERROR: overflow (Type of wisdom > INT_MAX)." << endl;
				}
				else if (static_cast<int>(stoi(Data, 0, 10)) < INT_MIN) {
					cout << "ERROR: overflow (Type of wisdom < INT_MIN)." << endl;
				}
				else {//Если с типом все хорошо.
					k = static_cast<int>(stoi(Data, 0, 10));
				}
			}
			catch (string Data) {
				cout << "ERROR: 'Type of wisdom' should be int ('Type of wisdom' == " << Data << ")." << endl;
				k = 0;
			}

		}
		else if (Data.compare("empty") == 0) { // если "пусто"(пустая строка)
			return 0;
		}

		switch (k) {
		case 1:
			sp = new wisdom;
			sp->k = wisdom::key::APHORISM;
			break;
		case 2:
			sp = new wisdom;
			sp->k = wisdom::key::PROVERB;
			break;
		case 3:
			sp = new wisdom;
			sp->k = wisdom::key::PUZZLE;
			break;
		default:
			string Junk; //для мусора
			getline(ifst, Junk); //Здесь - выражение
			getline(ifst, Junk); //Здесь - уникальная характеристика
			getline(ifst, Junk); //Здесь - оценка
			Junk.clear();
			return 0;
		}

		do {
			getline(ifst, Full_Line);
			Data = FindData("Expression:", Full_Line);
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //Если выражения нет, то выбрасываем последующие строки и переходим к новой мудрости.
				delete[] sp;
				string Junk; //Для мусора.
				getline(ifst, Junk); //Здесь - уникальная характеристика.
				getline(ifst, Junk); //Здесь - оценка.
				Junk.clear();
				return 0;
			}
			else if (Data.compare("empty") == 0) {//Если пустая строка.
				Exit_Flag = false; //Если false, то идем по циклу дальше.
			}

		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}
		else { //Если не конец файла.
			*sp->expression = CheckForOverflow(Data, sp->expression, ifst, 100);//Проверка выражения на переполнение, занесение выражения в expression.
		}
		
		switch (sp->k) {
		case wisdom::key::APHORISM:
			if (In(sp->a, ifst) == "error") {
				return 0;
			}

			if (ifst.eof()) {//Если конец файла, то выход.
				return 0;
			}//Иначе продолжаем.
			break;
		case wisdom::key::PROVERB:
			if (In(sp->p, ifst) == "error") {
				delete[] sp;
				return 0;
			}

			if (ifst.eof()) {//Если конец файла, то выход.
				return 0;
			}//Иначе продолжаем.
			break;
		case wisdom::key::PUZZLE:
			if (In(sp->z, ifst) == "error") {
				return 0;
			}

			if (ifst.eof()) {//Если конец файла, то выход.
				return 0;
			}//Иначе продолжаем.
			break;
		}
		
		do {//Ищем оценку.
			getline(ifst, Full_Line);
			Data = FindData("Rate:", Full_Line);

			if (Data.compare("error") != 0 && Data.compare("empty") != 0) {//Если НЕ "ошибка"(данные не введены) И НЕ "пусто"(пустая строка).
				try {
					if (isdigit(Data[0]) == 0) {
						throw Data;//Если Data - строка, а не число.
					}

					if (static_cast<int>(stoi(Data, 0, 10)) > 10) {
						delete[] sp;
						cout << "ERROR: unexpected value (Rate > 10)." << endl;
						return 0;
					}
					else if (static_cast<int>(stoi(Data, 0, 10)) < 0) {
						delete[] sp;
						cout << "ERROR: unexpected value (Rate < 10)." << endl;
						return 0;
					}
					else {//Если с оценкой все хорошо.
						sp->rate = static_cast<int>(stoi(Data, 0, 10));
						Full_Line.clear();
						Data.clear();
						return sp;
					}
				}
				catch (string Data) {
					cout << "ERROR: 'Rate' should be int ('Rate' == " << Data << ")." << endl;
					delete[] sp;
					return 0;
				}

			}
			else if (Data.compare("empty") == 0) { //Если "пусто"(пустая строка), то идем на следующую строку.
				Exit_Flag = false;
			}
			else if (Data.compare("error") == 0) {
				cout << "ERROR: misprint in field 'Rate:'." << endl;
				delete[] sp;
				return 0;
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return 0;
		}
		return 0;
	};
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
		while (s.expression[i] != '\0') {
			if (s.expression[i] == ',') {
				comma++;
			}

			i++;
		}
		return comma;
	};	bool Compare(wisdom *first, wisdom *second) {
		return Count_Comma(*first) > Count_Comma(*second);
	};	string FindData(const string &Text, string &Line) {
		string Data;

		if (Line.compare("") == 0) {
			cout << "Empty line." << endl;
			return "empty";
		}

		try {
			int Position = static_cast<int>(Line.find(Text));

			if (Position != 0) {
				throw Position;
			}

			try {//Если  Position == 0.
				int Difference = static_cast<int>(Line.length()) - static_cast<int>(Text.length());

				if (Difference == 0) {
					throw Text;
				}

				Data = Line.substr(static_cast<int>(Text.length()), Difference);
				return Data;
			}
			catch (string s) {
				cout << "ERROR: the data is empty (" << s << ")." << endl;
				return "error";
			}
		}
		catch (int Position) {
			if (Position != -1) { //Если данные маленько сдвинуты.
				cout << "WARNING: unexpected format of data (" << Line.substr(0, Position + static_cast<int>(Text.length())) << ")." << endl;
				Data = Line.substr(Position + static_cast<int>(Text.length()), static_cast<int>(Line.length()) - 1);
				return Data;
			}
			else if (Position == -1) { //Если данные введены неправильно.
				cout << "ERROR: incorrect data format." << endl;
				return "error";
			}
		}
	};	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len) {
		if (static_cast<int>(Data.length()) < Len) { //Проверка на переполнение - если длина данных < Len, то просто заносим выражение в переменную.
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
		else { //Иначе придется отсечь лишнее.
			Data.resize(Len - 1);
			strcpy_s(char_text, Len, Data.c_str());
			return *char_text;
		}
	};
}