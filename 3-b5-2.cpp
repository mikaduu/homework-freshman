/* 2350233	叶辰	信21 */
#include <iostream>
using namespace std;

int main()
{
	int year, month, day, location;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 400 == 0)))
	{
		switch (month + 0)
		{
			case 1:
				if ((day <= 31) && (day > 0))
				{
					location = day;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 2:
				if ((day <= 29) && (day > 0))
				{
					location = day + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 3:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 4:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 5:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 6:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 7:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 8:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 9:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 10:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 11:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 12:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
				break;
		}
	}
	else
	{
		switch (month + 0)
		{
			case 1:
				if ((day <= 31) && (day > 0))
				{
					location = day;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 2:
				if ((day <= 28) && (day > 0))
				{
					location = day + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 3:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 4:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 5:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 6:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 7:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 8:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 9:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 10:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 11:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			case 12:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << location << "天" << endl;
				}
				else
				{
					cout << "输入错误-日与月的关系非法" << endl;
				}
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
				break;
		}
	}
	return 0;
}