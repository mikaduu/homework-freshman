/*2350233	叶辰	信21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a, w, q, b, s, g;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	w = a / 10000;
	q = (a / 1000) % 10;
	b = (a / 100) % 10;
	s = (a / 10) % 10;
	g = a % 10;
	cout << "万位 : " << w << endl;
	cout << "千位 : " << q << endl;
	cout << "百位 : " << b << endl;
	cout << "十位 : " << s << endl;
	cout << "个位 : " << g << endl;
	return 0;
}