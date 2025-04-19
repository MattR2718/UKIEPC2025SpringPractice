#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>


std::vector<int> getPrimeFactors(int n, std::map<int, std::vector<int>>& cache) {
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    int n1 = n;
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;

            if (cache.find(n) != cache.end()) {
                factors.insert(factors.end(), cache[n].begin(), cache[n].end());
                cache[n * i] = factors;
                return factors;
            }
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    cache[n1] = factors;
    return factors;
}




int main() {
	int start, goal;
	std::cin >> start >> goal;
	std::map<int, std::vector<int>> cache;

	auto factorsStart = getPrimeFactors(start, cache);
	auto factorsGoal = getPrimeFactors(goal, cache);

	std::set<int> startSet = { factorsStart.begin(), factorsStart.end() };
	std::set<int> goalSet = { factorsGoal.begin(), factorsGoal.end() };
	/*std::set<int> intersection;
	std::set_intersection(startSet.begin(), startSet.end(), goalSet.begin(), goalSet.end(),
		std::inserter(intersection, intersection.begin()));
	if (intersection != startSet || intersection != goalSet) {
		std::cout << "NO" << std::endl;
		return 0;
	}*/

	if (!std::includes(startSet.begin(), startSet.end(), goalSet.begin(), goalSet.end())) {
		std::cout << "NO" << std::endl;
		return 0;
	}

    // get fastest way to get to goal by duplicating start factors or removing elements
	std::map<int, int> goalNumbers;
	for (int i = 0; i < factorsGoal.size(); ++i) {
		goalNumbers[factorsGoal[i]]++;
	}
	std::map<int, int> startNumbers;
	for (int i = 0; i < factorsStart.size(); ++i) {
		startNumbers[factorsStart[i]]++;
	}

	std::vector<int> res;

	//std::queue<int> q;
	//std::unordered_map<int, std::pair<int, int>> parent;
	//std::unordered_set<int> visited;


	//q.push(start);
	//visited.insert(start);

	//while (!q.empty()) {
	//	int curr = q.front();
	//	q.pop();
	//	if (curr == goal) {
	//		std::vector<int> ops;
	//		while (curr != start) {
	//			ops.push_back(parent[curr].second);
	//			curr = parent[curr].first;
	//		}
	//		std::reverse(ops.begin(), ops.end());
	//		std::cout << "YES\n";
	//		for (int op : ops) std::cout << op << " ";
	//		return 0;
	//	}

	//	long long squared = 1LL * curr * curr;
	//	if (!visited.count(squared)) {
	//		q.push(squared);
	//		visited.insert(squared);
	//		parent[squared] = { curr, 0 };
	//	}

	//	// Try dividing by each prime factor
	//	for (int factor : startSet) {
	//		if (curr % factor == 0) {
	//			int next = curr / factor;
	//			if (!visited.count(next)) {
	//				q.push(next);
	//				visited.insert(next);
	//				parent[next] = { curr, factor };
	//			}
	//		}
	//	}
	//}

	while (goalNumbers != startNumbers) {
		
		for (auto& v : startNumbers) {
			if (goalNumbers[v.first] < v.second) {
				for (int i = 0; i < v.second - goalNumbers[v.first]; ++i) {
					res.push_back(v.first);
				}
				v.second = goalNumbers[v.first];
			}
		}


		if (goalNumbers != startNumbers) {
		for (auto& v : startNumbers) {
				v.second *= 2;
				
			}
			res.push_back(0);
		}
	}

	std::cout << "YES\n";
	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " ";
	}

}