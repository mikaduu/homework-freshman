/* 2350233	Ҷ��	��21 */
#include <iostream>
#include<cstring>
using namespace std;

const int N = 80;
void judge_huiwen(int i,char *start)
{
	char* end = start + i-2;
	int correct = 1;
	if (i == 1 || i == 2)//����Ϊ1����մ����лس�����Ϊ2������һ���ַ����������������Ϊ����
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
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 80, stdin);
	length = strlen(str);
	str[length - 1] = 0;
	judge_huiwen(length, str);
	return 0;
}