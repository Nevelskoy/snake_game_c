#pragma once

void init_snake(size_t* m_snake_X, size_t* m_snake_Y, size_t& m_snake_size, bool& flag_game, const size_t& columns, const size_t& rows);
void move_snake(size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size, DIRECTIONS& m_current_mov, const size_t& columns, const size_t& rows);
void build_snake(char** m_field, size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size);
void clear_snake(char** m_field , size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size);