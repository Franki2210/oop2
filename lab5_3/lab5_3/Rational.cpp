#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>

using namespace std;

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw invalid_argument("Denominator must not be zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GetGCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

int GetGCD(int a, int b) //greatest common divisor
{
	while (b)
	{
		swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

const CRational CRational::operator+() const
{
	return *this;
}
const CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

const CRational operator+(const CRational & lValue, const CRational & rValue)
{
	int resultNumerator = lValue.GetNumerator() * rValue.GetDenominator() + rValue.GetNumerator() * lValue.GetDenominator();
	int resultDenominator = lValue.GetDenominator() * rValue.GetDenominator();
	return CRational(resultNumerator, resultDenominator);
}

const CRational operator-(const CRational & lValue, const CRational & rValue)
{
	return operator+(lValue, -rValue);
}

const CRational & CRational::operator+=(const CRational & summand)
{
	if (summand.GetNumerator() == 0)
	{
		return *this;
	}
	m_numerator = m_numerator * summand.GetDenominator() + m_denominator * summand.GetNumerator();
	m_denominator = m_denominator * summand.GetDenominator();
	Normalize();
	return *this;
}

const CRational & CRational::operator-=(const CRational & subtrahend)
{
	if (subtrahend.GetNumerator() == 0)
	{
		return *this;
	}
	CRational::operator+=(-subtrahend);
	return *this;
}

const CRational operator*(CRational const& lValue, CRational const& rValue)
{
	return CRational(lValue.GetNumerator() * rValue.GetNumerator(), lValue.GetDenominator() * rValue.GetDenominator());
}

const CRational operator/(CRational const& lValue, CRational const& rValue)
{
	return CRational(operator*(lValue, CRational(rValue.GetDenominator(), rValue.GetNumerator())));
}

CRational const& CRational::operator*=(CRational const& rational)
{
	*this = *this * rational;
	return *this;
}

CRational const& CRational::operator/=(CRational const& rational)
{
	*this = *this / rational;
	return *this;
}

const bool operator==(CRational const & lValue, CRational const & rValue)
{
	CRational l = lValue, r = rValue;
	l.Normalize();
	r.Normalize();
	return (((l.GetNumerator() == r.GetNumerator()) && (r.GetDenominator() == l.GetDenominator())));
}

const bool operator!=(CRational const & lValue, CRational const & rValue)
{
	return !(lValue == rValue);
}

const bool operator<(CRational const & lValue, CRational const & rValue)
{
	return (lValue.GetNumerator() * rValue.GetDenominator() < rValue.GetNumerator() * lValue.GetDenominator());
}

const bool operator>=(CRational const & lValue, CRational const & rValue)
{
	return !(lValue < rValue);
}

const bool operator>(CRational const & lValue, CRational const & rValue)
{
	return (lValue.GetNumerator() * rValue.GetDenominator() > rValue.GetNumerator() * lValue.GetDenominator());
}

const bool operator<=(CRational const & lValue, CRational const & rValue)
{
	return !(lValue > rValue);
}

ostream & operator<<(ostream & output, CRational & rational)
{
	output << rational.GetNumerator() << '/' << rational.GetDenominator();
	return output;
}

istream & operator>>(istream & input, CRational & rational)
{
	int numerator = 0;
	int denominator = 1;
	if ((input >> numerator) && (input.get() == '/') && (input >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(ios_base::failbit);
	}
	return input;
}