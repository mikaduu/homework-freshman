/* 2350233	叶辰	信21 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
	int leap_year(int y);
public:
	int calc_days();     //计算是当年的第几天
	Days(int y, int m, int d);
	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */

};

/* --- 此处给出类成员函数的体外实现 --- */

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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
