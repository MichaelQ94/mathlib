#include <iostream>
#include "rational.h"
#include "mathlib.h"
#include "prime.h"
#include "algorithm.h"

#include <vector>
#include <utility>

int add(const int&, const int&);
bool isEven(const int&);
int triple(const int&);
void printVec(const std::vector<int>&);
bool filter(const std::vector<int>&);

int main() {
	std::vector<int> nums;
	for(unsigned i = 0; i < 4; ++i) {
		nums.push_back(i);
	}

	printVec(Math::filter<int>(nums, &isEven));

	printVec(Math::map<int>(nums, &triple));

	std::cout << Math::reduce<int>(nums, &add) << std::endl;

	PrimeSieve primes;
	auto primefactors = primes.prime_factorization(120);
	for(unsigned i = 0; i < primefactors.size(); ++i) {
		std::cout << primefactors[i].first << ' ' << primefactors[i].second << std::endl;
	}

	return 0;
}

int add(const int &a, const int &b) { return a + b; }

bool isEven(const int &a) { return (a % 2) == 0; }

int triple(const int &a) { return 3 * a; }

void printVec(const std::vector<int> &list) {
	for(unsigned i = 0; i < list.size(); ++i)
		std::cout << list[i] << ' ';
	std::cout << std::endl;
}

bool filter(const std::vector<int> &list) {
	if(list.size() > 0)
		return list[0] == 0;
	else
		return true;
}
