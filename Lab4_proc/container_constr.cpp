#include "container.h"
#include "wisdom.h"

namespace collection_of_wisdom {
	void Init(container &c) { c.lenght = 0; };
	void Clear(container &c) {
		for (int i = 0; i < c.lenght; i++){
			delete c.cont[i];
		}

		c.lenght = 0;
	};
}