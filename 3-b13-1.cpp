/*��21 2350233	Ҷ��*/
#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	int year, month,day,a,b=1;//a��ʾ�����xx��x��1��Ϊ����a    bΪ��������ѭ���еļ��������жϸ���������죩
	
	while (1)
	{	
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;		
		if (!cin.good()) // ��������Ƿ�ʧ��
		{
			cin.clear(); // ������뻺����
			cin.ignore(100000000, '\n'); // �������뻺�����е���������
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (2000 <= year && year <= 2030 && 1 <= month && month <= 12)
		{
			break;			
		}
		cout << "����Ƿ�������������" << endl;
	}
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
	while (1)
	{
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> a;
		if (!cin.good()) // ��������Ƿ�ʧ��
		{
			cin.clear(); // ������뻺����
			cin.ignore(10000000, '\n'); // �������뻺�����е���������
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (0 <= a && a <= 6)
		{
			break;
		}
		cout << "����Ƿ�������������" << endl;
	}
	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������"<< endl;
	cout << setw(4 * 2 * a) << "";
	while (b <= day)
	{
		cout << setw(4) << b << setw(4) << "";
		if ((b + a) % 7 == 0)
		{
			cout << endl;
		}
		b++;
	}
	cout << endl;
	return 0;

}
