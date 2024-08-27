/* 2350233	叶辰	信21 */
#include <iostream>
//#include<limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int w,c,y1;
	
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
	switch (w%7)
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
	}
	return 0;
}

int main()
{
	int y, m, d;
	while (1) 
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
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
				if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 4 == 0) && (y % 400 == 0)) && m == 2 && 0 < d && d <= 29)
				{
					break;
				}
				else if (m == 2 && 0 < d && d <= 28)
				{
					break;
				}
				else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 && 0 < d && d <= 31)
				{
					break;
				}
				else if (m == 4 || m == 6 || m == 9 || m == 11 && 0 < d && d <= 30)
				{
					break;
				}
				else
				{
					cout<<"日不正确，请重新输入"<<endl;
					cin.clear(); 
					cin.ignore(65536, '\n');
				}
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
	
	zeller(y, m, d);
	return 0;
}