#include <windows.h>
#include <iostream>
#include <conio.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"
#include "winconsole.h"

#define AUTOMATIC


size_t st_game::get_timeout() const {
	return m_timeout;
}

bool st_game::get_flag_game() const {
	return m_flag_game;
}

void st_game::set_timeout(size_t& timeout) {
	m_timeout = timeout;
}

void st_game::set_flag_game(bool&& flag_game) {
	m_flag_game = flag_game;
}

void st_game::init_game() {
	system("cls");
	m_flag_game = true;
}

void st_game::check_eating(st_snake& snake, st_food& food) {
	if (food.get_foodX() == snake.get_snake_X(0) && food.get_foodY() == snake.get_snake_Y(0)) {
		snake.up_size();
		food.set_food_flag(false);
	}
}

void st_game::set_food(st_field& field, st_food& food) {
	if (food.get_flag()) {
		field.set_char(food.get_foodX(), food.get_foodY(), food_symbol);
	}
	else {
		food.generate_food(field);
	}
}

void st_game::handle_cmd(bool m_handle, st_snake& snake) {
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
	case LEFT_ARROW: if ((snake.get_direct() != RIGHT) || (snake.get_size() == 1))  snake.set_direct(LEFT); break;
	case RIGHT_ARROW: if ((snake.get_direct() != LEFT) || (snake.get_size() == 1)) snake.set_direct(RIGHT); break;
	case UP_ARROW: if ((snake.get_direct() != DOWN) || (snake.get_size() == 1)) snake.set_direct(UP); break;
	case DOWN_ARROW: if ((snake.get_direct() != UP) || (snake.get_size() == 1)) snake.set_direct(DOWN); break;
	}

	// ƒобавл€ем замедление при движении по вертикали
	if ((snake.get_direct() == UP) || (snake.get_direct() == DOWN)) {
		Sleep(m_timeout * 0.7);
	}
}

void st_game::check_game(st_snake& snake, st_field& field) {
	// ѕроверка превышени€ максимального размера	
	if (snake.get_size() > max_snake) {
		m_flag_game = false;
		setCursorPosition(5, 5);
		std::cout << "GAME OVER";
	}

	// ѕроверка пересечени€ с хвостом
	for (size_t i = 1; i < snake.get_size(); i++) {
		if ((snake.get_snake_X(0) == snake.get_snake_X(i)) && (snake.get_snake_Y(0) == snake.get_snake_X(i))) {
			m_flag_game = false;
		}
	}
}

void st_game::start(st_game& game, st_snake& snake, st_field& field, st_food& food) {

	field.init_field();
	init_game();
	snake.init_snake(field, game);

	while (m_flag_game) {
		snake.move_snake(field);	
		snake.build_snake(field);
		check_eating(snake, food);
		set_food(field, food);
		field.print_border_field();
		field.print_inner_field();
		snake.clear_snake(field);
		check_game(snake, field);

#ifdef AUTOMATIC
		handle_cmd(false, snake);
#else	
		handle_cmd(true, snake);
#endif 
	}
}
