#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//Split string on spaces and convert to type T
template<typename T>
std::vector<T> split(const std::string& str, char delimiter) {
	std::vector<T> result;
	std::string token;
	size_t start = 0;
	size_t end = str.find(delimiter);
	while (end != std::string::npos) {
		token = str.substr(start, end - start);

		std::cout << ";" << token << ";" << std::endl;

		result.push_back(std::stoi(token));
		start = end + 1;
		end = str.find(delimiter, start);
	}
	result.push_back(std::stoi(str.substr(start)));
	return result;
}


int rec(int day, int currMagic, std::vector<std::vector<int>>& programs, bool& reachedEnd, std::map<std::pair<int, int>, int> cache) {

	if (cache.find({ day, currMagic }) != cache.end()) {
		return cache[{ day, currMagic }];
	}

	if (reachedEnd) {
		return currMagic;
	}
	if (day == programs.size()) {
		reachedEnd = true;
		std::cout << currMagic << '\n';
		exit(0);
		return currMagic;
	}
	int maxMagic = 0;
	bool picked = false;
	for (int i = 0; i < programs[day].size(); ++i) {
		if (programs[day][i] < currMagic) {
			continue;
		}
		picked = true;
		int magic = rec(day + 1, programs[day][i], programs, reachedEnd, cache);
		maxMagic = std::max(maxMagic, magic);
	}

	cache[{ day, currMagic }] = maxMagic;

	return maxMagic;
}

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> programs(n);
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		programs[i].resize(k);
		for (int j = 0; j < k; ++j) {
			std::cin >> programs[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		std::sort(programs[i].begin(), programs[i].end(), std::greater<int>());
	}

	//Print the sorted programs
	/*for (int i = 0; i < n; ++i) {
		std::cout << "Day " << i + 1 << ": ";
		for (int j = 0; j < programs[i].size(); ++j) {
			std::cout << programs[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	int currMagic = 0;
	bool missday = false;
	std::map<std::pair<int, int>, int> cache;
	int i = rec(0, currMagic, programs, missday, cache);

	if (i == 0) {
		std::cout << -1 << '\n';
	}
	else {
		std::cout << i << '\n';
	}

}