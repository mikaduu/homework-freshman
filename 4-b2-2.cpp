/* 2350233	Ҷ��	��21 */
#include <iostream>
//#include<limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int w,c,y1;
	
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
	switch (w%7)
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
	}
	return 0;
}

int main()
{
	int y, m, d;
	while (1) 
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
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
				if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 4 == 0) && (y % 400 == 0)) && m == 2 && 0 < d && d <= 29)
				{
					break;
				}
				else if (m == 2 && 0 < d && d <= 28)
				{
					break;
				}
				else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 && 0 < d && d <= 31)
				{
					break;
				}
				else if (m == 4 || m == 6 || m == 9 || m == 11 && 0 < d && d <= 30)
				{
					break;
				}
				else
				{
					cout<<"�ղ���ȷ������������"<<endl;
					cin.clear(); 
					cin.ignore(65536, '\n');
				}
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
	
	zeller(y, m, d);
	return 0;
}