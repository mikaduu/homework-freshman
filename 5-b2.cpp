/* 2350233	Ò¶³½	ÐÅ21*/
#include<iostream>
using namespace std;

int main()
{
	int a[100] = { 0 };
	int i, j,b=0;
	for (i = 1; i < 101; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if ((j + 1) % i == 0)
			{
				a[j]++;
			}
		}
	}
	for (j = 0; j < 100; j++)
	{
		if (a[j] % 2 != 0)
		{
			b++;
			if (b != 1)
			{
				cout << ' ';
			}
			cout << (j + 1) ;
		}
	}
	cout << endl;
	return 0;
}