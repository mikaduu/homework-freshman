/*2350233	Ҷ��	��21*/
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
	w = w + 7000;//��һ���ϴ��7�ı�������ֹΪ������Ҫʹ���ᳬ��int�ķ�Χ
	switch (w % 7)
	{
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
	}
	return 0;
}

int main()
{
	int y, m, d,ret;
	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n" );
		ret=scanf("%d %d %d",&y,&m,&d);
		if (ret != 3)
		{
			printf("����Ƿ�������������\n");
			while (getchar() != '\n')// ������뻺�����еĶ�������
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
					printf("�ղ���ȷ������������\n");
					while (getchar() != '\n')
						;
				}
			}
			else
			{
				printf("�·ݲ���ȷ������������\n" );
				while (getchar() != '\n')
					;
			}
		}
		else
		{
			printf("��ݲ���ȷ������������\n" );
			while (getchar() != '\n')
				;
		}
	}

	zeller(y, m, d);
	return 0;
}