/* 2350233	叶辰	信21*/
#include<iostream>
using namespace std;

int main()
{
	int input[1000];
	int score[101] = { 0 };
	int i, j, k, m,n;
	cout<<"请输入成绩（最多1000个），负数结束输入"<<endl;
	for (i = 0; i < 1000; i++)
	{
		cin>>m;
		if (m < 0)
		{
			break;
		}
		input[i] = m;
	}//m作为中转判断数据是否大于0，
	if (i != 0)
	{
		cout<<"输入的数组为:"<<endl;
		for (j = 0; j < i; j++)
		{
			cout<<input[j]<<" ";
			if ((j + 1) % 10 == 0)
			{
				cout<<endl;
			}
		}
		if (i % 10 == 0)
		{
			;
		}
		else
		{
			cout << endl;
		}//i表示输入数据数量，如果i是10的整数倍，在循环中已经换行，否则最后一行手动换行
		cout << "分数与名次的对应关系为:" << endl;
		/*for (j = 0; j < i; j++)
		{
			for (k = j + 1; k < i; k++)
			{
				if (input[j] < input[k])
				{
					m = input[j];
					input[j] = input[k];
					input[k] = m;
				}
			}
		}//冒泡法从大到小排序*/
		for (j = 0; j < i; j++)
		{
			for (m = 0; m < 102; m++)
			{
				if (input[j] == m)
				{
					score[m]++;
				}
			}
		}//计算每个数据都有多少个
		
		for (j = 100; j>=0; j--)
		{
			m = 1;//m重新置1，用于计算分数的排名
			for (k = j+1; k < 101; k++)
			{
				m += score[k];
			}
			for (n=score[j];  n> 0; n--)
			{
					cout << j << " " << m << endl;
				
			}
		}
	}
	else
	{
		cout << "无有效输入" << endl;;
	}
	return 0;
}