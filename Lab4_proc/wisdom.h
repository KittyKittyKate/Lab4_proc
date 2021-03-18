#ifndef __wisdom__
#define __wisdom__
// Подключение необходимых типов данных
#include "aphorism.h"
#include "proverb.h"
#include "puzzle.h"
namespace collection_of_wisdom {
	
	// структура, обобщающая всю мудрость
	struct wisdom {
		// значения ключей для каждой мудрости
		enum key { APHORISM, PROVERB, PUZZLE };
		key k; // ключ
		char expression[100];
		int rate;
		// используемые альтернативы
		union { // используем включение
			aphorism a;
			proverb p;
			puzzle z;
		};
	};
} // end collection_of_wisdom namespace
#endif