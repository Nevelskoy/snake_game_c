#pragma once

void init_snake(int* m_snake_X, const int& m_snake_size);
void set_direct_mov(int mov);
void move_snake(int* m_snake_X, int& m_size_field);
void build_snake(int* m_snake_X, const int& m_snake_size, int* m_field, int& m_size_field);