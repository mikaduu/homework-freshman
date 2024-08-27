/*信21 2350233	叶辰*/
#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	int year, month,day,a,b=1;//a表示输入的xx年x月1日为星期a    b为后面月历循环中的计数器（判断该输出多少天）
	
	while (1)
	{	
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;		
		if (!cin.good()) // 检查输入是否失败
		{
			cin.clear(); // 清除输入缓冲区
			cin.ignore(100000000, '\n'); // 忽略输入缓冲区中的所有内容
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (2000 <= year && year <= 2030 && 1 <= month && month <= 12)
		{
			break;			
		}
		cout << "输入非法，请重新输入" << endl;
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
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> a;
		if (!cin.good()) // 检查输入是否失败
		{
			cin.clear(); // 清除输入缓冲区
			cin.ignore(10000000, '\n'); // 忽略输入缓冲区中的所有内容
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (0 <= a && a <= 6)
		{
			break;
		}
		cout << "输入非法，请重新输入" << endl;
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六"<< endl;
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
