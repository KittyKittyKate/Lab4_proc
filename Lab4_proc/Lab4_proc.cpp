#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;
namespace collection_of_wisdom {
	// Сигнатуры требуемых внешних функций
	void Init(container &c);
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void OutAphorism(container &c, ofstream &ofst);
	void Sort(container &c);
}
using namespace collection_of_wisdom;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc != 3) {
		cout << "Incorrect command line!"
			"Syntax: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	if (!ifst) {
		cout << "The file doesn't exist." << endl;
		return 0;
	}
	cout << "Let's begin" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container." << endl;
	Out(c, ofst);//обычный вывод контейнера
	ofst << "\n\nSorted container." << endl;
	Sort(c); // cортировка
	Out(c, ofst);//обычный вывод контейнера
	ofst << "\n\nAphorism container." << endl;
	OutAphorism(c, ofst); //вывод только афоризмов
	//Out(c, ofst); // вывод отсортированного контейнера
	Clear(c);
	ofst << "Empty container." << endl;
	//Out(c, ofst);
	cout << "Goodbye" << endl;
	return 0;
}