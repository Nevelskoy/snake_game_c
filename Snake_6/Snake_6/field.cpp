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
	setCursorPosition(0, 1);
	std::cout << borderV_symbol;

	setCursorPosition(columns - 1, 1);
	std::cout << borderV_symbol;

	setCursorPosition(0, 2);
	for (int i = 0; i < columns; i++) {
		std::cout << borderL_symbol;
	}
	std::cout << std::endl;
}

void print_field(int* field, int& size_field) {
	setCursorPosition(1, 1);
	for (int i = 0; i < size_field; i++) {
		if (field[i] > 0) {
			std::cout << static_cast<char>(field[i]);
			field[i] = 0;
		}
		else {
			std::cout << field_symbol;
		}
	}
	print_border_field();
}
