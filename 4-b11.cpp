/* 2350233 ��21 Ҷ�� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
void print_letter_left(int i)
{
	if (i == 0)
	{
		return;
	}
	cout << char('A' + i);
	print_letter_left(i - 1);
}
void print_letter_right(int a,int i)
{
	if (a == i)
	{
		return;
	}
	cout << char('A' + a + 1);
	print_letter_right(a+1, i);
}

void print_tower(int length1,int length2,int order)
{
	static int i=0;
	if (order == 1)
	{
		if (i <= length1)
		{
			cout << setw(length1 - i) <<setfill(' ') << "";
			print_letter_left(i);
			cout << 'A';
			print_letter_right(0, i);
			i++;
			cout << endl;
			print_tower(length1,length2,order);
		}
	}
	else if (order == 0)
	{
		if (i <= length2)
		{
			cout << setw(i+length1-length2) << setfill(' ') << "";
			print_letter_left(length2 - i);
			cout << 'A';
			print_letter_right(0, length2 - i);
			i++;
			cout << endl;
			print_tower(length1,length2,order);
		}
	}
	i = 0;
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') 
	{
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setw(2 * (end_ch - 'A') + 1) <<setfill('=') <<""<< endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch - 'A', end_ch - 'A',1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch - 'A', end_ch - 'A', 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl;/* ����ĸ����������= */
	print_tower(end_ch - 'A', end_ch - 'A', 1);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch - 'A', end_ch - 'A' - 1, 0);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
