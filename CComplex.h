#pragma once
#include <iostream>
#include <math.h>
using namespace std;



class CComplex
{
public:
	CComplex() : imaginary(0), real(0) {}
	CComplex(double real) : real(real), imaginary(0) {}
	CComplex(double real, double imaginary) : real(real), imaginary(imaginary) {}
	CComplex operator + (CComplex const &obj);
	CComplex operator - (CComplex const &obj);
	CComplex operator * (CComplex const &obj);
	CComplex operator / (CComplex const &obj);
	double operator ~ ();
	CComplex operator ^ (int n);
	friend ostream &operator<<(ostream &output, const CComplex &obj)
	{
		output << obj.real << showpos << obj.imaginary << 'i' << noshowpos << endl;
		return output;
	}
	friend istream &operator>>(istream &input, CComplex &obj)
	{
		input >> obj.real >> obj.imaginary;
		return input;
	}
	

	void print() const;
	
private:
	double real, imaginary;
	double combinari(int n, int k);
};

