#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

size_t main() {

	char field[columns][rows]{ 0 };
	size_t food_X;
	size_t food_Y;
	size_t timeout = 200;
	bool food_flag = false;
	bool flag_game = true;
	size_t snake_size = 5;
	size_t snake_X[max_snake]{0};
	size_t snake_Y[max_snake]{0};
	DIRECTIONS current_mov = RIGHT;

	init_game(flag_game);
	init_snake(snake_X, snake_Y, snake_size, flag_game);
	
	while (flag_game) {	
		move_snake(snake_X, snake_Y, snake_size, current_mov);	
		build_snake(snake_X, snake_Y, snake_size, field);
		check_eating(snake_X, snake_Y, snake_size, food_X, food_Y, food_flag);
		set_food(food_X, food_Y, food_flag, field);
		print_field(field);
		clear_snake(snake_X, snake_Y, snake_size, field);
		check_game(snake_size, flag_game, snake_X, snake_Y);

#ifdef AUTOMATIC
		handle_cmd(false, timeout, flag_game, snake_size, current_mov);
#else	
		handle_cmd(true, timeout, flag_game, snake_size, current_mov);
#endif 
	}
	return 0;
}