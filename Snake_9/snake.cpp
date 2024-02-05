#include <stdlib.h>
#include <iostream>
#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"


size_t st_snake::get_size() const {
	return m_snake_size;
}

size_t st_snake::get_snake_X(const size_t& x) const {
	return m_snake_X[x];
}

size_t st_snake::get_snake_Y(const size_t& y) const {
	return m_snake_Y[y];
}

DIRECTIONS st_snake::get_direct() const {
	return m_current_mov;
}

void st_snake::set_snake_X(const size_t& idx, const size_t& value) {
	m_snake_X[idx] = value;
}

void st_snake::set_snake_Y(const size_t& idx, const size_t& value) {
	m_snake_Y[idx] = value;
}

void st_snake::set_direct(DIRECTIONS&& new_direct) {
	m_current_mov = new_direct;
}

void st_snake::up_size() {
	++m_snake_size;
}


void st_snake::init_snake(st_field& field, st_game& game) {
	if (m_snake_size > field.get_columns() - 2) {
		game.set_flag_game(false);
		std::cout << "The snake size should be smaller than " << field.get_columns() + 1 << " !!!" << std::endl;
	}
	size_t start_snake = field.get_columns() / 2;
	if (m_snake_size > field.get_columns() / 2) {
		start_snake = field.get_columns() - 2;
	}

	for (size_t i = 0; i < m_snake_size; i++) {
		m_snake_X[i] = start_snake - i;
		m_snake_Y[i] = field.get_rows() / 2;
	}
}

// В связи с тем, что положение хвоста рассчитывается по положению головы,
// нам достаточно изменить только местоположение головы.
void st_snake::move_snake(st_field& field) {
	for (size_t i = m_snake_size; i > 0; --i) {
		m_snake_X[i] = m_snake_X[i - 1];
		m_snake_Y[i] = m_snake_Y[i - 1];
	}

	if (m_current_mov == RIGHT) {
		m_snake_X[0]++;
	}	else if (m_current_mov == LEFT) {
		m_snake_X[0]--;
	}

	if (m_current_mov == UP) {
		m_snake_Y[0]--;
	}	else if (m_current_mov == DOWN) {
		m_snake_Y[0]++;
	}

	if (m_snake_X[0] > field.get_columns() - 2) {
		m_snake_X[0] = 1;
	}	else if (m_snake_X[0] < 1) {
		m_snake_X[0] = field.get_columns() - 2;
	}

	if (m_snake_Y[0] > field.get_rows() - 2) {
		m_snake_Y[0] = 1;
	}	else if (m_snake_Y[0] < 1) {
		m_snake_Y[0] = field.get_rows() - 2;
	}
}

// Строим змейку в поле массива field 
void st_snake::build_snake(st_field& field) {
	for (size_t i = 1; i < m_snake_size; i++) {
		field.set_char(m_snake_X[i], m_snake_Y[i], tail_symbol);
	}
	field.set_char(m_snake_X[0], m_snake_Y[0], head_symbol);
}

void st_snake::clear_snake(st_field& field) {
	field.set_char(m_snake_X[m_snake_size], m_snake_Y[m_snake_size], 0);
}
