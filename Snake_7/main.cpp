#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

//#define AUTOMATIC

int main() {

	bool flag_game = true;
	int timeout = 200;
	char field[columns][rows]{0};
	int snake_size = 1;
	int snake_X[max_snake]{0};
	int snake_Y[max_snake]{0};
	bool food_flag = false;
	int food_X;
	int food_Y;

	init_game(flag_game);
	init_snake(snake_X, snake_Y);
	
	while (flag_game) {	
		move_snake(snake_X, snake_Y, snake_size);
		build_snake(snake_X, snake_Y, snake_size, field);
		check_eating(snake_X, snake_Y, snake_size, food_X, food_Y, food_flag);
		set_food(food_X, food_Y, food_flag, field);
		print_field(field);
		check_game(snake_size, flag_game, snake_X, snake_Y);

#ifdef AUTOMATIC
		handle_cmd(false, timeout, flag_game);
#else	
		handle_cmd(true, timeout, flag_game);
#endif 
	}
	return 0;
}