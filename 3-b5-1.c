/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, day, location;
	printf("�������꣬�£���\n");
	scanf("%d %d %d",&year,&month,&day);
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 400 == 0)))
	{
		switch (month + 0)
		{
			case 1:
				if ((day <= 31) && (day > 0))
				{
					location = day;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 2:
				if ((day <= 29) && (day > 0))
				{
					location = day + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 3:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 4:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 5:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 6:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 7:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 8:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 9:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 10:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 11:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 12:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			default:
				printf("�������-�·ݲ���ȷ\n");
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
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 2:
				if ((day <= 28) && (day > 0))
				{
					location = day + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);;
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 3:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 4:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 5:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 6:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 7:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 8:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 9:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 10:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 11:
				if ((day <= 30) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			case 12:
				if ((day <= 31) && (day > 0))
				{
					location = day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, location);
				}
				else
				{
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				}
				break;
			default:
				printf("�������-�·ݲ���ȷ\n");
				break;
		}
	}
	return 0;
}