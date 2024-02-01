#pragma once

void init_game(bool& game_on);
void check_eating(int* snake_X, int& snake_size, int& food_X, bool& flag);
void check_game(const int& snake_size, bool& game_on);
void set_food(int& food_X, bool& flag, int* field, int& size_field);
void handle_cmd(bool handle, const int& timeout, bool& game_on);