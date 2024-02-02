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


void init_game(bool& m_flag_game) {
	m_flag_game = true;
}

void check_eating(int* m_snake_X, int* m_snake_Y, int& m_snake_size, int& m_food_X, int& m_food_Y, bool& m_flag) {
	if (m_food_X == m_snake_X[0] && m_food_Y == m_snake_Y[0]) {
		++m_snake_size;
		m_flag = false;
	}
}

void set_food(int& m_food_X, int& m_food_Y, bool& m_flag, char(*m_field)[rows]) {
	if (m_flag) {
		m_field[m_food_X][m_food_Y] = food_symbol;
	}	else {
		generate_food(m_food_X, m_food_Y, m_flag, m_field);
	}
}

void handle_cmd(bool m_handle, const int& m_timeout, bool& m_flag_game) {

	if (!m_handle) {
		Sleep(m_timeout);
		if (_kbhit()) {	
			codeKey = _getch();
			if (codeKey == ESC) {
				m_flag_game = false;
			}
		}
	}	else {
			codeKey = _getch();
		if (codeKey == ESC) {
			m_flag_game = false;
		}	else if (codeKey == 224) {
				codeKey = _getch();
		}
	}

	switch (codeKey) {
		case LEFT_ARROW:
			set_direct_mov(-1);
			break;
		case RIGHT_ARROW:
			set_direct_mov(1);;
			break;
		case DOWN_ARROW:
			set_direct_mov(2);
			break;
		case UP_ARROW:
			set_direct_mov(3);
			break;
	} 
}

void check_game(const int& m_snake_size, bool& m_flag_game, int* m_snake_X, int* m_snake_Y) {
	if (m_snake_size > max_snake) {                //  (- 1) - the size of the food
		m_flag_game = false;
		std::cout << "GAME OVER";
		std::cout << std::endl;
	}

	for (size_t i = 1; i < m_snake_size; i++) {
		if ((m_snake_X[0] == m_snake_X[i]) && (m_snake_Y[0] == m_snake_Y[i])) {
			m_flag_game = false;
			std::cout << "GAME OVER";
			std::cout << std::endl;
		}
	}
}

