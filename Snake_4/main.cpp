#include <iostream>
#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

#define AUTOMATIC

int main() {
	
	unsigned int codeKey = -1;
	DIRECTION direct = RIGHT;
	snake_x[0] = (columns / 2);


	std::cout << "Welcom to the Snake-game! Press any key to start..." << std::endl;
	_getch();

	while (game_on) {
		system("cls");
		//============= BEGIN DRAWING =============
		for (int i = 0; i < columns; i++) {
			std::cout << borderL_symbol;
		}
		std::cout << std::endl;
		std::cout << borderV_symbol;
		for (int i = 0; i < size_field; i++) {
			if (field[i] > 0) {
				std::cout << static_cast<char>(field[i]);
				field[i] = 0;
			}
			else {
				std::cout << field_symbol;
			}
		}
		std::cout << borderV_symbol << std::endl;
		for (int i = 0; i < columns; i++) {
			std::cout << borderL_symbol;
		}
		//============= END DRAWING =============	

		//============= BEGIN INPUT KEY =============
#ifdef AUTOMATIC
		Sleep(timeout);
		if (_kbhit()) {
			codeKey = _getch();
			if (codeKey == ESC) {
				game_on = false;
			}
		}
		if (codeKey == RIGHT_ARROW) {
			direct = RIGHT;
		}
		else if (codeKey == LEFT_ARROW) {
			direct = LEFT;
		}
#else	
		codeKey = _getch();
		if (codeKey == ESC) {
			game_on = false;
		}
		else if(codeKey == 224) {
			codeKey = _getch();
		}

		if (codeKey == RIGHT_ARROW) {
			direct = RIGHT;
		}
		else if (codeKey == LEFT_ARROW) {
			direct = LEFT;
		}
#endif  
		//============= END INPUT KEY =============

		//============= BEGIN LOGIC =============	
		if (direct == RIGHT) {
			snake_x[0]++;
		}
		else if (direct == LEFT) {
			snake_x[0]--;
		}

		if (snake_x[0] > size_field - 1) {
			snake_x[0] = 0;
		}
		else if (snake_x[0] < 0) {
			snake_x[0] = size_field - 1;
		}

		if (food_x == snake_x[0]) {
			snake_size++;
			food_flag = false;
		}

		if (snake_size > L - 1) {                //  (- 1) - the size of the food
			std::cout << std::endl;
			std::cout << "GAME OVER";
			_getch();
			game_on = false;
		}

		for (int i = 1; i < snake_size; i++) {
			if (direct == RIGHT) {
				snake_x[i] = snake_x[0] - i;
				if (snake_x[i] < 0) {
					snake_x[i] = size_field - (snake_size - i);
				}
			}
			else if (direct == LEFT) {
				snake_x[i] = snake_x[0] + i;
				if (snake_x[i] > size_field - 1) {
					snake_x[i] = snake_size - i - 1;
				}
			}
			field[snake_x[i]] = tail_symbol;
		}	
		field[snake_x[0]] = head_symbol;
		//============= END LOGIC =============

		//============= BEGIN FOOD =============	
		if (food_flag) {
			draw_food(food_x);
		}

		while (!food_flag) {
			food_x = rand() % size_field;
			if (field[food_x] == 0) {
				field[food_x] = food_symbol;
				food_flag = true;
			}		
		}	
		//============= END FOOD =============

	}/*END while (game_on)*/

	
	return 0;
}