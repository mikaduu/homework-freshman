/* 2350233	Ҷ��	��21 */
// 2352743 ���		2351041 ������		2354089 ���ڽ�		2351276 ����		2350231 �߰���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X1  10    //ɨ�׵�����
#define Y1  26    //ɨ�׵�����

int main()
{
	int i,j,lei=0,x,y,start_x, end_x, start_y, end_y,correct=1,m;
	char saolei[X1][Y1] = { 0 };
	char yanzheng[X1][Y1] = { 0 };
	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			scanf("%c", &saolei[i][j]);
			if (saolei[i][j] == ' '||saolei[i][j]=='\n')
			{
				j--;
			}
		}
	}


	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			if (saolei[i][j] == '*')
			{
				yanzheng[i][j] = '*';
				lei++;
			}
		}
	}

	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			m = 0;
			if (yanzheng[i][j] != '*')
			{
				if (i != 0 && i != X1 - 1)
				{
					start_x = i - 1;
					end_x = i + 1;
				}
				else if (i == 0)
				{
					start_x = i;
					end_x = i + 1;
				}
				else if (i == X1 - 1)
				{
					start_x = i - 1;
					end_x = i;
				}
				if (j != 0 && j != Y1 - 1)
				{
					start_y = j - 1;
					end_y = j + 1;
				}
				else if (j == 0)
				{
					start_y = j;
					end_y = j + 1;
				}
				else if (j == Y1 - 1)
				{
					start_y = j - 1;
					end_y = j;
				}
				for (x = start_x; x <= end_x; x++)
				{
					for (y = start_y; y <= end_y; y++)
					{
						if (yanzheng[x][y] == '*')
						{
							m++;
						}
					}
				}

				yanzheng[i][j] = m;
			}

		}
	}
	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			if (saolei[i][j] != '*')
			{
				if (saolei[i][j] != yanzheng[i][j]+'0')
				{
					correct = 0;
				}
			}
		}
	}





	if (lei != 50)
	{
		printf("����1\n");
	}
	else
	{
		if (correct == 1)
		{
			printf("��ȷ\n");
		}
		else
		{
			printf("����2\n");
		}
	}
}