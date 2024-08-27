/*2350233	叶辰	信21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const double pi = 3.14159;
	double r, h, c_circle, s_circle, s_sphere, v_sphere, v_column;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	c_circle = 2 * pi * r;
	s_circle = pi * r * r;
	s_sphere = 4 * pi * r * r;
	v_sphere = 4.0 / 3.0 * pi * r * r * r;
	v_column = s_circle * h;
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << "圆周长     : " << c_circle << endl;
	cout << "圆面积     : " << s_circle << endl;
	cout << "圆球表面积 : " << s_sphere << endl;
	cout << "圆球体积   : " << v_sphere << endl;
	cout << "圆柱体积   : " << v_column << endl;
	return 0;
}