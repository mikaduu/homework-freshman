/* 2350233	叶辰	信21*/
#include<iostream>
using namespace std;

int main()
{
	int a[21];
	int i,j,m,n;//i为计数器，记录第一次输入的数组中元素个数 //j用于后面输出输入的数组所用的计数器 //m作为判断是否输入结束的中间变量 //n作为插入时重新排序的中间变量
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20 ; i++)
	{
		cin >> m;
		if (m > 0)
		{
			a[i] = m;
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');
	if (i == 0)
	{
		cout << "无有效输入";
	}
	else
	{ 
		cout << "原数组为：" << endl;
		for (j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		cout << "请输入要插入的正整数"<<endl;
		cin >> m;
		for (j = 0; j < i + 1; j++)
		{
			if (m < a[j]&&j<i)
			{
				n = a[j];
				a[j] = m;
				m = n;
			}
			else if (j == i)
			{
				a[j] = m;
			}
		}
		cout << "插入后的数组为：" << endl;
		for (j = 0; j < i+1; j++)
		{
			cout << a[j] << " ";
		}
	}
	cout << endl;
	return 0;
}