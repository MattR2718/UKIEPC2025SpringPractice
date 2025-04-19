#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>


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
	std::set<int> intersection;
	std::set_intersection(startSet.begin(), startSet.end(), goalSet.begin(), goalSet.end(),
		std::inserter(intersection, intersection.begin()));
    if(intersection != start)



}