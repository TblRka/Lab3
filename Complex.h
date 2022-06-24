#pragma once
#include <iostream>

class Complex
{
private:
	double Re = 0.0;
	double Im = 0.0;

public:
	Complex() : Re(0.0), Im(0.0) {}
	Complex(double x, double y) : Re(x), Im(y) {}
	Complex(const Complex& z) : Re(z.Re), Im(z.Im) {}
	~Complex() {}

	double GetRe() const
	{
		return Re;
	}
	double GetIm() const
	{
		return Im;
	}
	void Print()
	{
		std::cout << Re << ((Im >= 0) ? " + " : " ") << Im << "*i" << std::endl;
	}

	Complex& operator=(Complex z)
	{
		std::swap(Re, z.Re);
		std::swap(Im, z.Im);
		return *this;
	}

	Complex& operator+=(Complex z)
	{
		Re += z.Re;
		Im += z.Im;
		return *this;
	}

	Complex& operator-=(Complex z)
	{
		Re -= z.Re;
		Im -= z.Im;
		return *this;
	}

	Complex& operator*=(Complex z)
	{
		Re = Re * z.Re - Im * z.Im;
		Im = Re * z.Im + Im * z.Re;
		return *this;
	}

	Complex& operator/=(Complex z)
	{
		if (z.Re == 0.0 && z.Im == 0.0)
		{
			throw std::exception("Devided by zero");
		}
		Re = (Re * z.Re - Im * z.Im) / (z.Re * z.Re + z.Im * z.Im);
		Im = (Re * z.Im + Im * z.Re) / (z.Re * z.Re + z.Im * z.Im);
		return *this;
	}
};

Complex operator+(const Complex& a, const Complex& b)
{
	Complex copy = a;
	copy += b;
	return copy;
}

Complex operator-(const Complex& a, const Complex& b)
{
	Complex copy = a;
	copy -= b;
	return copy;
}

Complex operator*(const Complex& a, const Complex& b)
{
	Complex copy = a;
	copy *= b;
	return copy;
}

Complex operator/(const Complex& a, const Complex& b)
{
	Complex copy = a;
	copy /= b;
	return copy;
}

bool operator<(const Complex& a, const Complex& b)
{
	return (a.GetRe() * a.GetRe() + a.GetIm() * a.GetIm() < b.GetRe() * b.GetRe() + b.GetIm() * b.GetIm());
};

bool operator>(const Complex& a, const Complex& b)
{
	return (a.GetRe() * a.GetRe() + a.GetIm() * a.GetIm() > b.GetRe() * b.GetRe() + b.GetIm() * b.GetIm());
};

bool operator==(const Complex& a, const Complex& b)
{
	return (a.GetRe() * a.GetRe() + a.GetIm() * a.GetIm() == b.GetRe() * b.GetRe() + b.GetIm() * b.GetIm());
};

bool operator!=(const Complex& a, const Complex& b)
{
	return (a.GetRe() * a.GetRe() + a.GetIm() * a.GetIm() != b.GetRe() * b.GetRe() + b.GetIm() * b.GetIm());
};

std::ostream& operator<<(std::ostream& out, const Complex& z) {
	out << z.GetRe() << ((z.GetIm() >= 0) ? " + " : " ") << z.GetIm() << "*i";
	return out;
};
