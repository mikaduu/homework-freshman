/*2350233	Ҷ��	��21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const double pi = 3.14159;
	double r, h, c_circle, s_circle, s_sphere, v_sphere, v_column;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	c_circle = 2 * pi * r;
	s_circle = pi * r * r;
	s_sphere = 4 * pi * r * r;
	v_sphere = 4.0 / 3.0 * pi * r * r * r;
	v_column = s_circle * h;
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << "Բ�ܳ�     : " << c_circle << endl;
	cout << "Բ���     : " << s_circle << endl;
	cout << "Բ������ : " << s_sphere << endl;
	cout << "Բ�����   : " << v_sphere << endl;
	cout << "Բ�����   : " << v_column << endl;
	return 0;
}