#include <fstream>
#include <iostream>
#include <string>
#include "proverb.h"

using namespace std;

namespace collection_of_wisdom {
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	string In(proverb &p, ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);
			Data = FindData("Country:", Full_Line);//В Data будет страна.
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //Если страны нет, то выбрасываем последующие строки и переходим к новой мудрости.
				string Junk; //Для мусора.
				getline(ifst, Junk); //Здесь - оценка.
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {//если пустая строка
				Exit_Flag = false; // если false, то продолжаем цикл
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //Если не конец файла, то проверяем на переполнение.
			*p.country = CheckForOverflow(Data, p.country, ifst, 50);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	};
	void Out(proverb &p, ofstream &ofst) {
		ofst << "' - " << p.country;
	};
}