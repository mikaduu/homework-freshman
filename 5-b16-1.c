/* 2350233	叶辰	信21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


#define  TOTAL 10
#define XUEHAO 8//包括尾零
#define XINGMING 9//包括尾零
int input(char number[], char name[],int i)//传入i用于控制输出提示的变化
{
	int score;
	i++;
	printf("请输入第%d个人的学号、姓名、成绩\n", i);
	scanf("%s %s %d", number, name, &score);
	return score;
}
void paixu_xuehaojiangxu(char number[][XUEHAO], char name[][XINGMING], int score[])
{
	int i = 0, j = 0, k = 0;
	int score_middle=0;
	char middle[10] = { 0 };
	for (i = 0; i < TOTAL - 1; i++)
	{
		k = i;
		for (j = i; j < TOTAL; j++)
		{
			if (strcmp(number[k], number[j]) < 0)
			{
				k = j;
			}
		}//选择法排序，前提：学号不会重复
		score_middle = score[i];
		score[i] = score[k];
		score[k] = score_middle;
		strcpy(middle, number[k]);
		strcpy(number[k], number[i]);
		strcpy(number[i], middle);
		strcpy(middle, name[k]);
		strcpy(name[k], name[i]);
		strcpy(name[i], middle);
	}
	return;
}
void output(char number[][XUEHAO],char name[][XINGMING],int score[])
{
	int i;
	printf("\n");
	printf("及格名单(学号降序):\n");
	for (i = 0; i < TOTAL; i++)
	{
		if (score[i] >= 60)
		{
			printf("%s %s %d\n", name[i], number[i], score[i]);
		}
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
		score[i]=input(number[i],name[i],i);
	}
	paixu_xuehaojiangxu(number,name,score);
	output(number, name, score);
	return 0;
}