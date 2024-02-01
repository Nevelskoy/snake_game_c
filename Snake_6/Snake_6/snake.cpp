#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"


enum DIRECTIONS { LEFT = -1, RIGHT = 1, DOWN, UP };
static int movement = -1;


void set_direct_mov(int mov) {
	movement = mov;
}

void init_snake(int* snake_X, const int& snake_size) {
    //snake_size = 4;              
    //snake_x[L] = { 0 };
	snake_X[0] = (columns / 2);
}

// В связи с тем, что положение хвоста рассчитывается по положению головы,
// нам достаточно изменить только местоположение головы.
void move_snake(int* snake_X, int& size_field) {
	if (movement == RIGHT) {
		snake_X[0]++;
	}
	else if (movement == LEFT) {
		snake_X[0]--;
	}

	if (snake_X[0] > size_field - 1) {
		snake_X[0] = 0;
	}
	else if (snake_X[0] < 0) {
		snake_X[0] = size_field - 1;
	}
}

// Строим змейку в поле массива field
void build_snake(int* snake_X, const int& snake_size, int* field, int& size_field) {
	for (int i = 1; i < snake_size; i++) {
		if (movement == RIGHT) {
			snake_X[i] = snake_X[0] - i;
			if (snake_X[i] < 0) {
				snake_X[i] = size_field - (snake_size - i);
			}
		}
		else if (movement == LEFT) {
			snake_X[i] = snake_X[0] + i;
			if (snake_X[i] > size_field - 1) {
				snake_X[i] = snake_size - i - 1;
			}
		}
		field[snake_X[i]] = tail_symbol;
	}
	field[snake_X[0]] = head_symbol;
 }
