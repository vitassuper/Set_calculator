#pragma once
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <iostream>
#include "Helper.hpp"
class Calc {
public:
	Calc(std::string input);
	void count_sets(std::string input);
	void input_set();
	int resolve(std::string set);
	std::set<std::string> calc_union(std::set<std::string>A, std::set<std::string>B) const;
	std::set<std::string> calc_intersection(std::set<std::string>A, std::set<std::string>B) const;
	std::set<std::string> calc_difference(std::set<std::string>A, std::set<std::string>B) const;
	std::set<std::string> calc_symmetric_difference(std::set<std::string>A, std::set<std::string>B) const;
	std::set<std::string> calc_not(std::set<std::string>A) const;
	void set_universal();
	std::vector<std::pair<std::string, std::set<std::string>>> get_sets() const;
private:
	std::set<std::string> universal_set;
	std::vector<std::pair<std::string, std::set<std::string>>> sets;
	size_t sets_count;
};