#include "Complex.h"
TComplex::TComplex(double re_, double im_)
{
	re = re_;
	im = im_;
}

TComplex::TComplex(const TComplex& c)
{
	re = c.re;
	im = c.im;
}

double TComplex::GetRe()
{
	return re;
}

void TComplex::SetRe(double re_)
{
	re = re_;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetIm(double im_)
{
	im = im_;
}

TComplex TComplex::Add(TComplex& b)
{
	TComplex res(*this);
	res.re += b.re;
	res.im += b.im;
	return res;
}

TComplex TComplex::Mult(TComplex& b)
{
	TComplex res;
	res.re += re * b.re - im * b.im;
	res.im += im * b.re + re * b.im;
	return res;
}

TComplex TComplex::operator+(TComplex& p)
{
	TComplex res(*this);
	res.re += p.re;
	res.im += p.im;
	return res;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex res(*this);
	res.re -= p.re;
	res.im -= p.im;
	return res;
}

TComplex TComplex::operator*(TComplex& p)
{
	TComplex res;
	res.re += re * p.re - im * p.im;
	res.im += im * p.re + re * p.im;
	return res;
}

TComplex TComplex::operator/(TComplex& p)
{
	TComplex res;
	res.re = (re * p.re + im * p.im) / (p.re * p.re + p.im * p.im);
	res.im = (im * p.re - re * p.im) / (p.re * p.re + p.im * p.im);
	return res;
}

TComplex& TComplex::operator=(TComplex& p)
{
	if (this != &p)
	{
		re = p.re;
		im = p.im;
	}

	return *this;
}

bool TComplex::operator==(TComplex& p)
{
	return (re == p.re) && (im == p.im);
}

bool TComplex::operator!=(TComplex& p)
{
	return !(this->operator==(p));
}

std::istream& operator >> (std::istream& istr, TComplex& p)
{
	std::cout << "Re = ";
	istr >> p.re;
	std::cout << "Im = ";
	istr >> p.im;
	return istr;
}

std::ostream& operator << (std::ostream& ostr, TComplex& p)
{
	ostr << p.GetRe() << " + i * " << p.GetIm();
	return ostr;
}