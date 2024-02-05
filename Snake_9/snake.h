#pragma once

struct st_food;
struct st_field;

struct st_snake {
private:
	size_t m_snake_size = 5;
	DIRECTIONS m_current_mov = RIGHT;
	size_t m_snake_X[max_snake]{};
	size_t m_snake_Y[max_snake]{};
public:
	st_snake() {};
	st_snake(size_t snake_size, DIRECTIONS current_mov) : m_snake_size(snake_size), m_current_mov(current_mov) {};

	size_t get_size() const;
	size_t get_snake_X(const size_t& x) const;
	size_t get_snake_Y(const size_t& y) const;
	DIRECTIONS get_direct() const;

	void set_snake_X(const size_t& idx, const size_t& value);
	void set_snake_Y(const size_t& idx, const size_t& value);
	void set_direct(DIRECTIONS&&);

	void up_size();
	void init_snake(st_field& field, st_game& game);
	void move_snake(st_field& field);
	void build_snake(st_field& field);
	void clear_snake(st_field& field);

};