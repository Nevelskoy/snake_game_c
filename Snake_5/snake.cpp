#include "const.h"
#include "field.h"

DIRECTION direct;
int snake_size;                  // max L
int snake_x[L];                  // Snake's array of coordinates


void init_snake() {
    direct = RIGHT;
    snake_size = 4;              
    snake_x[L] = { 0 };
	snake_x[0] = (columns / 3);
}


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
