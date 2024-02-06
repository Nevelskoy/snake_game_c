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
	system("cls");
	m_flag_game = true;
}

void check_eating(size_t* m_snake_X, size_t* m_snake_Y, size_t& m_snake_size, size_t& m_food_X, size_t& m_food_Y, bool& m_flag) {
	if (m_food_X == m_snake_X[0] && m_food_Y == m_snake_Y[0]) {
		++m_snake_size;
		m_flag = false;
	}
}

void set_food(char** m_field, size_t& m_food_X, size_t& m_food_Y, bool& m_flag, const size_t& columns, const size_t& rows) {
	if (m_flag) {
		m_field[m_food_X][m_food_Y] = food_symbol;
	}
	else {
		generate_food(m_field, m_food_X, m_food_Y, m_flag, columns, rows);
	}
}

void handle_cmd(bool m_handle, const size_t& m_timeout, bool& m_flag_game, size_t& m_snake_size, DIRECTIONS& m_current_mov) {
	// јвтоматический режим работы игры
	if (!m_handle) {
		Sleep(m_timeout);
		if (_kbhit()) {
			codeKey = _getch();
			if (codeKey == ESC) {
				m_flag_game = false;
			}
		}
	}
	else {
		// –учной режим работы игры
		codeKey = _getch();
		if (codeKey == ESC) {
			m_flag_game = false;
		}
		else if (codeKey == 224) {
			codeKey = _getch();
		}
	}

	switch (codeKey) {
	case 'a': codeKey = LEFT_ARROW; break;
	case 'w': codeKey = UP_ARROW; break;
	case 's': codeKey = DOWN_ARROW; break;
	case 'd': codeKey = RIGHT_ARROW; break;
	case 'A': codeKey = LEFT_ARROW; break;
	case 'W': codeKey = UP_ARROW; break;
	case 'S': codeKey = DOWN_ARROW; break;
	case 'D': codeKey = RIGHT_ARROW; break;
	}

	// «апрет движени€ в противоположную сторону при наличии хвоста
	switch (codeKey) {
	case LEFT_ARROW: if ((m_current_mov != RIGHT) || (m_snake_size == 1)) m_current_mov = LEFT; break;
	case RIGHT_ARROW: if ((m_current_mov != LEFT) || (m_snake_size == 1)) m_current_mov = RIGHT; break;
	case UP_ARROW: if ((m_current_mov != DOWN) || (m_snake_size == 1)) m_current_mov = UP; break;
	case DOWN_ARROW: if ((m_current_mov != UP) || (m_snake_size == 1)) m_current_mov = DOWN; break;
	}

	// ƒобавл€ем замедление при движении по вертикали
	if ((m_current_mov == UP) || (m_current_mov == DOWN)) {
		Sleep(m_timeout * 0.7);
	}
}

void check_game(const size_t& m_snake_size, bool& m_flag_game, size_t* m_snake_X, size_t* m_snake_Y) {
	// ѕроверка превышени€ максимального размера	
	if (m_snake_size > max_snake) {
		m_flag_game = false;
		std::cout << "GAME OVER";
		std::cout << std::endl;
	}

	// ѕроверка пересечени€ с хвостом
	for (size_t i = 1; i < m_snake_size; i++) {
		if ((m_snake_X[0] == m_snake_X[i]) && (m_snake_Y[0] == m_snake_Y[i])) {
			m_flag_game = false;
			std::cout << "GAME OVER";
			std::cout << std::endl;
		}
	}
}

