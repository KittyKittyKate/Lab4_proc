#include "container.h"
#include "wisdom.h"
namespace collection_of_wisdom {
	// Инициализация контейнера
	void Init(container &c) { c.lenght = 0; };
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(container &c) {
		for (int i = 0; i < c.lenght; i++){
			delete c.cont[i];
		}
		c.lenght = 0;
	};
} // end collection_of_wisdom namespace