#pragma once
#include <iostream>
#include <cmath>
#include "Complex.h"

	Complex::Complex()
	{

	};

	Complex::Complex(double r)
	{
		re = r;
		im = 0;
	}

	Complex::Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex::Complex(const Complex& c)   // конструктор копирования
	{
		re = c.re;
		im = c.im;
	}

	// деструктор
	Complex::~Complex()
	{
		//delete[];
	}

	// остальные функции

	// Модуль комплексного числа
	double Complex::abs() //унарный оператор => не требуется передача параметра
	{
		return sqrt(re * re + im * im);//корень из суммы квадратов вещественной и мнимой частей
	}

	Complex Complex::M(int n)
	{
		double k = sqrt(re * re + im * im);
		double p=pow(k, n);
		double phi = atan(im / re);
		double _re = p * cos(n * phi);
		double _im = p * sin(n * phi);
		Complex Myr(_re,_im);
		return Myr;
		
	}

	Complex Complex::conjugation() //тоже унарный
	{
		double r = re;
		double i = -im;
		Complex p(r, i);//конструктор создаст свою копию
		return p;

	}
	// оператор присваивания
	Complex& Complex::operator = (Complex& c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}


	// оператор +=
	Complex& Complex::operator += (Complex& c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	// оператор сложения
	Complex Complex::operator + (const Complex& c)
	{
		return Complex(re + c.re, im + c.im);
	}

	// оператор вычитания
	Complex Complex::operator - (const Complex& c)
	{
		return Complex(re - c.re, im - c.im);
	}

	// оператор умножения
	Complex Complex::operator * (const Complex& c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	// оператор деления
	Complex Complex::operator / (const Complex& c)
	{
		Complex t;//как через this передаются значения левого объекта

		double r = c.re * c.re + c.im * c.im;
		t.re = (re * c.re + im * c.im) / r;
		t.im = (im * c.re - re * c.im) / r;

		return t;
	}

//  оператор << вывод
ostream& operator<< (ostream& out, const Complex& c)
{
	if (c.im > 0) {
		
		//out << "" << c.re << "+ " << c.im << "*i";
		out << "" << c.re << "+ ";
		if (c.im == 1) {
			out << "i";
		}
		else {
			out<< c.im << "*i";
		}
	}
	else
	{
		//out << "" << c.re << "" << c.im << "*i";
		out << "" << c.re;
		if (c.im == -1) {
			out << "-i";
		}
		else {
			out << c.im << "*i";
		}
	}
	return out;
}

//  оператор >> ввод
istream& operator>> (istream& in, Complex& c)
{
	in >> c.re >> c.im;
	return in;
}

