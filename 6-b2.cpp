/* 2350233	叶辰	信21 */
#include <iostream>
#include<cstring>
using namespace std;

const int N = 80;
void judge_huiwen(int i,char *start)
{
	char* end = start + i-2;
	int correct = 1;
	if (i == 1 || i == 2)//长度为1代表空串（有回车），为2代表有一个字符，这两种情况都必为回文
	{
		;
	}
	else
	{
		for (; *start != 0; start++, end--)
		{
			if (*start != *end)
			{
				correct = 0;
			}
		}
	}
	if (correct == 0)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}

	return;
}

int main()
{
	int length;
	char str[N] = { 0 };
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 80, stdin);
	length = strlen(str);
	str[length - 1] = 0;
	judge_huiwen(length, str);
	return 0;
}