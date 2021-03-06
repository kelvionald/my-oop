#pragma once

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;
	CComplex operator+(const CComplex& a) const;
	CComplex operator-(const CComplex& a) const;
	CComplex operator*(const CComplex& a) const;
	CComplex operator/(const CComplex& a) const;
	CComplex operator+() const;
	CComplex operator-() const;
	friend CComplex& operator+=(CComplex& a, const CComplex& b);
	friend CComplex& operator-=(CComplex& a, const CComplex& b);
	friend CComplex& operator*=(CComplex& a, const CComplex& b);
	friend CComplex& operator/=(CComplex& a, const CComplex& b);
	bool operator==(const CComplex& a) const;
	bool operator!=(const CComplex& a) const;

private:
	double m_real;
	double m_image;
};

CComplex operator+(double a, const CComplex& b);
CComplex operator-(double a, const CComplex& b);
CComplex operator*(double a, const CComplex& b);
CComplex operator/(double a, const CComplex& b);
bool operator==(double a, const CComplex& b);
bool operator!=(double a, const CComplex& b);