#pragma once

struct st_field;

struct st_food
{
private:
	bool m_food_flag = false;
	size_t m_food_X;
	size_t m_food_Y;

public:
	st_food() {};

	bool get_flag() const;
	size_t get_foodX() const;
	size_t get_foodY() const;

	void set_food_flag(const bool& new_flag);

	void generate_food(st_field& field);
};
