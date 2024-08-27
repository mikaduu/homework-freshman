/*信21 2350233	叶辰*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */

	int a=100, b=100, c=100,total=1;
	while (a < 1953/3)//使a一定是3个数中最小的
	{
		b = a;
		while (b <=(1953-a)/2)
		{
			c = b;
			while (c < 1000)
			{
				if ((a+b+c==1953) && (a / 100 != 0) && (a / 10 % 10 != 0) && (a % 10 != 0) && (b / 100 != 0) && (b / 10 % 10 != 0) && (b % 10 != 0) && (c / 100 != 0) && (c / 10 % 10 != 0) && (c % 10 != 0) && (a / 100 != a / 10 % 10) && (a / 100 != a % 10) && (a / 100 != b / 100) && (a / 100 != b / 10 % 10) && (a / 100 != b % 10) && (a / 100 != c / 100) && (a / 100 != c / 10 % 10) && (a / 100 != c % 10) && (a / 10 % 10 != a % 10) && (a / 10 % 10 != b / 100) && (a / 10 % 10 != b / 10 % 10) && (a / 10 % 10 != b % 10) && (a / 10 % 10 != c / 100) && (a / 10 % 10 != c / 10 % 10) && (a / 10 % 10 != c % 10) && (a % 10 != b / 100) && (a % 10 != b / 10 % 10) && (a % 10 != b % 10) && (a % 10 != c / 100) && (a % 10 != c / 10 % 10) && (a % 10 != c % 10) && (b / 100 != b / 10 % 10) && (b / 100 != b % 10) && (b / 100 != c / 100) && (b / 100 != c / 10 % 10) && (b / 100 != c % 10) && (b / 10 % 10 != b % 10) && (b / 10 % 10 != c / 100) && (b / 10 % 10 != c / 10 % 10) && (b / 10 % 10 != c % 10) && (c / 100 != c / 10 % 10) && (c / 100 != c % 10) && (c / 10 % 10 != c % 10))
					//判断三个三位数之和为1953，且他们是由1-9不重复构成的
				{
					cout << "No." << setw(3) << total << " : " << a << "+" << b << "+" << c << "=1953" << endl;
					total++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
	total--;
	cout <<"total=" << total << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
