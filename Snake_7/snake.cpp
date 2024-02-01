#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"


enum DIRECTIONS { LEFT = -1, RIGHT = 1, DOWN, UP };
static int movement = -1;


void set_direct_mov(int mov) {
	movement = mov;
}

void init_snake(int* m_snake_X, const int& m_snake_size) {
    //snake_size = 4;              
    //snake_x[L] = { 0 };
	m_snake_X[0] = (columns / 2);
}

// В связи с тем, что положение хвоста рассчитывается по положению головы,
// нам достаточно изменить только местоположение головы.
void move_snake(int* m_snake_X, int& m_size_field) {
	if (movement == RIGHT) {
		m_snake_X[0]++;
	}
	else if (movement == LEFT) {
		m_snake_X[0]--;
	}

	if (m_snake_X[0] > m_size_field - 1) {
		m_snake_X[0] = 0;
	}
	else if (m_snake_X[0] < 0) {
		m_snake_X[0] = m_size_field - 1;
	}
}

// Строим змейку в поле массива field
void build_snake(int* m_snake_X, const int& m_snake_size, int* m_field, int& m_size_field) {
	for (int i = 1; i < m_snake_size; i++) {
		if (movement == RIGHT) {
			m_snake_X[i] = m_snake_X[0] - i;
			if (m_snake_X[i] < 0) {
				m_snake_X[i] = m_size_field - (m_snake_size - i);
			}
		}
		else if (movement == LEFT) {
			m_snake_X[i] = m_snake_X[0] + i;
			if (m_snake_X[i] > m_size_field - 1) {
				m_snake_X[i] = m_snake_size - i - 1;
			}
		}
		m_field[m_snake_X[i]] = tail_symbol;
	}
	m_field[m_snake_X[0]] = head_symbol;
 }
