#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

int main() {

//	print_field();
	init_game();							
	init_snake();						 
	
	while (game_on) {	
		move_snake();
		build_snake();
		set_food();
		check_eating();
		print_border_field();
		print_object_field();
		check_game();

#ifdef AUTOMATIC
		handle_cmd(false);
#else	
		handle_cmd(true);
#endif 
	}


	return 0;
}