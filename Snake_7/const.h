#pragma once

const size_t columns = 20;
const size_t rows = 10;
const size_t max_snake = 70;
const size_t visual_max_X = columns - 2;	
const size_t visual_max_Y = rows - 2;
const char field_symbol = ' ';
const char borderL_symbol = '-';
const char borderV_symbol = '|';
const char tail_symbol = '#';
const char head_symbol = '@';
const char food_symbol = '+';
enum DIRECTIONS { LEFT = -1, RIGHT = 1, DOWN, UP };


