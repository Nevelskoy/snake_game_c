#include "const.h"


int field[columns] = {0};
int size_field = columns - 2;


void draw_food(int x) {
	field[x] = food_symbol;
}
