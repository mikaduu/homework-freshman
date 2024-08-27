/* 2350233	叶辰	信21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define  TOTAL 10
#define XUEHAO 8//包括尾零
#define XINGMING 9//包括尾零

int input(char number[], char name[], int i)//传入i用于控制输出提示的变化
{
	int score;
	i++;
	printf("请输入第%d个人的学号、姓名、成绩\n", i);
	scanf("%s %s %d", number, name, &score);
	return score;
}
void paixu_chengjijiangxu(char number[][XUEHAO], char name[][XINGMING], int score[])
{
	int i = 0, j = 0, k = 0;
	int score_middle = 0;
	char middle[10] = { 0 };//定宽度为10防止溢出
	for (i = 0; i < TOTAL - 1; i++)
	{
		for (j = 0; j < TOTAL - i - 1; j++)
		{
			if (score[j] < score[j + 1])
			{
				score_middle = score[j];
				score[j] = score[j + 1];
				score[j + 1] = score_middle;
				strcpy(middle, number[j]);
				strcpy(number[j], number[j+1]);
				strcpy(number[j+1], middle);
				strcpy(middle, name[j]);
				strcpy(name[j], name[j+1]);
				strcpy(name[j+1], middle);
			}
		}
	}//冒泡法排序，使用选择法不能很好的保证成绩相等的情况
	return;
}
void output(char number[][XUEHAO], char name[][XINGMING], int score[])
{
	int i;
	printf("\n");
	printf("全部学生(成绩降序):\n");
	for (i = 0; i < TOTAL; i++)
	{
		printf("%s %s %d\n", name[i], number[i], score[i]);
	}
	return;
}
int main()
{
	char name[TOTAL][XINGMING] = { 0 };
	char number[TOTAL][XUEHAO] = { 0 };
	int score[TOTAL] = { 0 };
	int i = 0;
	for (i = 0; i < TOTAL; i++)
	{
		score[i] = input(number[i], name[i], i);
	}
	paixu_chengjijiangxu(number, name, score);
	output(number, name, score);
	return 0;
}