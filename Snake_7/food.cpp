#include "const.h"
#include "field.h"
#include <stdlib.h>
#include <ctime>


void generate_food(int& m_food_X, int& m_food_Y, bool& m_flag, char(*m_field)[rows]) {
	srand(time(0));
	while (!m_flag) {
		m_food_X = rand() % visual_max_X + 1;
		m_food_Y = rand() % visual_max_Y + 1;
		if (m_field[m_food_X][m_food_Y] == 0) {
			m_field[m_food_X][m_food_Y] = food_symbol;
			m_flag = true;
		}
	}
}