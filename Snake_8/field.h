#pragma once

void init_field(char** m_field, const size_t& m_rows, const size_t& m_columns);
void print_inner_field(char** m_field, const size_t& m_rows, const size_t& m_columns);
void print_border_field(const size_t& m_rows, const size_t& m_columns);
void destruct_field(char** m_field, const size_t& m_columns);