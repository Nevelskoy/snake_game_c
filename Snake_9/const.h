#pragma once

const size_t max_snake = 70;
const char field_symbol = ' ';
const char borderL_symbol = '-';
const char borderV_symbol = '|';
const char tail_symbol = '#';
const char head_symbol = '@';
const char food_symbol = '+';
enum DIRECTIONS { LEFT, RIGHT, DOWN, UP };
enum KEYS {
	RIGHT_ARROW = 77,
	LEFT_ARROW = 75,
	UP_ARROW = 72,
	DOWN_ARROW = 80,
	ESC = 27
};


