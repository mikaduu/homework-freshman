/*信21 2350233	叶辰*/
#include <iostream>
#include <limits> // 通过查询，引入limits头文件可用于清除输入缓冲区（以cin.xx的成员函数形式）
using namespace std;

int main()
{
	int x;

	while (1) 
	{	
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		/*if (cin.rdbuf()->in_avail() != 0)
		{
			cin.clear(); // 清除输入缓冲区
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的所有内容
			continue;
		}*/  //此部分用于解决类似78abc这类前面的有效部分在范围内，但有非法输入的情况
		


		if (!cin.good()) // 检查输入是否失败
		{ 
			cin.clear(); // 清除输入缓冲区
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的所有内容
			continue;
		}
		
		if (x >= 0 && x <= 100)
			break;
		/*else
		{
			cin.clear(); // 清除输入缓冲区
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的所有内容
			continue;
		}*/ //此部分为处理类似于123abc这类前面的有效部分超限，后面为非法输入导致的输出两次“请输入x的值[0-100] :”
		
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}



