/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	w = w + 7000;//加一个较大的7的倍数，防止为负，且要使不会超过int的范围
	switch (w % 7)
	{
		case 0:
			printf("星期天\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}
	return 0;
}

int main()
{
	int y, m, d,ret;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n" );
		ret=scanf("%d %d %d",&y,&m,&d);
		if (ret != 3)
		{
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n')// 清除输入缓冲区中的多余内容
				;
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
					printf("日不正确，请重新输入\n");
					while (getchar() != '\n')
						;
				}
			}
			else
			{
				printf("月份不正确，请重新输入\n" );
				while (getchar() != '\n')
					;
			}
		}
		else
		{
			printf("年份不正确，请重新输入\n" );
			while (getchar() != '\n')
				;
		}
	}

	zeller(y, m, d);
	return 0;
}