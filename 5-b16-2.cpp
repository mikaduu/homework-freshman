/* 2350233	叶辰	信21 */
#include <iostream>
#include <string>
using namespace std;

const int TOTAL = 10;

int input(string number[], string name[], int i)
{
	int score=0;
	cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
	cin >> number[i] >> name[i] >> score;
	return score;
}
void paixu_chengjishengxu(string number[], string name[], int score[])
{
	string middle;
	int i = 0, j = 0;
	int score_middle = 0;
	for (i = 0; i < TOTAL-1; i++)
	{
		for (j = 0; j < TOTAL-i-1; j++)
		{
			if (score[j] > score[j+1])
			{
				score_middle = score[j];
				score[j] = score[j+1];
				score[j+1] = score_middle;
				middle = number[j];
				number[j] = number[j+1];
				number[j+1] = middle;
				middle = name[j];
				name[j] = name[j+1];
				name[j+1] = middle;
			}
		}
	}//冒泡法排序，使用选择法不能很好的保证成绩相等的情况
}
void output(string number[], string name[], int score[])
{
	int i=0;
	cout << endl;
	cout << "不及格名单(成绩升序):" << endl;
	for (i = 0; i < TOTAL; i++)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << number[i] << " " << score[i] << endl;
		}
	}
}
int main()
{
	string name[TOTAL];
	string number[TOTAL];
	int score[TOTAL] = { 0 };
	int i = 0;
	for (i = 0; i < TOTAL; i++)
	{
		score[i] = input(number, name, i);
	}
	paixu_chengjishengxu(number, name, score);
	output(number, name, score);
	return 0;
}