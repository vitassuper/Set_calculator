#include "Parser.hpp"

Parser::Parser(std::string input, Calc calc) : input(input), calc(calc), iter(0) {
	this->delete_spaces();
};

std::set<std::string> Parser::execute() {
	return this->eval(this->parse());
};

Expression Parser::parse() {
	return this->parse_binary_expression(0);
};

std::string Parser::parse_token() {
	if (this->input.size() > this->iter) {
		if (std::isupper(this->input.at(this->iter))) {
			std::string number;
			while (this->input.size() > this->iter && (std::isupper(this->input.at(this->iter)))) {
				number.push_back(this->input.at(this->iter));
				this->iter++;
			};
			return number;
		};
		for (std::string_view t : this->tokens)
			if (std::strncmp(this->input.substr(iter).c_str(), t.data(), t.size()) == 0) {
				this->iter += t.size();
				return t.data();
			};
	};
	return "";
};

// TODO
// prevent more undefined token input
Expression Parser::parse_simple_expression() {
	std::string token = this->parse_token();
	if (token.empty())
		throw std::runtime_error("Invalid Expression");
	if (std::isupper(token.at(0)))
		return Expression(token);
	if (token == "(") {
		Expression result = parse();
		if (this->parse_token() != ")")
			throw std::runtime_error("Expected )...");
		return result;
	};
	return Expression(token, parse_simple_expression());
};

Expression Parser::parse_binary_expression(unsigned int min_priority) {
	Expression left_expr = parse_simple_expression();
	while (true) {
		std::string op = this->parse_token();
		unsigned int priority = this->get_priority(op);
		if (priority <= min_priority) {
			this->iter -= op.size();
			return left_expr;
		};
		Expression right_expr = this->parse_binary_expression(priority);
		left_expr = Expression(op, left_expr, right_expr);
	};
};

unsigned char Parser::get_priority(std::string& token) const noexcept {
	if (token == "+" || token == "/"||token=="u" || token=="n") return 1;
	if (token == "not") return 2;
	return 0;
};

// TODO
// add more operations
// prevent possible value overflow
std::set<std::string> Parser::eval(const Expression& e){
	size_t args_size = e.get_args().size();
	if (args_size == 2) {
		std::set<std::string> a = eval(e.get_args()[0]);
		std::set<std::string> b = eval(e.get_args()[1]);
		if (e.get_token() == "+") return this->calc.calc_symmetric_difference(a,b);
		if (e.get_token() == "u") return this->calc.calc_union(a,b);
		if (e.get_token() == "n") return this->calc.calc_intersection(a,b);
		if (e.get_token() == "/") return this->calc.calc_difference(a,b);
		throw std::runtime_error("Unknown binary operation");
	};
	if (args_size == 1) {
		std::set<std::string> a = eval(e.get_args()[0]);
		if (e.get_token() == "not") return this->calc.calc_not(a);
		throw std::runtime_error("Unknown unary operation");
	};
	if (args_size == 0) {
		for(size_t i=0; i< this->calc.get_sets().size(); i++){
			if (this->calc.get_sets().at(i).first == e.get_token()) {
				return this->calc.get_sets().at(i).second;
			}
	}
	}
	throw std::runtime_error("Unknown expression type");
};

void Parser::delete_spaces() {
	this->input.erase(std::remove_if(this->input.begin(), this->input.end(), std::isspace), input.end());
};
