#pragma once

void init_game(bool& m_flag_game);
void check_eating(size_t* m_snake_X, size_t* m_snake_Y, size_t& m_snake_size, size_t& m_food_X, size_t& m_food_Y, bool& m_flag);
void check_game(const size_t& m_snake_size, bool& m_flag_game, size_t* m_snake_X, size_t* m_snake_Y);
void set_food(size_t& m_food_X, size_t& m_food_Y, bool& m_flag, char(*m_field)[rows]);
void handle_cmd(bool m_handle, const size_t& m_timeout, bool& m_flag_game, size_t& m_snake_size, DIRECTIONS& m_current_mov);