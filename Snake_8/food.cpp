#include <stdlib.h>
#include <ctime>
#include "const.h"


void generate_food(char** m_field, size_t& m_food_X, size_t& m_food_Y, bool& m_flag, const size_t& columns, const size_t& rows) {
	srand(time(0));
	while (!m_flag) {
		m_food_X = 1 + rand() % (columns - 2);
		m_food_Y = 1 + rand() % (rows - 2);
		if (m_field[m_food_X][m_food_Y] == 0) {
			m_field[m_food_X][m_food_Y] = food_symbol;
			m_flag = true;
		}
	}
}