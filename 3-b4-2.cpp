/*2350233	Ҷ��	��21*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	float s;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> c;
	s = 0.5F * a * b * float(sin(c / 180.0 * pi));
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "���������Ϊ : " << s << endl;
	return 0;
}