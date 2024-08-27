/* 2350233	Ҷ��	��21 */
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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> requirement[0] >> requirement[1] >> requirement[2] >> requirement[3] >> requirement[4];
	if (cin.good() == 0)
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	else if (!(requirement[0] >= 12 && requirement[0] <= 16))
	{
		cout << "���볤��[" << requirement[0] << "]����ȷ" << endl;
		return 0;
	}
	else if (!(requirement[1] >= 2 && requirement[1] <= requirement[0]))
	{
		cout << "��д��ĸ����[" << requirement[1] << "]����ȷ" << endl;
		return 0;
	}
	else if (!(requirement[2] >= 2 && requirement[2] <= requirement[0]))
	{
		cout << "Сд��ĸ����[" << requirement[2] << "]����ȷ" << endl;
		return 0;
	}
	else if (!(requirement[3] >= 2 && requirement[3] <= requirement[0]))
	{
		cout << "���ָ���[" << requirement[3] << "]����ȷ" << endl;
		return 0;
	}
	else if (!(requirement[4] >= 2 && requirement[4] <= requirement[0]))
	{
		cout << "�������Ÿ���[" << requirement[4] << "]����ȷ" << endl;
		return 0;
	}
	else if (requirement[0] < requirement[1] + requirement[2] + requirement[3] + requirement[4])
	{
		cout << "�����ַ�����֮��[" << requirement[1] << "+" << requirement[2] << "+" << requirement[3] << "+" << requirement[4] << "]���������볤��[" << requirement[0] << "]" << endl;
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
	int i = 0,j=0;//������
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