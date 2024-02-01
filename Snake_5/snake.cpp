#include "const.h"
#include "field.h"

DIRECTIONS direct;
int snake_size;                  // max L
int snake_x[L];                  // Snake's array of coordinates


void init_snake() {
    direct = RIGHT;
    snake_size = 4;              
    snake_x[L] = { 0 };
	snake_x[0] = (columns / 3);
}

// ¬ св€зи с тем, что положение хвоста рассчитываетс€ по положению головы, нам достаточно изменить местоположение головы.
void move_snake() {
	if (direct == RIGHT) {
		snake_x[0]++;
	}
	else if (direct == LEFT) {
		snake_x[0]--;
	}

	if (snake_x[0] > size_field - 1) {
		snake_x[0] = 0;
	}
	else if (snake_x[0] < 0) {
		snake_x[0] = size_field - 1;
	}
}

// —троим змейку в поле массива field
void build_snake() {
	for (int i = 1; i < snake_size; i++) {
		if (direct == RIGHT) {
			snake_x[i] = snake_x[0] - i;
			if (snake_x[i] < 0) {
				snake_x[i] = size_field - (snake_size - i);
			}
		}
		else if (direct == LEFT) {
			snake_x[i] = snake_x[0] + i;
			if (snake_x[i] > size_field - 1) {
				snake_x[i] = snake_size - i - 1;
			}
		}
		field[snake_x[i]] = tail_symbol;
	}
	field[snake_x[0]] = head_symbol;
 }
