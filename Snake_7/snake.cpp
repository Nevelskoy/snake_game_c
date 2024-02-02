#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"
#include <stdlib.h>


enum DIRECTIONS { LEFT = -1, RIGHT = 1, DOWN, UP };
static int movement = -1;


void set_direct_mov(int mov) {
	movement = mov;
}

void init_snake(int* m_snake_X, int* m_snake_Y) {
	m_snake_X[0] = (columns / 2);
	m_snake_Y[0] = (rows / 2);
}

// ¬ св€зи с тем, что положение хвоста рассчитываетс€ по положению головы,
// нам достаточно изменить только местоположение головы.
void move_snake(int* m_snake_X, int* m_snake_Y, const int& m_snake_size) {
	for (int i = m_snake_size; i > 0; --i) {
		m_snake_X[i] = m_snake_X[i - 1];
		m_snake_Y[i] = m_snake_Y[i - 1];
	}

	if (movement == RIGHT) {
		m_snake_X[0]++;
	}   else if (movement == LEFT) {
		m_snake_X[0]--;
	}

	if (movement == UP) {
		m_snake_Y[0]--;
	}	else if (movement == DOWN) {
		m_snake_Y[0]++;
	}

	if (m_snake_X[0] > visual_max_X) {
		m_snake_X[0] = 1;
	}   else if (m_snake_X[0] < 1) {
		m_snake_X[0] = visual_max_X;
	}

	if (m_snake_Y[0] > visual_max_Y) {
		m_snake_Y[0] = 1;
	}	else if (m_snake_Y[0] < 1) {
		m_snake_Y[0] = visual_max_Y;
	}
}

// —троим змейку в поле массива field 
void build_snake(int* m_snake_X, int* m_snake_Y, const int& m_snake_size, char(*m_field)[rows]) {
	for (int i = 1; i < m_snake_size; i++) {
		m_field[m_snake_X[i]][m_snake_Y[i]] = tail_symbol; // отображение змейки
	}
	m_field[m_snake_X[0]][m_snake_Y[0]] = head_symbol;
	m_field[m_snake_X[m_snake_size]][m_snake_Y[m_snake_size]] =  0;  // очистка хвоста
 }

