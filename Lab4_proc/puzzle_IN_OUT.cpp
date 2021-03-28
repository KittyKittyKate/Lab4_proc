#include <fstream>
#include <iostream>
#include <string>
#include "puzzle.h"
using namespace std;
namespace collection_of_wisdom {
	string FindData(const string &Text, string &Line);
	char& CheckForOverflow(string & Data, char char_text[], ifstream &ifst, int Len);
	// Ввод из файла
	string In(puzzle &a, ifstream &ifst) {
		string Full_Line;
		string Data;
		bool Exit_Flag = true;

		do {
			getline(ifst, Full_Line);//строка с ответа
			Data = FindData("Answer:", Full_Line);//В Data будет ответ
			Exit_Flag = true;

			if (Data.compare("error") == 0) { //если ответа нет, то выбрасываем послед. строки и переходим к новой мудрости
				string Junk; //для мусора
				getline(ifst, Junk); //Здесь - оценка
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
		else { //если не конец файла, то проверяем на переполнение
			*a.answer = CheckForOverflow(Data, a.answer, ifst, 20);
			Data.clear();
			Full_Line.clear();
			return "";
		}
	};
	void Out(puzzle &a, ofstream &ofst) {
		ofst << "' - Answer: " << a.answer;
	};
	
} // end collection_of_wisdom namespace