#include "const.h"
#include "field.h"
#include <stdlib.h>



bool food_flag = false;
int food_x = -1;          // coordinates of food


void generate_food() {
	while (!food_flag) {
		food_x = rand() % size_field;
		if (field[food_x] == 0) {
			field[food_x] = food_symbol;
			food_flag = true;
		}
	}
}