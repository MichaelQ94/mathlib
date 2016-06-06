#include "rational.h"
#include <stdexcept>
#include "mathlib.h"
#include <iostream>
#define ABS(n) (n >= 0 ? n : -n)

Rational::Rational(int n) : N(n), D(1) {}
Rational::Rational(int n, unsigned d) : N(n), D(d) {
	if(D == 0) {
		std::cout << n << std::endl;
		throw std::invalid_argument("Denominator of rational cannot be 0");
	}
}

int Rational::n() const { return N; }
unsigned Rational::d() const { return D; }
void Rational::setN(int n) { N = n; }
void Rational::setD(unsigned d) { D = d; }

Rational Rational::reduce() const {
	unsigned gcd = Math::gcd(ABS(N), D);
	return Rational(N/static_cast<int>(gcd), D/gcd);
}

bool Rational::operator==(Rational r) const {
	return N * r.D == D * r.N;
}

bool Rational::operator!=(Rational r) const {
	return N * r.D != D * r.N;
}

bool Rational::operator<(Rational r) const {
	return N * r.D < D * r.N;
}

bool Rational::operator>(Rational r) const {
	return N * r.D > D * r.N;
}

bool Rational::operator<=(Rational r) const {
	return N * r.D <= D * r.N;
}

bool Rational::operator>=(Rational r) const {
	return N * r.D >= D * r.N;
}

Rational Rational::operator+(Rational r) const {
	return Rational((N * r.D) + (D * r.N), D * r.D).reduce();
}

Rational Rational::operator-(Rational r) const {
	return Rational((N * r.D) - (D * r.N), D * r.D).reduce();
}

Rational Rational::operator*(Rational r) const {
	return Rational(N * r.N, D * r.D).reduce();
}

Rational Rational::operator/(Rational r) const {
	return (*this) * r.recip();
}

Rational Rational::operator+=(Rational r) {
	*this = (*this) + r;
	return *this;
}

Rational Rational::operator-=(Rational r) {
	*this = (*this) - r;
	return *this;
}

Rational Rational::operator*=(Rational r) {
	*this = (*this) * r;
	return *this;
}

Rational Rational::operator/=(Rational r) {
	*this = (*this) / r;
	return *this;
}

Rational Rational::recip() const {
	if(N) {
		int sign = (N > 0 ? 1 : -1);
		return Rational(D * sign, ABS(N));
	}
	else {
		throw std::invalid_argument("Cannot take reciprocal of 0");
	}
}

Rational Rational::abs() const {
	return Rational(ABS(N), D);
}

void Rational::print() const {
	std::cout << N << '/' << D << std::endl;
}

