/* 2350233	叶辰	信21 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
const int MAX_LENGTH = 17;
const int YINGWENZIFU = 26;
const int SHUZI = 10;
const int QITA = 15;

int input(int requirement[])
{
	int i = 0;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> requirement[0] >> requirement[1] >> requirement[2] >> requirement[3] >> requirement[4];
	if (cin.good() == 0)
	{
		cout << "输入非法" << endl;
		return 0;
	}
	else if (!(requirement[0] >= 12 && requirement[0] <= 16))
	{
		cout << "密码长度[" << requirement[0] << "]不正确" << endl;
		return 0;
	}
	else if (!(requirement[1] >= 2 && requirement[1] <= requirement[0]))
	{
		cout << "大写字母个数[" << requirement[1] << "]不正确" << endl;
		return 0;
	}
	else if (!(requirement[2] >= 2 && requirement[2] <= requirement[0]))
	{
		cout << "小写字母个数[" << requirement[2] << "]不正确" << endl;
		return 0;
	}
	else if (!(requirement[3] >= 2 && requirement[3] <= requirement[0]))
	{
		cout << "数字个数[" << requirement[3] << "]不正确" << endl;
		return 0;
	}
	else if (!(requirement[4] >= 2 && requirement[4] <= requirement[0]))
	{
		cout << "其它符号个数[" << requirement[4] << "]不正确" << endl;
		return 0;
	}
	else if (requirement[0] < requirement[1] + requirement[2] + requirement[3] + requirement[4])
	{
		cout << "所有字符类型之和[" << requirement[1] << "+" << requirement[2] << "+" << requirement[3] << "+" << requirement[4] << "]大于总密码长度[" << requirement[0] << "]" << endl;
		return 0;
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			cout << requirement[i] << " ";
		}
		cout << endl;
		return 1;
	}
}
void key_produce(char key[],int requirement[])
{
	int i = 0, j = 0, m = 0;
	for (i = 0; i < requirement[1]; i++)
	{
		j = rand()%requirement[0];
		if (key[j] == 0)
		{
			key[j] = 'A' + rand() % YINGWENZIFU;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < requirement[2]; i++)
	{
		j = rand() % requirement[0];
		if (key[j] == 0)
		{
			key[j] = 'a' + rand() % YINGWENZIFU;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < requirement[3]; i++)
	{
		j = rand() % requirement[0];
		if (key[j] == 0)
		{
			key[j] = '0' + rand() % SHUZI;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < requirement[4]; i++)
	{
		j = rand() % requirement[0];
		if (key[j] == 0)
		{
			key[j] = other[rand()%QITA];
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < requirement[0]; i++)
	{
		if (key[i] == 0)
		{
			m = rand() % 4 + 1;
			if (m == 1)
			{
				key[i] = 'A' + rand() % YINGWENZIFU;
			}
			else if (m == 2)
			{
				key[i] = 'a' + rand() % YINGWENZIFU;
			}
			else if (m == 3)
			{
				key[i] = '0' + rand() % SHUZI;
			}
			else
			{
				key[i] = other[rand() % QITA];
			}
		}
	}
	return;
}
int main()
{
	int i = 0,j=0;//计数器
	int correct;
	char key[MAX_LENGTH] = {0};
	int requirement[5] = {0};
	srand((unsigned int)(time(0)));
	correct = input(requirement);
	if (correct)
	{
		i = 0;
		while (i < 10)
		{
			for (j = 0; j < MAX_LENGTH; j++)
			{
				key[j] = 0;
			}
			key_produce(key,requirement);
			cout << key << endl;
			i++;
		}
	}
	return 0;
}