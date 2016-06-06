#include "mathlib.h"
#define BITS_PER_BYTE 8

unsigned Math::gcd(unsigned a, unsigned b) {
	unsigned large, small, rgcd;
	if(a < b) {
		small = a;
		large = b;
	}
	else {
		small = b;
		large = a;
	}
	rgcd = large;
	
	while(small) {
		rgcd = small;
		small = large % small;
		large = rgcd;
	}

	return rgcd;
}

int Math::pow(int n, unsigned p) {
	int ret = 1;
	for(; p > 0; --p) {
		ret *= n;
	}
	return ret;
}

unsigned Math::fac(unsigned n) {
	unsigned ret = 1;
	for(unsigned i = 2; i <= n; ++i) {
		ret *= i;
	}
	return ret;
}

unsigned Math::permute(unsigned n, unsigned r) {
	if(r <= n) {
		unsigned ret = 1;
		for(unsigned i = n - r + 1; i <= n; ++i) {
			ret *= i;
		}
		return ret;
	}
	else {
		return 0;
	}
}

unsigned Math::choose(unsigned n, unsigned r) {
	if(r <= n) {
		return Math::permute(n, r) / Math::fac(r);
	}
	else {
		return 0;
	}
}

unsigned Math::countdigits(unsigned n) {
	unsigned digits = 1;
	while(n /= 10) {
		++digits;
	}
	return digits;
}

unsigned Math::countbits(unsigned n) {
	unsigned shift = (sizeof(unsigned) * BITS_PER_BYTE) - 1;
	for(; shift > 0; --shift) {
		if(n & (1 << shift)) {
			return shift + 1;
		}
	}
	return 1;
}
