/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret,year,month,day,a,b=1,m;//a表示输入的xx年x月1日为星期a    m用于处理1号前的空格
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret != 2)
		{
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n')// 清除输入缓冲区中的多余内容
				;
			continue;
		}
		if (2000 <= year && year <= 2030 && 1 <= month && month <= 12)
		{
			break;
		}
		printf("输入非法，请重新输入\n");

	}
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
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		ret=scanf("%d", &a);
		if (!ret) // 检查输入是否失败
		{
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n')// 清除输入缓冲区中的多余内容
				;
			continue;
		}
		if (0 <= a && a <= 6)
		{
			break;
		}
		printf("输入非法，请重新输入\n");
	}
	printf("\n");
	printf("%d年%d月的月历为:\n",year,month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	m = 4 * 2 * a;
	while (m)
	{
		printf(" ");
		m--;
	}
	while (b <= day)
	{
		printf("%4d",b);
		printf("    ");
		if ((b + a) % 7 == 0)
		{
			printf("\n");
		}
		b++;
	}
	printf("\n");
	return 0;


}