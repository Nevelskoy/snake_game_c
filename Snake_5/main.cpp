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
	
	
	init_game();			// 1.1.	������������� ���� 
	// init_field()				 1.2.	������������� �������� ���� 
	init_snake();				// 1.3.	������������� ������ 
	// init_food()						������������� ���
	// set_snake()			 	1.5.	����������� ������ � ���� ���� 
	print_field();		//1.6.	����� ���� ���� �� ����� 	
	std::cout << "Welcom to the Snake-game! Press any key to start..." << std::endl;




	while (game_on) {
#ifdef AUTOMATIC
		handle_cmd(false);
#else	
		handle_cmd(true);
#endif  
		clear_snake();	
		move_snake();
		set_snake();
		check_eating();
		set_food();
		print_field();
		check_game();	
	}

	std::cout << std::endl;
	std::cout << "GAME OVER";
	return 0;
}