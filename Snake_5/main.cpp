#include <iostream>
#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

//#define AUTOMATIC

int main() {

	snake_x[0] = (columns / 2);


	// init_game()				 1.1.	������������� ���� 
	// init_field()				 1.2.	������������� �������� ���� 
	init_snake();				// 1.3.	������������� ������ 
	// init_food()						������������� ���
	// set_snake()			 	1.5.	����������� ������ � ���� ���� 
	// print_field()			1.6.	����� ���� ���� �� ����� 	
	std::cout << "Welcom to the Snake-game! Press any key to start..." << std::endl;
	_getch();


	while (game_on) {
		clear_snake();
		print_field();

#ifdef AUTOMATIC
		handle_cmd(0);
#else	
		handle_cmd(true);
#endif  
		move_snake();
		set_snake();
		check_eating();
		check_game();
		set_food();


	}/*END while (game_on)*/

	std::cout << std::endl;
	std::cout << "GAME OVER";
	return 0;
}