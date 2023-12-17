#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

int main() {

	print_field();
	init_game();							
	init_snake();						 
	
	while (game_on) {	
		clear_field();
		move_snake();
		set_snake();
		check_eating();
		set_food();
		print_field();
		check_game();

#ifdef AUTOMATIC
		handle_cmd(false);
#else	
		handle_cmd(true);
#endif 
	}


	return 0;
}