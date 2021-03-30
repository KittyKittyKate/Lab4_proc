#include "wisdom.h"
#ifndef __container__
#define __container__

namespace collection_of_wisdom {
	struct container
	{
		enum { max_len = 100 };
		int lenght;
		wisdom *cont[max_len];
	};
}
#endif