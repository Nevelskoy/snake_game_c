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


void init_game(bool& m_game_on) {
	m_game_on = true;
}

void check_eating(int* m_snake_X, int& m_snake_size, int& m_food_X, bool& m_flag) {
	if (m_food_X == m_snake_X[0]) {
		++m_snake_size;
		m_flag = false;
	}
}

void set_food(int& m_food_X, bool& m_flag, int* m_field, int& m_size_field) {
	if (m_flag) {
		m_field[m_food_X] = food_symbol;
	}
	else {
		generate_food(m_food_X, m_flag, m_field, m_size_field);
	}
}

void handle_cmd(bool m_handle, const int& m_timeout, bool& m_game_on) {
	if (!m_handle) {
		Sleep(m_timeout);
		if (_kbhit()) {	
			codeKey = _getch();
			if (codeKey == ESC) {
				m_game_on = false;
			}
		}
	}
	else {
		codeKey = _getch();
		if (codeKey == ESC) {
			m_game_on = false;
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

void check_game(const int& m_snake_size, bool& m_game_on) {
	if (m_snake_size > max_L - 1) {                //  (- 1) - the size of the food
		m_game_on = false;
		std::cout << "GAME OVER";
		std::cout << std::endl;
	}
}

