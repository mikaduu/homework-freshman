/* 2350233	叶辰	信21 */
#include <iostream>
//#include<limits>
#include <iomanip>
using namespace std;

int zeller(int y, int m,int d)
{
	int w, c, y1;
	if (m == 1)
	{
		m = 13;
		y = y - 1;
	}
	else if (m == 2)
	{
		m = 14;
		y = y - 1;
	}
	y1 = y % 100;
	c = y / 100;
	w = y1 + y1 / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	w = w + 7000;//加一个较大的7的倍数，防止为负，且要使不会超过int的范围
	/*switch (w % 7)
	{
		case 0:
			cout << "星期天" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}*/
	return w%7;
}

void calender(int year, int month)
{
	/* 按需添加代码 */
	int a,b,day;
	a = zeller(year, month, 1);
	b = 1;
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 400 == 0)))
	{
		if (month == 2)
		{
			day = 29;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	else
	{
		if (month == 2)
		{
			day = 28;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	
	/* 头部分隔线，不算打表 */
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	cout << setw(4 * 2 * a) << "";
	while (b <= day)
	{
		cout << setw(4) << b << setw(4) << "";
		if ((b + a) % 7 == 0)
		{
			if (b+1>day)
			{
				;
			}
			else
			{
				cout << endl;
			}
		}
		b++;
	}
	cout << endl;

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	int y, m;
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m ;
		if (!cin.good()) // 检查输入是否失败
		{
			cin.clear(); // 清除输入缓冲区
			cin.ignore(65536, '\n'); // 忽略输入缓冲区中的所有内容
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (1900 <= y && y <= 2100)
		{
			if (1 <= m && m <= 12)
			{
				break;
			}
			else
			{
				cout << "月份不正确，请重新输入" << endl;
				cin.clear(); 
				cin.ignore(65536, '\n');
			}
		}
		else
		{
			cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}

	
	calender(y, m);
	return 0;
}