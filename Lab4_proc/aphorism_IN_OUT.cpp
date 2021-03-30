#include <fstream>
#include <iostream>
#include <string>
#include "aphorism.h"

using namespace std;

namespace collection_of_wisdom {
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	string In(aphorism &a, ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);
			Data = FindData("Author:", Full_Line);//В Data будет автор.
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //Если автора нет, то выбрасываем последующие строки и переходим к новой мудрости.
				string Junk; //Для мусора.
				getline(ifst, Junk); //Здесь - оценка.
				Junk.clear();
				return "error";
			}
			else if (Data.compare("empty") == 0) {//Если пустая строка.
				Exit_Flag = false; //Если false, то идем по циклу дальше.
			}
		} while ((ifst.eof() == false) && (Exit_Flag == false));

		if (ifst.eof()) {
			cout << "INFORMATION: the end of file." << endl;
			return "";
		}
		else { //Если не конец файла, то проверяем на переполнение.
			*a.author = CheckForOverflow(Data, a.author, ifst, 50);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	};
	void Out(aphorism &a, ofstream &ofst) {
		ofst << "' - " << a.author;
	};
}