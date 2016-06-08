#ifndef PRIME_H
#define PRIME_H

#include <vector>
#include <utility>
#include <cstddef>

class PrimeSieve {
private:
	std::vector<bool> primesieve;
	std::vector<unsigned> primelist;

	void sift();

public:
	PrimeSieve();
	PrimeSieve(unsigned);
	bool isPrime(unsigned);
	void extendList(unsigned);
	size_t size() const;
	unsigned max() const;
	unsigned operator[](size_t);
	std::vector<std::pair<unsigned, unsigned> > prime_factorization(unsigned);
};

class ESieve {
private:
	std::vector<bool> numbers;

	void sift();
public:
	ESieve();
	ESieve(unsigned);
	void extendList(unsigned);
	bool isPrime(unsigned);
	size_t size() const;
};

#endif
