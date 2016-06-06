#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int N;
	unsigned D;
	Rational();

public:
	Rational(int);
	Rational(int, unsigned);
	
	int n() const;
	unsigned d() const;
	void setN(int);
	void setD(unsigned);
	
	Rational reduce() const;
	bool operator==(Rational) const;
	bool operator!=(Rational) const;
	bool operator<(Rational) const;
	bool operator>(Rational) const;
	bool operator<=(Rational) const;
	bool operator>=(Rational) const;
	Rational operator+(Rational) const;
	Rational operator-(Rational) const;
	Rational operator*(Rational) const;
	Rational operator/(Rational) const;
	Rational operator+=(Rational);
	Rational operator-=(Rational);
	Rational operator*=(Rational);
	Rational operator/=(Rational);
	Rational recip() const;
	Rational abs() const;

	void print() const;
};

#endif
