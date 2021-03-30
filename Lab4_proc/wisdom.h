#ifndef __wisdom__
#define __wisdom__
#include "aphorism.h"
#include "proverb.h"
#include "puzzle.h"

namespace collection_of_wisdom {
	struct wisdom {
		enum key { APHORISM, PROVERB, PUZZLE };
		key k;
		char expression[100];
		int rate;

		union {
			aphorism a;
			proverb p;
			puzzle z;
		};
	};
}
#endif