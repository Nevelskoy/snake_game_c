#include <iostream>
#include "winconsole.h"
#include "const.h"


void init_field(char** m_field, const size_t& m_rows, const size_t& m_columns) {
	for (size_t i = 0; i < m_columns; i++) {
		m_field[i] = new char[m_rows] {0};
	}
}

void print_border_field(const size_t& m_rows, const size_t& m_columns) {
	setCursorPosition(0, 0);
	for (size_t i = 0; i < m_columns; i++) {
		std::cout << borderL_symbol;
	}
	for (size_t i = 0; i < m_rows - 2; i++) {
		setCursorPosition(0, i + 1);
		std::cout << borderV_symbol;
	}
	for (size_t i = 0; i < m_rows - 2; i++) {
		setCursorPosition(m_columns - 1, i + 1);
		std::cout << borderV_symbol;
	}
	setCursorPosition(0, m_rows - 1);
	for (size_t i = 0; i < m_columns; i++) {
		std::cout << borderL_symbol;
	}
	std::cout << std::endl;
}

void print_inner_field(char** m_field, const size_t& m_rows, const size_t& m_columns) {
	for (size_t i = 1; i < m_columns - 1; i++) {
		for (size_t j = 1; j < m_rows - 1; j++) {
			setCursorPosition(i, j);
			if (m_field[i][j] != 0) {
				std::cout << m_field[i][j];
			} else {
				std::cout << field_symbol;
			}
		}
	}
}

void destruct_field(char** m_field, const size_t& m_columns)
{
	for (size_t i = 0; i < m_columns; i++)
	{
		delete[] m_field[i];
	}
	delete[] m_field;
}
