/* 2350233 信21 叶辰 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void print_letter_left(int i)
{
	if (i == 0)
	{
		return;
	}
	cout << char('A' + i);
	print_letter_left(i - 1);
}
void print_letter_right(int a,int i)
{
	if (a == i)
	{
		return;
	}
	cout << char('A' + a + 1);
	print_letter_right(a+1, i);
}

void print_tower(int length1,int length2,int order)
{
	static int i=0;
	if (order == 1)
	{
		if (i <= length1)
		{
			cout << setw(length1 - i) <<setfill(' ') << "";
			print_letter_left(i);
			cout << 'A';
			print_letter_right(0, i);
			i++;
			cout << endl;
			print_tower(length1,length2,order);
		}
	}
	else if (order == 0)
	{
		if (i <= length2)
		{
			cout << setw(i+length1-length2) << setfill(' ') << "";
			print_letter_left(length2 - i);
			cout << 'A';
			print_letter_right(0, length2 - i);
			i++;
			cout << endl;
			print_tower(length1,length2,order);
		}
	}
	i = 0;
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') 
	{
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setw(2 * (end_ch - 'A') + 1) <<setfill('=') <<""<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch - 'A', end_ch - 'A',1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch - 'A', end_ch - 'A', 0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A') + 1) << setfill('=') << "" << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch - 'A', end_ch - 'A', 1);   //打印 A~结束字符的正三角 
	print_tower(end_ch - 'A', end_ch - 'A' - 1, 0);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
