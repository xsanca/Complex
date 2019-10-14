#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double re, im;      // �������������� � ������ �����

public:
	// ������������ 

	Complex();//�� ���������
	Complex(double r);
	Complex(double r, double i);
	Complex(const Complex& c);  // ����������� �����������
	~Complex(); 	// ����������
	friend ostream& operator<< (ostream&, const Complex&);//���������� ��������� ��� ������� � ���������� ��������� ������, ����� �������� � �������� �����
	//& �.�. ��������� ������� ������ �� ����������, �� �����������
	friend istream& operator>> (istream&, Complex&);
	//������� ���������, �� ��������� �������� ���������
	double abs();
	Complex conjugation();
	Complex M(int n);

	//�������� ���������, ���������� �������� ������ ������ �� ��������� - �� ������ (����� ���������� �������������)
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
		Complex a(9, 6);   //���������� � ������� ������������
		Complex b(2, -1);
		cout << "������� �������������� � ������ �����(����������� � ������� ������������)" << endl;

		int r, k;
		cin >> r;
		cin >> k;
		Complex t(r, k); //���������� � ������� ������������ � �������������� �������� ������
		cout<< "t = " << t << endl;  //����� � �������������� �������������� ���������
		cout << "������� �������������� � ������ ����� (����������� ����� ������������� �������� >>)" << endl;
		Complex h;
		cin >> h;
		cout <<  "h = " << h << endl;
		cout << endl << "����������� h = " << h.conjugation() << endl;

		cout <<"������ h (�� ������������): "<< h.abs() << endl;

		int n;
		cout << "������� �������, � ������� ������ �������� h (� ������� ������� ������)" << endl;
		cin >> n;
		cout <<"���� �� ������� ������: "<< h.M(n) << endl;

		cout << "a = " << a << "; b =" << b << endl << "����������� ������������� � ���������" << endl;

		a += b;  //�������� += ��� ������ ������

		cout << "����� ���������� +=  a=" << a << "; b =" << b << endl;

		Complex c = a + b;  //�������� + ��� ������
		cout <<"����� a+b="<< c << endl;

		Complex d = a * b;
		cout << "������������ a*b=" << d << endl;

		Complex g = a / b;
		cout << "������� a/b=" << g << endl;

		Complex u = a - b;
		cout << "��������� a-b=" << u << endl;


		return 0;
	}