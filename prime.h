#ifndef PRIME_H
#define PRIME_H

#include <vector>
#include <cstddef>

class PrimeSieve {
private:
	std::vector<bool> primesieve;
	std::vector<unsigned> primelist;

	void sieve();

public:
	PrimeSieve();
	PrimeSieve(unsigned);
	bool isPrime(unsigned);
	void extendList(unsigned);
	size_t size() const;
	unsigned max() const;
	unsigned operator[](size_t);
};

class ESieve {
private:
	std::vector<bool> numbers;

	void sieve();
public:
	ESieve();
	ESieve(unsigned);
	void extendList(unsigned);
	bool isPrime(unsigned);
	size_t size() const;
};

#endif
