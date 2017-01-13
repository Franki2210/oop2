#pragma once

using namespace std;

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;

	int GetDenominator() const;

	void Normalize();

	
	double ToDouble() const;

	const CRational operator+() const;
	const CRational operator-() const;

	CRational const& operator+=(const CRational & subtrahend);

	
	CRational const& operator-=(const CRational & subtrahend);

	CRational const& operator*=(CRational const& r);

	CRational const& CRational::operator/=(CRational const& r);
private:
	int m_numerator;
	int m_denominator;
};

int GetGCD(int a, int b);

const CRational operator+(const CRational & lValue, const CRational & rValue);

const CRational operator-(const CRational & lValue, const CRational & rValue);

const CRational operator*(CRational const& lValue, CRational const& rValue);

const CRational operator/(CRational const& lValue, CRational const& rValue);

const bool operator==(CRational const & lValue, CRational const & rValue);
const bool operator!=(CRational const & lValue, CRational const & rValue);

const bool operator<(CRational const & lValue, CRational const & rValue);
const bool operator>=(CRational const & lValue, CRational const & rValue);
const bool operator>(CRational const & lValue, CRational const & rValue);
const bool operator<=(CRational const & lValue, CRational const & rValue);

ostream & operator<<(ostream & output, CRational & rational);

istream & operator>>(istream & input, CRational & rational);