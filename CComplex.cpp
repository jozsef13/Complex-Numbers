#include "CComplex.h"

double CComplex::combinari(int n, int k)
{
	if (k == 0)
		return 1;
	else if (k > n)
		return 0;
	else
		return (combinari(n - 1, k) + combinari(n - 1, k - 1));
}

void CComplex::print() const
{
	cout << "z = " << real << showpos << imaginary << 'i' << noshowpos << endl;
}

CComplex CComplex::operator + (CComplex const &obj)
{
	CComplex sum;
	sum.real = this->real + obj.real;
	sum.imaginary = this->imaginary + obj.imaginary;
	return sum;
}

CComplex CComplex::operator - (CComplex const &obj)
{
	CComplex dif;
	dif.real = this->real - obj.real;
	dif.imaginary = this->imaginary - obj.imaginary;
	return dif;
}

CComplex CComplex::operator * (CComplex const &obj)
{
	CComplex prod;

	prod.real = (real * obj.real) - (imaginary * obj.imaginary);
	prod.imaginary = (real * obj.imaginary) + (imaginary * obj.real);

	return prod;
}

CComplex CComplex::operator / (CComplex const &obj)
{
	CComplex div;

	div.real = ((real * obj.real) + (imaginary * obj.imaginary)) / ((obj.real * obj.real) + (obj.imaginary * obj.imaginary));
	div.imaginary = ((obj.real * imaginary) - (real * obj.imaginary)) / ((obj.real * obj.real) + (obj.imaginary * obj.imaginary));

	return div;
}

double CComplex::operator ~ ()
{
	CComplex modul;
	double modulD;

	modul.real = real * real;
	modul.imaginary = imaginary * imaginary;
	modulD = sqrt(modul.real + modul.imaginary);

	return modulD;
}

CComplex CComplex::operator ^ (int n)
{
	CComplex putere;

	for (int k = 0; k <= n; k += 2)
	{
		putere.real = putere.real + combinari(n, k) * pow(-1, k / 2) * pow(real, n - k) * pow(imaginary, k);
	}

	for (int k = 1; k <= n; k += 2)
	{
		putere.imaginary = putere.imaginary + combinari(n, k) *	pow(-1, (k - 1) / 2) * pow(real, n - k) * pow(imaginary, k);
	}

	return putere;
}