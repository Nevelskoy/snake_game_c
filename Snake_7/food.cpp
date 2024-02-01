#include "const.h"
#include "field.h"
#include <stdlib.h>


void generate_food(int& m_food_X, bool& m_flag, int* m_field, int& m_size_field) {
	while (!m_flag) {
		m_food_X = rand() % m_size_field;
		if (m_field[m_food_X] == 0) {
			m_field[m_food_X] = food_symbol;
			m_flag = true;
		}
	}
}