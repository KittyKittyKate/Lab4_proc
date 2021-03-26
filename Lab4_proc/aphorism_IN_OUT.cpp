#include <fstream>
#include <iostream>
#include <string>
#include "aphorism.h"
using namespace std;
namespace collection_of_wisdom {
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	// ¬вод из файла
	string In(aphorism &a, ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);//строка с автором
			Data = FindData("Author:", Full_Line);//¬ Data будет автор
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //если автора нет, то выбрасываем послед. строки и переходим к новой мудрости
				delete[] &a;
				string Junk; //дл€ мусора
				getline(ifst, Junk); //«десь - оценка
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {//если пуста€ строка
				Exit_Flag = false; // если false, то продолжаем цикл
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //если не конец файла, то провер€ем на переполнение
			*a.author = CheckForOverflow(Data, a.author, ifst, 50);
			/*if (static_cast<int>(Data.length()) < 50) { //ѕроверка на переполнение - если длина данных < Len, то просто заносим выражение в переменную
				strcpy_s(a.author, 50, Data.c_str());
			}
			else { //иначе придетс€ отсечь лишнее
				Data.resize(49);
				strcpy_s(a.author, 50, Data.c_str());
			}*/
			Data.clear();
			Full_Line.clear();
			return "";
		}
	};
	void Out(aphorism &a, ofstream &ofst) {
		ofst << "' - " << a.author;
	};
} // end collection_of_wisdom namespace