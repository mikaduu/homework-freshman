/* 2350233	Ҷ��	��21 */
#include <iostream>
//#include<limits>
#include <iomanip>
using namespace std;

int zeller(int y, int m,int d)
{
	int w, c, y1;
	if (m == 1)
	{
		m = 13;
		y = y - 1;
	}
	else if (m == 2)
	{
		m = 14;
		y = y - 1;
	}
	y1 = y % 100;
	c = y / 100;
	w = y1 + y1 / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	w = w + 7000;//��һ���ϴ��7�ı�������ֹΪ������Ҫʹ���ᳬ��int�ķ�Χ
	/*switch (w % 7)
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}*/
	return w%7;
}

void calender(int year, int month)
{
	/* ������Ӵ��� */
	int a,b,day;
	a = zeller(year, month, 1);
	b = 1;
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 400 == 0)))
	{
		if (month == 2)
		{
			day = 29;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	else
	{
		if (month == 2)
		{
			day = 28;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			day = 31;
		}
		else
		{
			day = 30;
		}
	}
	
	/* ͷ���ָ��ߣ������� */
	cout << endl;
	cout << year << "��" << month << "��" << endl;
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	/* ������Ӵ��� */
	cout << setw(4 * 2 * a) << "";
	while (b <= day)
	{
		cout << setw(4) << b << setw(4) << "";
		if ((b + a) % 7 == 0)
		{
			if (b+1>day)
			{
				;
			}
			else
			{
				cout << endl;
			}
		}
		b++;
	}
	cout << endl;

	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}

int main()
{
	int y, m;
	while (1)
	{
		cout << "��������[1900-2100]����" << endl;
		cin >> y >> m ;
		if (!cin.good()) // ��������Ƿ�ʧ��
		{
			cin.clear(); // ������뻺����
			cin.ignore(65536, '\n'); // �������뻺�����е���������
			cout << "�����������������" << endl;
			continue;
		}
		if (1900 <= y && y <= 2100)
		{
			if (1 <= m && m <= 12)
			{
				break;
			}
			else
			{
				cout << "�·ݲ���ȷ������������" << endl;
				cin.clear(); 
				cin.ignore(65536, '\n');
			}
		}
		else
		{
			cout << "��ݲ���ȷ������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}

	
	calender(y, m);
	return 0;
}