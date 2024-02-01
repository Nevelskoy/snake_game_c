#pragma once

void init_snake(int* snake_X, const int& snake_size);
void set_direct_mov(int mov);
void move_snake(int* snake_X, int& size_field);
void build_snake(int* snake_X, const int& snake_size, int* field, int& size_field);