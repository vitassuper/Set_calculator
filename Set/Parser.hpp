#pragma once
#include "Expression.hpp"
#include <cctype>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "Calc.hpp"


class Parser {
public:
	explicit Parser(std::string input, Calc calc);
	std::set<std::string> execute();
	Expression parse();
	Calc calc;
private:
	std::string input;
	size_t iter;
	static std::string_view constexpr tokens[] = {	"u", "n", "/", "+", "not" , "(" , ")",	};

	Expression parse_binary_expression(unsigned int min_priority);
	Expression parse_simple_expression();
	std::string parse_token();
	void delete_spaces();
	unsigned char get_priority(std::string& token) const noexcept;
	std::set<std::string> eval(const Expression& e);
};