/* 2350233	Ҷ��	��21*/
#include<iostream>
using namespace std;

int main()
{
	int a[21];
	int i,j,m,n;//iΪ����������¼��һ�������������Ԫ�ظ��� //j���ں������������������õļ����� //m��Ϊ�ж��Ƿ�����������м���� //n��Ϊ����ʱ����������м����
	cout << "��������������������������20������0������������" << endl;
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
		cout << "����Ч����";
	}
	else
	{ 
		cout << "ԭ����Ϊ��" << endl;
		for (j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		cout << "������Ҫ�����������"<<endl;
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
		cout << "����������Ϊ��" << endl;
		for (j = 0; j < i+1; j++)
		{
			cout << a[j] << " ";
		}
	}
	cout << endl;
	return 0;
}