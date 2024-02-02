#pragma once

void init_snake(int* m_snake_X, int* m_snake_Y);
void set_direct_mov(int mov);
void move_snake(int* m_snake_X, int* m_snake_Y, const int& m_snake_size);
void build_snake(int* m_snake_X, int* m_snake_Y, const int& m_snake_size, char(*m_field)[rows]);