#pragma once

void init_snake(size_t* m_snake_X, size_t* m_snake_Y, size_t& m_snake_size, bool& flag_game);
void set_direct_mov(size_t mov);
void move_snake(size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size, DIRECTIONS& m_current_mov);
void build_snake(size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size, char(*m_field)[rows]);
void clear_snake(size_t* m_snake_X, size_t* m_snake_Y, const size_t& m_snake_size, char(*m_field)[rows]);