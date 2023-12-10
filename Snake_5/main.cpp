
#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

int main() {

	status_bar();
	print_field();
	init_game();							
	init_snake();						 
	
	while (status == RUN) {	
		clear_snake();		
		status_bar();
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

	status_bar();

	return 0;
}