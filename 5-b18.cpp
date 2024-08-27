/* 2350233	Ò¶³½	ÐÅ21 */
#include <iostream>
#include<cstring>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
const int MAX_LENGTH = 17;

int input(int requirement[])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cin >> requirement[i];
	}
	if ((cin.good() == 0)||(!(requirement[0] >= 12 && requirement[0] <= 16))||(!(requirement[1] >= 2 && requirement[1] <= requirement[0]))||
		(!(requirement[2] >= 2 && requirement[2] <= requirement[0]))||(!(requirement[3] >= 2 && requirement[3] <= requirement[0]))||(!(requirement[4] >= 2 && requirement[4] <= requirement[0]))
		||(requirement[0] < requirement[1] + requirement[2] + requirement[3] + requirement[4]))
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}
int judge(int requirement[], char key[])
{
	int daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
	int i = 0,j=0;
	for (i = 0; i < MAX_LENGTH; i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
		{
			daxie++;
		}
		else if (key[i] >= 'a' && key[i] <= 'z')
		{
			xiaoxie++;
		}
		else if (key[i] >= '0' && key[i] <= '9')
		{
			shuzi++;
		}
		else
		{
			for (j = 0; j < 15; j++)
			{
				if (key[i] == other[j])
				{
					qita++;
				}
			}
		}
	}
	if (daxie < requirement[1] || xiaoxie < requirement[2] || shuzi < requirement[3] || qita < requirement[4] || ((daxie + xiaoxie + shuzi + qita) != requirement[0]))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int correct = 1,i=0,change;
	char key[10][MAX_LENGTH] = { 0 };
	int requirement[5] = {0};
	getchar();
	cin.ignore(100000000, '\n');
	correct=input(requirement);
	if (correct == 0)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	for (i = 0; i < 10; i++)
	{
		cin >> key[i];
		if (strlen(key[i]) != requirement[0])
		{
			correct = 0;
		}
		if (correct == 0)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
	}
	for (i = 0; i < 10; i++)
	{
		change = judge(requirement, key[i]);
		if (change == 0)
		{
			correct = 0;
		}
	}
	if (correct == 0)
	{
		cout << "´íÎó" << endl;
	}
	else
	{
		cout << "ÕýÈ·" << endl;
	}
	return 0;
}