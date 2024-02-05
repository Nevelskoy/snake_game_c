#pragma once

struct st_field {
private:
	size_t m_colomns = 20;
	size_t m_rows = 20;
	char** m_field;

public:
	st_field() {};
	st_field(const size_t& columns, const size_t& rows) : m_colomns(columns), m_rows(rows) {};
	~st_field();

	size_t get_columns() const;
	size_t get_rows() const;

	char get_coor(const size_t& col, const size_t& row) const;

	void set_char(const size_t& col, const size_t& row, const char c);

	void init_field();
	void print_border_field();
	void print_inner_field();
};