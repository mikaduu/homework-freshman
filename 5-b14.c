/* 2350233	叶辰	信21 */
// 2352743 郭睿		2351041 刘浩田		2354089 王冠杰		2351276 彭煦		2350231 高柏舟
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X1  10    //扫雷的行数
#define Y1  26    //扫雷的列数

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
		printf("错误1\n");
	}
	else
	{
		if (correct == 1)
		{
			printf("正确\n");
		}
		else
		{
			printf("错误2\n");
		}
	}
}