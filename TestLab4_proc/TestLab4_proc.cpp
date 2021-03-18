#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab4_proc/container.h"
#include "../Lab4_proc/container_constr.cpp"
#include "../Lab4_proc/container_IN_OUT.cpp"
#include "../Lab4_proc/wisdom.h"
#include "../Lab4_proc/wisdom_IN_OUT.cpp"
#include "../Lab4_proc/aphorism.h"
#include "../Lab4_proc/puzzle.h"
#include "../Lab4_proc/proverb.h"
#include "../Lab4_proc/proverb_IN_OUT.cpp"
#include "../Lab4_proc/aphorism_IN_OUT.cpp"
#include "../Lab4_proc/puzzle_IN_OUT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace collection_of_wisdom;
using namespace std;

int Difference(ifstream &ifst_1, ifstream &ifst_2);

namespace TestLab4proc
{
	TEST_CLASS(TestLab4proc)
	{
	public:
		
		TEST_METHOD(Container_In_7) //Проверка функции In для контейнера
		{
			ifstream ifst("in_7.txt"); //В файле 7 мудростей
			container c;
			Init(c);
			In(c, ifst);
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 7);//OK
			Clear(c);
		}
		TEST_METHOD(Container_In_0) //Проверка функции In для контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			container c;
			Init(c);
			In(c, ifst);
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 0);//OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_In_7) //Проверка функции In для класса wisdom
		{
			ifstream ifst("in_7_with_incorrect_keys.txt"); //В файле 7 мудростей, 3 мудрости с неправильными ключами
			container c;
			Init(c);
			In(c, ifst);
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 4);//OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_7) //Проверка функции Sort для контейнера
		{
			ifstream ifst("in_7.txt"); //В файле 7 мудростей
			ofstream ofst("out_7.txt");
			container c;
			Init(c);
			In(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			Out(c, ofst);
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 7); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_0) //Проверка функции Sort для пустого контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			ofstream ofst("out_0.txt");
			container c;
			Init(c);
			In(c, ifst);
			Sort(c); //OK, сортировка не произошла
			Out(c, ofst); //В выходном файле "Container contents 0 elements."
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_1) //Проверка функции Sort для контейнера с одним элементом
		{
			ifstream ifst("in_1.txt"); //В файле один элемент
			ofstream ofst("out_1.txt");
			container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, сортировка не произошла
			Out(c, ofst); //В выходном файле "Container contents 1 elements."
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 1); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_2) //Проверка функции Sort для контейнера с двумя элементами
		{
			ifstream ifst("in_2.txt"); //В файле два элемента
			ofstream ofst("out_2.txt");
			container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, сортировка ведет себя адекватно 
			Out(c, ofst); //В выходном файле "Container contents 2 elements."
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 2); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutAphorisms_0) //Проверка функции OutAphorisms для пустого контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			ofstream ofst("out_0.txt");
			container c;
			Init(c);
			In(c, ifst);
			OutAphorism(c, ofst); //В выходном файле "Only aphorisms."
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutAphorisms_without_aphors) //Проверка функции OutAphorisms контейнера без афоризмов
		{
			ifstream ifst("in_5_without_aphors.txt"); //В файле 5 мудростей
			ofstream ofst("out_5_without_aphors.txt");
			container c;
			Init(c);
			In(c, ifst);
			OutAphorism(c, ofst); //В выходном файле "Only aphorisms."
			int real_len = c.lenght;
			Assert::AreEqual(real_len, 5); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_InData_OverBuf) //Проверка функции InData на поведение в случае переполнения
		{
			ifstream ifst("in_1_overbuf.txt"); //В файле один афоризм с выражением > 100 символов
			ofstream ofst("out_1_overbuf.txt");
			ifstream ifst_IDEAL("in_1_overbuf_IDEAL.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_0) //Проверка функции CountOfComma в случае 0 запятых
		{
			ifstream ifst("in_0_commas.txt"); //В выражении нет запятых
			ofstream ofst("out_0_commas.txt");
			ifstream ifst_IDEAL("out_0_commas_IDEAL.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_0_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_1) //Проверка функции CountOfComma в случае 1 запятых
		{
			ifstream ifst("in_1_comma.txt"); //В выражении 1 запятая
			ofstream ofst("out_1_comma.txt");
			ifstream ifst_IDEAL("out_1_comma_IDEAL.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_comma.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_5) //Проверка функции CountOfComma в случае 5 запятых
		{
			ifstream ifst("in_5_commas.txt"); //В выражении 5 запятых
			ofstream ofst("out_5_commas.txt");
			ifstream ifst_IDEAL("out_5_commas_IDEAL.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_5_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Clean_0) //Проверка очистки контейнера при отсутствии элементов
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			container c;
			Init(c);
			In(c, ifst);
			Clear(c);//OK, цикл не начинался
			Assert::AreEqual(c.lenght, 0); //OK
		}
		TEST_METHOD(A_P_P_OverBuf) //Проверка функций InData трех подклассов на поведение в случае переполнения
		{
			ifstream ifst("in_3_overbuf.txt"); //В файле 3 мудрости с переполненными уник. хар-ми 
			ofstream ofst("out_3_overbuf.txt");
			ifstream ifst_IDEAL("out_3_overbuf_IDEAL.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_3_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK 
			Clear(c);
		}
	};
}

int Difference(ifstream & ifst_1, ifstream & ifst_2)
{
	char ch_1 = '0';
	char ch_2 = '0';

	while (ifst_1.get(ch_1) && ifst_2.get(ch_2)) {
		if (ch_1 != ch_2)
		{
			return 0;
		}
	}
	return 1;
}
