/*2350233	Ҷ��	��21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a, w, q, b, s, g;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	w = a / 10000;
	q = (a / 1000) % 10;
	b = (a / 100) % 10;
	s = (a / 10) % 10;
	g = a % 10;
	cout << "��λ : " << w << endl;
	cout << "ǧλ : " << q << endl;
	cout << "��λ : " << b << endl;
	cout << "ʮλ : " << s << endl;
	cout << "��λ : " << g << endl;
	return 0;
}