#include <windows.h>
#include <iostream>
#include <conio.h>
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"

STATUS status = START;
int timeout = 100;
unsigned int codeKey = -1;


void init_game() {
	status = RUN;
	_getch();
}


void clear_snake() {
	system("cls");
}


void set_snake() {
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
}


void check_eating() {
	if (food_x == snake_x[0]) {
		snake_size++;
		food_flag = false;
	}

}


void set_food() {
	if (food_flag) {
		generate_food(food_x);
	}

	while (!food_flag) {
		food_x = rand() % size_field;
		if (field[food_x] == 0) {
			field[food_x] = food_symbol;
			food_flag = true;
		}
	}
}

void check_game() {
	if (snake_size > L - 1) {                //  (- 1) - the size of the food
		status = FINISH;
	}
}


void handle_cmd(bool handle) {
	if (!handle) {
		Sleep(timeout);
		if (_kbhit()) {	
			codeKey = _getch();
			if (codeKey == ESC) {
				status = FINISH;
			}
		}
	}
	else {
		codeKey = _getch();
		if (codeKey == ESC) {
			status = FINISH;
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


void status_bar() {
	switch (status)
	{
	case START:
		std::cout << "Welcom to the Snake-game! Press any key to start..." << std::endl;
		break;
	case RUN:
		std::cout << "Run..." << std::endl;
		break;
	case FINISH:
		clear_snake();
		std::cout << "GAME OVER!" << std::endl;
		set_snake();
		print_field();
		break;
	default:
		break;
	}
}
