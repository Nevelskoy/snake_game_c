#include <stdlib.h>
#include <iostream>
#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"


void init_snake(size_t* m_snake_X, size_t* m_snake_Y, size_t& m_snake_size, bool& flag_game, const size_t& columns, const size_t& rows) {
	if (m_snake_size > columns - 2) {
		flag_game = false;
		std::cout << "The snake size should be smaller than " << columns + 1 << " !!!" << std::endl;
	}
	size_t start_snake = columns / 2;
	if (m_snake_size > columns / 2) {
		start_snake = columns - 2;
	}

	for (size_t i = 0; i < m_snake_size; i++) {
		m_snake_X[i] = start_snake - i;
		m_snake_Y[i] = rows / 2;
	}
}

// ¬ св€зи с тем, что положение хвоста рассчитываетс€ по положению головы,
// нам достаточно изменить только местоположение головы.
void move_snake(size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size, DIRECTIONS& m_current_mov, const size_t& columns, const size_t& rows) {
	for (size_t i = m_snake_size; i > 0; --i) {
		m_snake_X[i] = m_snake_X[i - 1];
		m_snake_Y[i] = m_snake_Y[i - 1];
	}

	if (m_current_mov == RIGHT) {
		m_snake_X[0]++;
	}
	else if (m_current_mov == LEFT) {
		m_snake_X[0]--;
	}

	if (m_current_mov == UP) {
		m_snake_Y[0]--;
	}
	else if (m_current_mov == DOWN) {
		m_snake_Y[0]++;
	}

	if (m_snake_X[0] > columns - 2) {
		m_snake_X[0] = 1;
	}
	else if (m_snake_X[0] < 1) {
		m_snake_X[0] = columns - 2;
	}

	if (m_snake_Y[0] > rows - 2) {
		m_snake_Y[0] = 1;
	}
	else if (m_snake_Y[0] < 1) {
		m_snake_Y[0] = rows - 2;
	}
}

// —троим змейку в поле массива field 
void build_snake(char** m_field, size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size) {
	for (size_t i = 1; i < m_snake_size; i++) {
		m_field[m_snake_X[i]][m_snake_Y[i]] = tail_symbol; // отображение змейки
	}
	m_field[m_snake_X[0]][m_snake_Y[0]] = head_symbol;
}

void clear_snake(char** m_field, size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size) {
	m_field[m_snake_X[m_snake_size]][m_snake_Y[m_snake_size]] = 0;
}
