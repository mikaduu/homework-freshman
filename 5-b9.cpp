/* 2350233 叶辰 信21 */
#include <iostream>
#include <iomanip>
using namespace std;

const int ROW = 9;
const int COLUMN = 9;

void input_shudu(int input[],int i)
{
	int j=0,m;//j为计数器，m为中间变量，防止错误输入进行数组
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	while (j<COLUMN)
	{	
		cin >> m;
		if (cin.good()==0)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值"<<endl;
			continue;
		}
		if (m >= 1 && m < 10)
		{
			input[j] = m;
		}
		else
		{
			cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
			continue;
		}
		j++;
	}
	return;
}
int shudu_correct_row(int shudu[])
{
	int i, j,correct=1;
	for (i = 0; i < COLUMN - 1; i++)
	{
		for (j = i + 1; j < COLUMN; j++)
		{
			if (shudu[i] == shudu[j])
			{
				correct = 0;
			}
		}
	}
	if (correct == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i, j, k,m;
	int correct_row = 1, correct_line = 1, correct_group = 1;
	int group[ROW][COLUMN] = { 0 };
	int shudu[ROW][COLUMN] = { 0 };
	for (i = 0; i < ROW; i++)
	{
		input_shudu(shudu[i],i);
	}
	for (i = 0; i < ROW; i++)
	{
		correct_row = shudu_correct_row(shudu[i]);
		if (correct_row == 0)
		{
			break;
		}
	}
	for (i = 0; i < COLUMN; i++)
	{
		for (j = 0; j < ROW - 1; j++)
		{
			for (k = j + 1; k < ROW; k++)
			{
				if (shudu[j][i] == shudu[k][i])
				{
					correct_line = 0;
				}
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (m = 0; m < 3; m++)
			{
				for (k = 0; k < 3; k++)
				{
					group[3*i + j][3*m+k] = shudu[3*i+m][3*j+k];
				}

			}
			
		}
	}
	
	for (i = 0; i < ROW; i++)
	{
		correct_group = shudu_correct_row(group[i]);
		if (correct_group == 0)
		{
			break;
		}
	}
	if (correct_row == 1 && correct_line == 1 && correct_group == 1)
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}
}