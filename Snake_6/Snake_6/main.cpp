#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

int main() {

	bool game_on = true;
	int timeout = 100;
	int field[columns] = { 0 };
	int size_field = columns - 2;
	int snake_size = 1;
	int snake_X[max_L]{ 0 };	
	bool food_flag = false;
	int food_X = -1;


	init_game(game_on);
	init_snake(snake_X, snake_size);
	
	while (game_on) {	
		move_snake(snake_X, size_field);
		build_snake(snake_X, snake_size, field, size_field);
		check_eating(snake_X, snake_size, food_X, food_flag);
		set_food(food_X, food_flag, field, size_field);
		print_field(field, size_field);
		check_game(snake_size, game_on);

#ifdef AUTOMATIC
		handle_cmd(false, timeout, game_on);
#else	
		handle_cmd(true, timeout, game_on);
#endif 
	}
	return 0;
}