#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double re, im;      // действительная и мнимая части

public:
	// конструкторы 

	Complex();//по умолчанию
	Complex(double r);
	Complex(double r, double i);
	Complex(const Complex& c);  // конструктор копирования
	~Complex(); 	// деструктор
	friend ostream& operator<< (ostream&, const Complex&);//перегрузка разрешена для доступа к внутренним элементам класса, чтобы записать в выходной поток
	//& т.к. потоковые объекты нельзя ни копировать, ни присваивать
	friend istream& operator>> (istream&, Complex&);
	//унарные операторы, не требуется передача параметра
	double abs();
	Complex conjugation();
	Complex M(int n);

	//бинарные операторы, необходимо передать объект справа от оператора - по ссылке (левый передается автоматически)
	Complex& operator = (Complex& c);
	Complex& operator += (Complex& c);
	Complex operator + (const Complex& c);
	Complex operator - (const Complex& c);
	Complex operator * (const Complex& c);
	Complex operator / (const Complex& c);
	
	//ostream& operator << (ostream& out, const Complex& c);
};
	
	
int main()
	{
		setlocale(LC_ALL, "");
		Complex a(9, 6);   //заполнение с помощью конструктора
		Complex b(2, -1);
		cout << "Введите действительную и мнимую части(заполняется с помощью конструктора)" << endl;

		int r, k;
		cin >> r;
		cin >> k;
		Complex t(r, k); //заполнение с помощью конструктора с использованием введеных данных
		cout<< "t = " << t << endl;  //вывод с использованием перегруженного оператора
		cout << "Введите действительную и мнимую части (заполняется через перегруженный оператор >>)" << endl;
		Complex h;
		cin >> h;
		cout <<  "h = " << h << endl;
		cout << endl << "Сопряженное h = " << h.conjugation() << endl;

		cout <<"Модуль h (не сопряженного): "<< h.abs() << endl;

		int n;
		cout << "Введите степень, в которую хотите возвести h (с помощью формулы Муавра)" << endl;
		cin >> n;
		cout <<"Счет по формуле Муавра: "<< h.M(n) << endl;

		cout << "a = " << a << "; b =" << b << endl << "Заполняются автоматически в программе" << endl;

		a += b;  //оператор += для нового класса

		cout << "После применения +=  a=" << a << "; b =" << b << endl;

		Complex c = a + b;  //оператор + для класса
		cout <<"Сумма a+b="<< c << endl;

		Complex d = a * b;
		cout << "Произведение a*b=" << d << endl;

		Complex g = a / b;
		cout << "Деление a/b=" << g << endl;

		Complex u = a - b;
		cout << "Вычитание a-b=" << u << endl;


		return 0;
	}