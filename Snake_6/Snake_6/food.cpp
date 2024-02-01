#include "const.h"
#include "field.h"
#include <stdlib.h>


void generate_food(int& food_X, bool& flag, int* field, int& size_field) {
	while (!flag) {
		food_X = rand() % size_field;
		if (field[food_X] == 0) {
			field[food_X] = food_symbol;
			flag = true;
		}
	}
}