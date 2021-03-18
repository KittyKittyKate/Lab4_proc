#include "wisdom.h"
#ifndef __container__
#define __container__
namespace collection_of_wisdom {
	// Ссылка на описание мудрости.
	// Простейший контейнер на основе одномерного массива
	struct container
	{
		enum { max_len = 100 }; // максимальное количество элементов в контейнере
		int lenght; // актуальное количество элементов
		wisdom *cont[max_len];
	};
} // end collection_of_wisdom namespace
#endif