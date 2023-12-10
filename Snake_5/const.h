#pragma once

const int columns = 20;
const int L = columns - 2;				// max lenght Snake
const char field_symbol = ' ';
const char borderL_symbol = '-';
const char borderV_symbol = '|';
const char tail_symbol = '#';
const char head_symbol = '@';
const char food_symbol = '+';

enum DIRECTION {
	RIGHT, 
	LEFT,
	UP,
	DOWN
};

enum KEYS {
	RIGHT_ARROW = 77,
	LEFT_ARROW = 75,
	UP_ARROW = 72,
	DOWN_ARROW = 80,
	ESC = 27
};

enum STATUS {
	START,
	RUN,
	FINISH
};


