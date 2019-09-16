#pragma once
#include <algorithm>
#include <string>
#include <set>
class Helper {
	public:
		static inline void SplitToSet(std::set<std::string>& set, std::string dlm, std::string src) noexcept{
				std::string::size_type p, start = 0, len = src.length();
				start = src.find_first_not_of(dlm);
				p = src.find_first_of(dlm, start);
				while (p != std::string::npos) {
					set.insert(src.substr(start, p - start));
					start = src.find_first_not_of(dlm, p);
					p = src.find_first_of(dlm, start);
				}
				if (len > start)
					set.insert(src.substr(start, len - start));
			}
		static inline bool find_in_pair(std::vector<std::pair<std::string, std::set<std::string>>> sets, std::string input) {
			for (auto& i : sets) {
				if (i.first == input) return true;
			}
			return false;
		}
};

