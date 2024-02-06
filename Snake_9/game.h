#pragma once

struct st_snake;
struct st_food;
struct st_field;


struct st_game {
private:
	size_t m_timeout = 200;
	bool m_flag_game = true;
	unsigned int codeKey = -1;

public:
	st_game() {};

	size_t get_timeout() const;
	bool get_flag_game() const;

	void set_timeout(size_t& timeout);
	void set_flag_game(bool&& flag_game);

	void start(st_game& game, st_snake& snake, st_field& field, st_food& food);

	void init_game();
	void check_eating(st_snake& snake, st_food& food);
	void set_food(st_field& field, st_food& food);
	void handle_cmd(bool m_handle, st_snake& snake);
	void check_game(st_snake& snake, st_field& field);
};