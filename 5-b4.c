/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int input[1000];
	int score[101] = {0};
	int i, j, m;
	printf("������ɼ������1000������������������\n");
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &m);
		if (m < 0)
		{
			break;
		}
		input[i] = m;
	}//m��Ϊ��ת�ж������Ƿ����0��
	if (i != 0)
	{
		printf("���������Ϊ:\n");
		for (j = 0; j < i; j++)
		{
			printf("%d ", input[j]);
			if ((j + 1) % 10 == 0)
			{
				printf("\n");
			}
		}
		if (i % 10 == 0)
		{
			;
		}
		else
		{
			printf("\n");
		}//i��ʾ���������������i��10������������ѭ�����Ѿ����У��������һ���ֶ�����
		printf("�����������Ķ�Ӧ��ϵΪ:\n");
		for (j = 0; j < i; j++)
		{
			for (m = 0; m < 102; m++)
			{
				if (input[j] == m)
				{
					score[m]++;
				}
			}
		}
		for (m = 100; m>= 0; m--)
		{
			if (score[m] != 0)
			{
				printf("%d %d\n", m,score[m]);
			}
		}
	}
	else
	{
		printf("����Ч����\n");
	}
	return 0;
}