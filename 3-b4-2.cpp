/*2350233	叶辰	信21*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	float s;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> c;
	s = 0.5F * a * b * float(sin(c / 180.0 * pi));
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为 : " << s << endl;
	return 0;
}