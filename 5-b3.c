/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


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

int scanf_correct(int a[],int month,int day)
{
	if (month <= 0 || month > 13)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	if (day<0 || day>a[month - 1])
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	return 1;
}

int calc_location(int a[],int month,int day)
{
	int location=0,i;
	for (i = 0; i < month - 1; i++)
	{
		location += a[i];
	}
	location += day;
	return location;
}
int main()
{
	int year, month, day, location=0,leap,correct;
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	leap = leap_year(year);
	a[1] += leap;
	correct=scanf_correct(a,month, day);
	if (correct == 0)
	{
		return 0;
	}
	else
	{
		location = calc_location(a, month, day);
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, location);
	}
	return 0;
}