/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret,year,month,day,a,b=1,m;//a��ʾ�����xx��x��1��Ϊ����a    m���ڴ���1��ǰ�Ŀո�
	while (1)
	{
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret != 2)
		{
			printf("����Ƿ�������������\n");
			while (getchar() != '\n')// ������뻺�����еĶ�������
				;
			continue;
		}
		if (2000 <= year && year <= 2030 && 1 <= month && month <= 12)
		{
			break;
		}
		printf("����Ƿ�������������\n");

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
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ",year,month);
		ret=scanf("%d", &a);
		if (!ret) // ��������Ƿ�ʧ��
		{
			printf("����Ƿ�������������\n");
			while (getchar() != '\n')// ������뻺�����еĶ�������
				;
			continue;
		}
		if (0 <= a && a <= 6)
		{
			break;
		}
		printf("����Ƿ�������������\n");
	}
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n",year,month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
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