#include "Calc.hpp"


void Calc::count_sets(std::string input){
	size_t i = 0;
	std::string temp;
	while (input.size() > i) {
		if (std::isupper(input.at(i))) {
			while (input.size() > i && std::isupper(input.at(i))) {
				temp += input.at(i);
				i++;
			}
			if (!Helper::find_in_pair(this->sets, temp)) {
				this->sets.push_back(std::pair(temp, std::set<std::string>()));
			}
			temp.clear();
		}else
		i++;
	}
}

Calc::Calc(std::string input) {
	this->sets_count = 0;
	this->count_sets(input);
	this->input_set();
	this->set_universal();
}



void Calc::input_set() {
	std::cin.get();
	for (size_t i = 0;  i < this->sets.size(); i++) {
		std::string temp;
		std::cout << this->sets.at(i).first + ": ";
		std::getline(std::cin,temp);
		Helper::SplitToSet(this->sets.at(i).second, " -,.", temp);
	}
}

int Calc::resolve(std::string set) {
	return 0;
}

std::set<std::string> Calc::calc_union(std::set<std::string> A, std::set<std::string> B)const {
	std::set<std::string> temp;
	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(temp, temp.begin()));
	return temp;
}

std::set<std::string> Calc::calc_intersection(std::set<std::string> A, std::set<std::string> B) const {
	std::set<std::string> temp;
	std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(temp, temp.begin()));
	return temp;
}

std::set<std::string> Calc::calc_difference(std::set<std::string> A, std::set<std::string> B) const {
	std::set<std::string> temp;
	std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(temp, temp.begin()));
	return temp;
}

std::set<std::string> Calc::calc_symmetric_difference(std::set<std::string> A, std::set<std::string> B) const{
	std::set<std::string> temp;
	std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(temp, temp.begin()));
	return temp;
}

std::set<std::string> Calc::calc_not(std::set<std::string> A) const {
	return this->calc_difference(this->universal_set, A);
}

void Calc::set_universal(){
	for (auto& i : this->sets) {
		std::set_union(this->universal_set.begin(), this->universal_set.end(), i.second.begin(), i.second.end(), std::inserter(this->universal_set, this->universal_set.begin()));
	}
}

std::vector<std::pair<std::string, std::set<std::string>>> Calc::get_sets() const{
	return this->sets;
}
