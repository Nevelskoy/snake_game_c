#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

size_t main() {

	size_t columns = 20;
	size_t rows = 10;
	char** field = new char* [columns];
	size_t food_X;
	size_t food_Y;
	size_t timeout = 200;
	bool food_flag = false;
	bool flag_game = true;
	size_t snake_size = 5;
	size_t snake_X[max_snake]{};
	size_t snake_Y[max_snake]{};
	DIRECTIONS current_mov = RIGHT;

	init_field(field, rows, columns);
	init_game(flag_game);
	init_snake(snake_X, snake_Y, snake_size, flag_game, columns, rows);

	while (flag_game) {
		move_snake(snake_X, snake_Y, snake_size, current_mov, columns, rows);
		build_snake(field, snake_X, snake_Y, snake_size);
		check_eating(snake_X, snake_Y, snake_size, food_X, food_Y, food_flag);
		set_food(field, food_X, food_Y, food_flag, columns, rows);
		print_border_field(rows, columns);
		print_inner_field(field, rows, columns);
		clear_snake(field, snake_X, snake_Y, snake_size);
		check_game(snake_size, flag_game, snake_X, snake_Y);

#ifdef AUTOMATIC
		handle_cmd(false, timeout, flag_game, snake_size, current_mov);
#else	
		handle_cmd(true, timeout, flag_game, snake_size, current_mov);
#endif 
	}

	destruct_field(field, columns);

	return 0;
}
