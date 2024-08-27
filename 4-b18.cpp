/* 2350233 叶辰 信21 */
#include <iostream>
#include <iomanip>
using namespace std;

void max(int a, int b)
{
	cout << "max=" << (a > b ? a : b) << endl;
	return;
}
void max(int a, int b, int c)
{
	int middle = a > b ? a : b;
	cout << "max=" << (middle > c ? middle : c) << endl;
	return; 
}
void max(int a, int b, int c, int d)
{
	int middle1 = a > b ? a : b;
	int middle2 = c > d ? c : d;
	cout << "max=" << (middle1 > middle2 ? middle1 : middle2) << endl;
	return;
}

int main()
{
	while (1)
	{
		int x, a, b, c, d;
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> x >> a >> b;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (x == 2)
		{
			if (a <= 0 || b <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else;
			{
				max(a, b);
				break;
			}
		}
		else if (x == 3)
		{
			cin >> c;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (a <= 0 || b <= 0 || c <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
			{
				max(a, b, c);
				break;
			}
		}
		else if (x == 4)
		{
			cin >> c >> d;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
			{
				max(a, b, c, d);
				break;
			}
		}
		else
		{
			cout << "个数输入错误" << endl;
			break;
		}

	}

	return 0;
}