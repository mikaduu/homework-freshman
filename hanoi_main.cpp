/* 信21 2350233 叶辰 */
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include"hanoi.h"
#include"cmd_console_tools.h"
using namespace std;


/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
int main()
{
	

	 /*demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	
	int x=0,y=0,n=0;
	char choice=0,src=0,tmp=0,dst=0;
	
	
	while (1)
	{	
		cct_setconsoleborder(120, 40, 120, 9000);
		choice = hanoi_menu();
		if (choice == '1'||choice == '2'||choice == '3'||choice=='4')
		{
			cout << endl <<endl;
			hanoi_input(n, src, tmp, dst,choice);
			hanoi(n, src, tmp, dst, choice);
			cout << endl;
			cct_getxy(x, y);
			to_be_continued(x,y);
			cct_cls();
		}
		else if (choice == '5')
		{
			cct_cls();
			hanoi_draw_column();
			to_be_continued();
		}
		else if (choice == '6' || choice == '7')
		{
			cout << endl << endl;
			hanoi_input(n, src, tmp, dst, choice);
			cct_cls();
			cout << "从 " << src << " 移动到 " << dst << " ,共 " << n << " 层";
			hanoi_draw_column();
			hanoi_draw_plate(src, n);
			if (choice == '7')
			{
				Sleep(500);
				if (n % 2 == 0)
				{
					hanoi_plate_move(src, tmp);
				}
				else
				{
					hanoi_plate_move(src, dst);
				}
				
			}
			to_be_continued();
		}
		else if (choice == '8')
		{
			cout << endl << endl;
			hanoi_input(n, src, tmp, dst, choice);
			hanoi(n, src, tmp, dst, choice);
			to_be_continued(0, 38);
		}
		else if (choice == '9')
		{
			cout << endl << endl;
			hanoi_input(n, src, tmp, dst, choice);
			hanoi_game(n, dst, choice);
			to_be_continued(0, 38);
		}
		else if (choice == '0')
		{
			break;
		}

	}
	




	return 0;
}
