/* 2350233	Ҷ��	��21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


#define  TOTAL 10
#define XUEHAO 8//����β��
#define XINGMING 9//����β��
int input(char number[], char name[],int i)//����i���ڿ��������ʾ�ı仯
{
	int score;
	i++;
	printf("�������%d���˵�ѧ�š��������ɼ�\n", i);
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
		}//ѡ������ǰ�᣺ѧ�Ų����ظ�
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
	printf("��������(ѧ�Ž���):\n");
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