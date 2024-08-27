/*信21 2350233	叶辰*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a = 100, b = 100, c = 100, total = 1;
	while (a < 1953 / 3)//使a一定是3个数中最小的
	{
		b = a;
		while (b <= (1953 - a) / 2)
		{
			c = b;
			while (c < 1000)
			{
				if ((a + b + c == 1953) && (a / 100 != 0) && (a / 10 % 10 != 0) && (a % 10 != 0) && (b / 100 != 0) && (b / 10 % 10 != 0) && (b % 10 != 0) && (c / 100 != 0) && (c / 10 % 10 != 0) && (c % 10 != 0) && (a / 100 != a / 10 % 10) && (a / 100 != a % 10) && (a / 100 != b / 100) && (a / 100 != b / 10 % 10) && (a / 100 != b % 10) && (a / 100 != c / 100) && (a / 100 != c / 10 % 10) && (a / 100 != c % 10) && (a / 10 % 10 != a % 10) && (a / 10 % 10 != b / 100) && (a / 10 % 10 != b / 10 % 10) && (a / 10 % 10 != b % 10) && (a / 10 % 10 != c / 100) && (a / 10 % 10 != c / 10 % 10) && (a / 10 % 10 != c % 10) && (a % 10 != b / 100) && (a % 10 != b / 10 % 10) && (a % 10 != b % 10) && (a % 10 != c / 100) && (a % 10 != c / 10 % 10) && (a % 10 != c % 10) && (b / 100 != b / 10 % 10) && (b / 100 != b % 10) && (b / 100 != c / 100) && (b / 100 != c / 10 % 10) && (b / 100 != c % 10) && (b / 10 % 10 != b % 10) && (b / 10 % 10 != c / 100) && (b / 10 % 10 != c / 10 % 10) && (b / 10 % 10 != c % 10) && (c / 100 != c / 10 % 10) && (c / 100 != c % 10) && (c / 10 % 10 != c % 10))
					//判断三个三位数之和为1953，且他们是由1-9不重复构成的
				{
					printf("No.%3d : %d+%d+%d=1953\n",total,a,b,c);
					total++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
	total--;
	printf("total=%d\n",total);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
