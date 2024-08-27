/* 2350233	叶辰	信21 */
#include <iostream>
#include <iomanip>
using namespace std;

const int DAY = 1;
int zeller(int y, int m, int d)
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
	w = w + 700;//加一个较大的7的倍数，防止为负，且要使不会超过int的范围
	return w % 7;
}
int leap_year(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 400 == 0)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void calendar(int year,int month[])
{
	int i, a, b, c,complete1,complete2,complete3,h;//三个complete表示一个季度内的月份是否输出完成，当全为0时该季度输出结束；h标售每个季度输出到的行数（1，2时进行特判，输出月份和星期）
	int s1,s2,s3;//s1,s2,s3为数组循环输出中的变量
	for (i = 0; i < 4; i++)
	{
		h = 0;
		complete1 = complete2 = complete3 = 1;
		s1 = s2 = s3 = 1;
		a = zeller(year, 3 * i + 1, DAY);
		b = zeller(year, 3 * i + 2, DAY);
		c = zeller(year, 3 * i + 3, DAY);
		cout << setiosflags(ios::right) << endl;
		while (complete1!=0||complete2!=0||complete3!=0)
		{
			if (h==0)
			{
				cout << setw(13) << 3 * i + 1 << "月" << setw(17) << " " << setw(13) << 3 * i + 2 << "月" << setw(17) << " " << setw(13) << 3 * i + 3 << "月" << setw(17) << " " ;
			}
			else if (h == 1)
			{
				cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" ;
			}
			else
			{
				for (; s1 <= month[3 * i + 0]; s1++)
				{
					if (h == 2&&s1==1)
					{
						cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4 * a) << "";
					}
					if (complete1 == 0)
					{
						cout << setw(32) << "";
						break;
					}
					if (s1 == month[3 * i + 0])
					{
						complete1 = 0;
						cout << setw(4) << s1;
						if ((s1 + a) % 7 == 0)
						{
							cout << setw(4) << "";
						}
						else
						{
							cout << setw(4 * (7 - (s1 + a) % 7) + 4) << "";
						}
						break;
					}
					cout << setw(4) << s1;
					if ((s1 + a) % 7 == 0)
					{
						s1++;
						cout << setw(4) << "";
						break;
					}
				}
				for (; s2 <= month[3 * i + 1]; s2++)
				{
					if (h == 2&&s2==1)
					{
						cout << setw(4 * b) << "";
					}
					if (complete2 == 0)
					{
						cout << setw(32) << "";
						break;
					}
					if (s2 == month[3 * i + 1])
					{
						complete2 = 0;
						cout << setw(4) << s2;
						if ((s2 + b) % 7 == 0)
						{
							cout << setw(4) << "";
						}
						else
						{
							cout << setw(4 * (7 - (s2 + b) % 7) + 4) << "";
						}
						break;
					}
					cout << setw(4) << s2;
					if ((s2 + b) % 7 == 0)
					{
						s2++;
						cout << setw(4) << "";
						break;
					}
				}
				for (; s3 <= month[3 * i + 2]; s3++)
				{
					if (h == 2&&s3==1)
					{
						cout << setw(4 * c) << "";
					}
					if (complete3 == 0)
					{
						cout << setw(32) << "";
						break;
					}
					if (s3 == month[3 * i + 2])
					{
						complete3 = 0;
						cout << setw(4) << s3;
						if ((s3 + c) % 7 == 0)
						{
							cout << setw(4) << "";
						}
						else
						{
							cout << setw(4 * (7 - (s3 + c) % 7) + 4) << "";
						}
						break;
					}
					cout << setw(4) << s3;
					if ((s3 + c) % 7 == 0)
					{
						s3++;
						cout << setw(4) << "";
						break;
					}
				}
			}
			h++;
			cout << endl;
		}
		
	}
	
	return;
}

int main()
{
	int year,leap;
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	cout << year << "年的日历:" << endl;
	leap = leap_year(year);
	month[1] += leap;
	calendar(year,month);
	cout << endl;
	cout << endl;
	return 0;
}