/* 2350233	Ҷ��	��21*/
#include<iostream>
using namespace std;

int main()
{
	int input[1000];
	int score[101] = { 0 };
	int i, j, k, m,n;
	cout<<"������ɼ������1000������������������"<<endl;
	for (i = 0; i < 1000; i++)
	{
		cin>>m;
		if (m < 0)
		{
			break;
		}
		input[i] = m;
	}//m��Ϊ��ת�ж������Ƿ����0��
	if (i != 0)
	{
		cout<<"���������Ϊ:"<<endl;
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
		}//i��ʾ�����������������i��10������������ѭ�����Ѿ����У��������һ���ֶ�����
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
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
		}//ð�ݷ��Ӵ�С����*/
		for (j = 0; j < i; j++)
		{
			for (m = 0; m < 102; m++)
			{
				if (input[j] == m)
				{
					score[m]++;
				}
			}
		}//����ÿ�����ݶ��ж��ٸ�
		
		for (j = 100; j>=0; j--)
		{
			m = 1;//m������1�����ڼ������������
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
		cout << "����Ч����" << endl;;
	}
	return 0;
}