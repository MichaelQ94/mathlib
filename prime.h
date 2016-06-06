#ifndef PRIME_H
#define PRIME_H

#include <vector>
#include <cstddef>

class PrimeSieve {
private:
	std::vector<unsigned> primelist;
	unsigned max;

public:
	PrimeSieve();
	PrimeSieve(unsigned);
	bool isPrime(unsigned);
	void extendList(unsigned);
	size_t size() const;
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
