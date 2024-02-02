#pragma once

void init_game(bool& m_flag_game);
void check_eating(int* m_snake_X, int* m_snake_Y, int& m_snake_size, int& m_food_X, int& m_food_Y, bool& m_flag);
void check_game(const int& m_snake_size, bool& m_flag_game, int* m_snake_X, int* m_snake_Y);
void set_food(int& m_food_X, int& m_food_Y, bool& m_flag, char(*m_field)[rows]);
void handle_cmd(bool m_handle, const int& m_timeout, bool& m_flag_game);