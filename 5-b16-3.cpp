/* 2350233	叶辰	信21 */
#include <iostream>
#include <string>
using namespace std;

const int TOTAL = 10;

int input(string number[], string name[], int i)
{
	int score = 0;
	cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
	cin >> number[i] >> name[i] >> score;
	return score;
}
void paixu_xuehaoshengxu(string number[], string name[], int score[])
{
	string middle;
	int i = 0, j = 0,k=0;
	int score_middle = 0;
	for (i = 0; i < TOTAL - 1; i++)
	{
		k = i;
		for (j = i; j < TOTAL; j++)
		{
			if (number[k]>number[j])
			{
				k = j;
			}
		}//选择法排序，前提：学号不会重复
		score_middle = score[i];
		score[i] = score[k];
		score[k] = score_middle;
		middle = number[k];
		number[k] = number[i];
		number[i] = middle;
		middle = name[k];
		name[k] = name[i];
		name[i] = middle;
	}
	//冒泡法排序，使用选择法不能很好的保证成绩相等的情况
}
void output(string number[], string name[], int score[])
{
	int i = 0;
	cout << endl;
	cout << "全部学生(学号升序):" << endl;
	for (i = 0; i < TOTAL; i++)
	{
		cout << name[i] << " " << number[i] << " " << score[i] << endl;
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
	paixu_xuehaoshengxu(number, name, score);
	output(number, name, score);
	return 0;
}