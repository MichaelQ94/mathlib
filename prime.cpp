#include "prime.h"

bool binary_search(std::vector<unsigned>&, unsigned, size_t, size_t);

PrimeSieve::PrimeSieve() : max(3) {
	primelist.push_back(2);
	primelist.push_back(3);
}

PrimeSieve::PrimeSieve(unsigned n) : max(3) {
	primelist.push_back(2);
	primelist.push_back(3);

	extendList(n);
}

bool PrimeSieve::isPrime(unsigned n) {
	extendList(n);

	return binary_search(primelist, n, 0, primelist.size() - 1);
}

void PrimeSieve::extendList(unsigned n) {
	if(n <= max) return;

	bool prime;
	for(max += 2; max <= n; max += 2) {
		prime = true;

		for(unsigned i = 0; i < primelist.size(); ++i) {
			if(max % primelist[i] == 0) {
				prime = false;
				break;
			}
		}

		if(prime) primelist.push_back(max);
	}

	if(n % 2 == 0) max -= 2;
}

size_t PrimeSieve::size() const {
	return primelist.size();
}

unsigned PrimeSieve::operator[](size_t index) {
	return primelist[index];
}

ESieve::ESieve() : numbers(3, true) {
	sieve();
}

ESieve::ESieve(unsigned max) : numbers(max + 1, true) {
	sieve();
}

bool ESieve::isPrime(unsigned num) {
	extendList(num);
	return numbers[num];
}

void ESieve::extendList(unsigned max) {
	if(max < numbers.size()) return;

	numbers = std::move(std::vector<bool>(max + 1, true));

	sieve();
}

void ESieve::sieve() {
	switch(numbers.size()) {
		case 2:
			numbers[1] = false;
		case 1:
			numbers[0] = false;
		case 0:
			return;
		default:
			numbers[0] = false;
			numbers[1] = false;
	}

	size_t max = numbers.size();
	for(size_t i = 2; i <= max; ++i)
		if(numbers[i])
			for(size_t j = i + i; j <= max; j += i)
				numbers[j] = false;
}

bool binary_search(std::vector<unsigned> &list, unsigned n, size_t start, size_t end) {
	if(start > end) return false;
	
	size_t mid = (start + end) / 2;
	
	if(n < list[mid]) {
		if(mid == start) return false;
		else return binary_search(list, n, start, mid-1);
	}
	else if(n > list[mid]) return binary_search(list, n, mid+1, end);
	else return true; //list[mid] == n
}

