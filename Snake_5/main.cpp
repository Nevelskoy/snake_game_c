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


	// init_game()				 1.1.	инициализация игры 
	// init_field()				 1.2.	инициализация игрового поля 
	init_snake();				// 1.3.	инициализация змейки 
	// init_food()						инициализация еды
	// set_snake()			 	1.5.	“Установка” змейки в поле игры 
	// print_field()			1.6.	Вывод поля игры на экран 	
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