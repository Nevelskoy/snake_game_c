#include <iostream>
#include "winconsole.h"
#include "const.h"


void init_field() {

}

void print_border_field() {
	setCursorPosition(0, 0);
	for (int i = 0; i < columns; i++) {
		std::cout << borderL_symbol;
	}
	for (int i = 0; i < rows - 2; i++) {
		setCursorPosition(0, i + 1);
		std::cout << borderV_symbol;
	}
	for (int i = 0; i < rows - 2; i++) {
		setCursorPosition(columns - 1, i + 1);
		std::cout << borderV_symbol;
	}
	setCursorPosition(0, rows - 1);
	for (int i = 0; i < columns; i++) {
		std::cout << borderL_symbol;
	}
	std::cout << std::endl;
}

void print_field(char(*m_field)[rows]) {
	for (int i = 1; i <= visual_max_X + 1; i++) {
		for (int j = 1; j < visual_max_Y + 1; j++) {
			setCursorPosition(i, j);
			if (m_field[i][j] > 0) {
				std::cout << m_field[i][j];
				//m_field[i][j] = 0;          // сразу очищаем поле
			}
			else {
				std::cout << field_symbol;
			}
		}
	}
	print_border_field();
}
