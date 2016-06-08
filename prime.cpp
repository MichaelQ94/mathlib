#include "prime.h"

PrimeSieve::PrimeSieve() : primesieve(3, true) {
	sieve();
}

PrimeSieve::PrimeSieve(unsigned max) : primesieve(max + 1, true) {
	sieve();
}

bool PrimeSieve::isPrime(unsigned n) {
	extendList(n);
	return primesieve[n];
}

void PrimeSieve::extendList(unsigned max) {
	if(max < primesieve.size()) return;

	primesieve = std::vector<bool>(max + 1, true);
	sieve();
}

size_t PrimeSieve::size() const {
	return primelist.size();
}

unsigned PrimeSieve::max() const {
	return primesieve.size() - 1;
}

unsigned PrimeSieve::operator[](size_t index) {
	return primelist[index];
}

void PrimeSieve::sieve() {
	size_t max = primesieve.size();

	switch(max) {
		case 2: primesieve[1] = false;
		case 1: primesieve[0] = false;
		case 0: return;
		default:
			primesieve[1] = false;
			primesieve[0] = false;
	}

	for(size_t i = 2; i < max; ++i)
		if(primesieve[i]) {
			primelist.push_back(i);

			for(size_t j = i + i; j < max; j += i)
				primesieve[j] = false;
		}
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

size_t ESieve::size() const {
	return numbers.size() - 1;
}

