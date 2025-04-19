#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> eggs(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> eggs[i];
	}

	std::vector<std::vector<int>> possibleEggs;
	for (int i = 0; i < n; ++i) {
		std::vector<int> temp;
		for (int j = 0; j < n; ++j) {
			if (eggs[j] - k < eggs[i]) {
				temp.push_back(eggs[j]);
			}
		}
		possibleEggs.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		std::cout << "Egg " << i + 1 << ": ";
		for (int j = 0; j < possibleEggs[i].size(); ++j) {
			std::cout << possibleEggs[i][j] + 1 << " ";
		}
		std::cout << std::endl;
	}

}