#pragma once

void init_game(bool& m_game_on);
void check_eating(int* m_snake_X, int& m_snake_size, int& m_food_X, bool& m_flag);
void check_game(const int& snake_size, bool& game_on);
void set_food(int& m_food_X, bool& m_flag, int* m_field, int& m_size_field);
void handle_cmd(bool m_handle, const int& m_timeout, bool& m_game_on);