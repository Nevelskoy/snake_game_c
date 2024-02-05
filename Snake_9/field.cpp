#include <iostream>
#include "winconsole.h"
#include "const.h"
#include "field.h"


void st_field::init_field() {
	// Создаём новое поле
	m_field = new char* [get_columns()];

	for (size_t i = 0; i < get_columns(); i++) {
		m_field[i] = new char[get_rows()] {0};
	}
}

void st_field::print_border_field() {
	setCursorPosition(0, 0);
	for (size_t i = 0; i < get_columns(); i++) {
		std::cout << borderL_symbol;
	}
	for (size_t i = 0; i < get_rows() - 2; i++) {
		setCursorPosition(0, i + 1);
		std::cout << borderV_symbol;
	}
	for (size_t i = 0; i < get_rows() - 2; i++) {
		setCursorPosition(get_columns() - 1, i + 1);
		std::cout << borderV_symbol;
	}
	setCursorPosition(0, get_rows() - 1);
	for (size_t i = 0; i < get_columns(); i++) {
		std::cout << borderL_symbol;
	}
	std::cout << std::endl;
}

void st_field::print_inner_field() {
	for (size_t i = 1; i < get_columns() - 1; i++) {
		for (size_t j = 1; j < get_rows() - 1; j++) {
			setCursorPosition(i, j);
			if (m_field[i][j] != 0) {
				std::cout << m_field[i][j];
			} else {
				std::cout << field_symbol;
			}
		}
	}
}

size_t st_field::get_columns() const {
	return m_colomns;
}

size_t st_field::get_rows() const {
	return m_rows;
}

char st_field::get_coor(const size_t& col, const size_t& row) const {
	return m_field[col][row];
}

void st_field::set_char(const size_t& col, const size_t& row, const char c) {
	m_field[col][row] = c;
}

st_field::~st_field() {
	for (size_t i = 0; i < get_columns(); i++)
	{
		delete[] m_field[i];
	}
	delete[] m_field;
}
