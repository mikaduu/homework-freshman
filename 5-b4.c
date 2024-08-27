/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int input[1000];
	int score[101] = {0};
	int i, j, m;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &m);
		if (m < 0)
		{
			break;
		}
		input[i] = m;
	}//m作为中转判断数据是否大于0，
	if (i != 0)
	{
		printf("输入的数组为:\n");
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
		}//i表示输入数据数，如果i是10的整数倍，在循环中已经换行，否则最后一行手动换行
		printf("分数与人数的对应关系为:\n");
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
		printf("无有效输入\n");
	}
	return 0;
}