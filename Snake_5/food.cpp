#include "const.h"
#include "field.h"


bool food_flag = false;
int food_x = -1;


void generate_food(int x) {
	field[x] = food_symbol;
}