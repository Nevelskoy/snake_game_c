#include <stdlib.h>
#include <ctime>
#include "const.h"
#include "food.h"
#include "field.h"


void st_food::generate_food(st_field& field) {
	srand(time(0));
	while (!m_food_flag) {
		m_food_X = 1 + rand() % (field.get_columns() - 2);
		m_food_Y = 1 + rand() % (field.get_rows() - 2);
		if (field.get_coor(m_food_X, m_food_Y) == 0) {
			field.set_char(m_food_X, m_food_Y, food_symbol);
			m_food_flag = true;
		}
	}
}

size_t st_food::get_foodX() const {
	return m_food_X;
}

size_t st_food::get_foodY() const {
	return m_food_Y;
}

bool st_food::get_flag() const {
	return m_food_flag;
}

void st_food::set_food_flag(const bool& new_flag) {
	m_food_flag = new_flag;
}

