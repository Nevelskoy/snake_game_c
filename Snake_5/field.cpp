#include <iostream>
#include "const.h"


int field[columns] = {0};
int size_field = columns - 2;

void init_field() {

}

void print_field() {
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
	std::cout << std::endl;
}
