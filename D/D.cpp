#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::map<int, std::vector<int>> tunnels;
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		tunnels[a].push_back(b);
		tunnels[b].push_back(a);
	}

	std::set<int> possiblePositions = { 1 };
	//std::map<int, std::set<int>> cache;
	std::vector<std::set<int>> history;

	int loopStart = -1;

	for (int i = 0; i < k; i++) {

		//check if in loop based on history
		bool inLoop = false;
		for (int j = 0; j < history.size(); ++j) {
			if (history[j] == possiblePositions) {
				inLoop = true;
				loopStart = j;
				break;
			}
		}
		if (inLoop) {
			break;
		}

		history.push_back(possiblePositions);

		std::set<int> newPositions;
		for (int pos : possiblePositions) {
			//if (cache.find(pos) != cache.end()) {
			//	newPositions.insert(cache[pos].begin(), cache[pos].end());
			//}
			//else {
				std::set<int> neighbors;
				for (int tunnel : tunnels[pos]) {
					neighbors.insert(tunnel);
				}
				//cache[pos] = neighbors;
				newPositions.insert(neighbors.begin(), neighbors.end());
			//}
		}

		possiblePositions = newPositions;
	}


	if (loopStart != -1) {
		int loopSize = history.size() - loopStart;
		int remainingSteps = (k - loopStart) % loopSize;
		possiblePositions = history[loopStart + remainingSteps];
	}


	std::cout << possiblePositions.size() << std::endl;
	for (int pos : possiblePositions) {
		std::cout << pos << " ";
	}
	std::cout << std::endl;

	
}