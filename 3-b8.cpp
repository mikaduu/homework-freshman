/* 2350233	Ҷ��	��21 */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int j = 1;  //jΪ����������������׳� 
	double x, m, n = 1, total = 1;//m���ڴ洢�����xֵ�����ڼ���ߴ�
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cout << setprecision(10);
	cin >> x;
	m = x;
	while (fabs(x / n) > 1e-6)
	{
		if (j == 1 && (x < -10 || 65 < x))
		{
			cout << "����Ƿ�������������" << endl;
			cout << "������x��ֵ[-10 ~ +65]" << endl;
			cin >> x;
			m = x;
			continue;
		}
		total = total + x / n;
		j++;
		n = n * j;
		x = x * m;
		cout << x << "  " << n <<"     " << x / n << endl;
		getchar();
	}
	cout << "e^" << m << "=" << total << endl;
	return 0;
}
