/*��21 2350233	Ҷ��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */

	int a=100, b=100, c=100,total=1;
	while (a < 1953/3)//ʹaһ����3��������С��
	{
		b = a;
		while (b <=(1953-a)/2)
		{
			c = b;
			while (c < 1000)
			{
				if ((a+b+c==1953) && (a / 100 != 0) && (a / 10 % 10 != 0) && (a % 10 != 0) && (b / 100 != 0) && (b / 10 % 10 != 0) && (b % 10 != 0) && (c / 100 != 0) && (c / 10 % 10 != 0) && (c % 10 != 0) && (a / 100 != a / 10 % 10) && (a / 100 != a % 10) && (a / 100 != b / 100) && (a / 100 != b / 10 % 10) && (a / 100 != b % 10) && (a / 100 != c / 100) && (a / 100 != c / 10 % 10) && (a / 100 != c % 10) && (a / 10 % 10 != a % 10) && (a / 10 % 10 != b / 100) && (a / 10 % 10 != b / 10 % 10) && (a / 10 % 10 != b % 10) && (a / 10 % 10 != c / 100) && (a / 10 % 10 != c / 10 % 10) && (a / 10 % 10 != c % 10) && (a % 10 != b / 100) && (a % 10 != b / 10 % 10) && (a % 10 != b % 10) && (a % 10 != c / 100) && (a % 10 != c / 10 % 10) && (a % 10 != c % 10) && (b / 100 != b / 10 % 10) && (b / 100 != b % 10) && (b / 100 != c / 100) && (b / 100 != c / 10 % 10) && (b / 100 != c % 10) && (b / 10 % 10 != b % 10) && (b / 10 % 10 != c / 100) && (b / 10 % 10 != c / 10 % 10) && (b / 10 % 10 != c % 10) && (c / 100 != c / 10 % 10) && (c / 100 != c % 10) && (c / 10 % 10 != c % 10))
					//�ж�������λ��֮��Ϊ1953������������1-9���ظ����ɵ�
				{
					cout << "No." << setw(3) << total << " : " << a << "+" << b << "+" << c << "=1953" << endl;
					total++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
	total--;
	cout <<"total=" << total << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}
