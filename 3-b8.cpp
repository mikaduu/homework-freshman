/* 2350233	叶辰	信21 */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int j = 1;  //j为计数器，帮助计算阶乘 
	double x, m, n = 1, total = 1;//m用于存储最初的x值，便于计算高次
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cout << setprecision(10);
	cin >> x;
	m = x;
	while (fabs(x / n) > 1e-6)
	{
		if (j == 1 && (x < -10 || 65 < x))
		{
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入x的值[-10 ~ +65]" << endl;
			cin >> x;
			m = x;
			continue;
		}
		total = total + x / n;
		j++;
		n = n * j;
		x = x * m;
		cout << x << "  " << n <<"     " << x / n << endl;
		getchar();
	}
	cout << "e^" << m << "=" << total << endl;
	return 0;
}
