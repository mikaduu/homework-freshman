/* 2350233	Ҷ��	��21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define  TOTAL 10
#define XUEHAO 8//����β��
#define XINGMING 9//����β��

int input(char number[], char name[], int i)//����i���ڿ��������ʾ�ı仯
{
	int score;
	i++;
	printf("�������%d���˵�ѧ�š��������ɼ�\n", i);
	scanf("%s %s %d", number, name, &score);
	return score;
}
void paixu_chengjijiangxu(char number[][XUEHAO], char name[][XINGMING], int score[])
{
	int i = 0, j = 0, k = 0;
	int score_middle = 0;
	char middle[10] = { 0 };//�����Ϊ10��ֹ���
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
	}//ð�ݷ�����ʹ��ѡ�񷨲��ܺܺõı�֤�ɼ���ȵ����
	return;
}
void output(char number[][XUEHAO], char name[][XINGMING], int score[])
{
	int i;
	printf("\n");
	printf("ȫ��ѧ��(�ɼ�����):\n");
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