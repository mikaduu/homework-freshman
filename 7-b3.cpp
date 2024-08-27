/* 2350233	Ҷ��	��21 */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
	int leap_year(int y);
public:
	int calc_days();     //�����ǵ���ĵڼ���
	Days(int y, int m, int d);
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */

};

/* --- �˴��������Ա����������ʵ�� --- */

int Days::leap_year(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 4 == 0) && (y % 400 == 0)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Days::calc_days()
{
	int tianshu=0,i;
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	m[1] += leap_year(year);
	if (day <= m[month - 1])
	{
		for (i = 0; i < month - 1; i++)
		{
			tianshu += m[i];
		}
		tianshu += day;
		return tianshu;
	}
	else
	{
		return -1;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
