/* 2350233 Ҷ�� ��21 */
#include <iostream>
#include <iomanip>
using namespace std;


void min(int a, int b, int c= 2147483647, int d= 2147483647)
{
	int middle1 = a > b ? b : a;
	int middle2 = c > d ? d : c;
	cout << "min=" << (middle1 > middle2 ? middle2 : middle1) << endl;
	return;
}

int main()
{
	while (1)
	{
		int x, a, b, c, d;
		cout << "���������num��num����������" << endl;
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
				min(a, b);
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
				min(a, b, c);
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
				min(a, b, c, d);
				break;
			}
		}
		else
		{
			cout << "�����������" << endl;
			break;
		}

	}

	return 0;
}