/*��21 2350233	Ҷ��*/
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int a = 100, b = 100, c = 100, total = 1;
	while (a < 1953 / 3)//ʹaһ����3��������С��
	{
		b = a;
		while (b <= (1953 - a) / 2)
		{
			c = b;
			while (c < 1000)
			{
				if ((a + b + c == 1953) && (a / 100 != 0) && (a / 10 % 10 != 0) && (a % 10 != 0) && (b / 100 != 0) && (b / 10 % 10 != 0) && (b % 10 != 0) && (c / 100 != 0) && (c / 10 % 10 != 0) && (c % 10 != 0) && (a / 100 != a / 10 % 10) && (a / 100 != a % 10) && (a / 100 != b / 100) && (a / 100 != b / 10 % 10) && (a / 100 != b % 10) && (a / 100 != c / 100) && (a / 100 != c / 10 % 10) && (a / 100 != c % 10) && (a / 10 % 10 != a % 10) && (a / 10 % 10 != b / 100) && (a / 10 % 10 != b / 10 % 10) && (a / 10 % 10 != b % 10) && (a / 10 % 10 != c / 100) && (a / 10 % 10 != c / 10 % 10) && (a / 10 % 10 != c % 10) && (a % 10 != b / 100) && (a % 10 != b / 10 % 10) && (a % 10 != b % 10) && (a % 10 != c / 100) && (a % 10 != c / 10 % 10) && (a % 10 != c % 10) && (b / 100 != b / 10 % 10) && (b / 100 != b % 10) && (b / 100 != c / 100) && (b / 100 != c / 10 % 10) && (b / 100 != c % 10) && (b / 10 % 10 != b % 10) && (b / 10 % 10 != c / 100) && (b / 10 % 10 != c / 10 % 10) && (b / 10 % 10 != c % 10) && (c / 100 != c / 10 % 10) && (c / 100 != c % 10) && (c / 10 % 10 != c % 10))
					//�ж�������λ��֮��Ϊ1953������������1-9���ظ����ɵ�
				{
					printf("No.%3d : %d+%d+%d=1953\n",total,a,b,c);
					total++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
	total--;
	printf("total=%d\n",total);

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
