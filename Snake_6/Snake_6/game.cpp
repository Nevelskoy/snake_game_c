#include <windows.h>
#include <iostream>
#include <conio.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

enum KEYS {
	RIGHT_ARROW = 77,
	LEFT_ARROW = 75,
	UP_ARROW = 72,
	DOWN_ARROW = 80,
	ESC = 27
};

static unsigned int codeKey = -1;


void init_game(bool& game_on) {
	game_on = true;
}

void check_eating(int* snake_X, int& snake_size, int& food_X, bool& flag) {
	if (food_X == snake_X[0]) {
		++snake_size;
		flag = false;
	}
}

void set_food(int& food_X, bool& flag, int* field, int& size_field) {
	if (flag) {
		field[food_X] = food_symbol;
	}
	else {
		generate_food(food_X, flag, field, size_field);
	}
}

void handle_cmd(bool handle, const int& timeout, bool& game_on) {
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
		set_direct_mov(1);
	}
	else if (codeKey == LEFT_ARROW) {
		set_direct_mov(-1);
	}

}

void check_game(const int& snake_size, bool& game_on) {
	if (snake_size > max_L - 1) {                //  (- 1) - the size of the food
		game_on = false;
		std::cout << "GAME OVER";
		std::cout << std::endl;
	}
}

