#include <windows.h>
#include <iostream>
#include <conio.h>
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"

int timeout = 100;
unsigned int codeKey = -1;
bool game_on;


void init_game() {
	game_on = true;
}


void check_eating() {
	if (food_x == snake_x[0]) {
		snake_size++;
		food_flag = false;
	}
}


void chek_food() {
	if (food_flag) {
		field[food_x] = food_symbol;
	}
	else {
		generate_food();
	}
}


void handle_cmd(bool handle) {
	if (!handle) {
		Sleep(timeout);
		if (_kbhit()) {	
			codeKey = _getch();
			if (codeKey == ESC) {
				game_on = false;
			}
		}
	}
	else {
		codeKey = _getch();
		if (codeKey == ESC) {
			game_on = false;
		}
		else if (codeKey == 224) {
			codeKey = _getch();
		}
	}

	if (codeKey == RIGHT_ARROW) {
		direct = RIGHT;
	}
	else if (codeKey == LEFT_ARROW) {
		direct = LEFT;
	}

}


void check_game() {
	if (snake_size > L - 1) {                //  (- 1) - the size of the food
		game_on = false;
		std::cout << "GAME OVER";
		std::cout << std::endl;
	}
}

