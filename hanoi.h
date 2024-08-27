/* 信21 2350233 叶辰 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

const int X1 = 0;//输出第几步的位置
const int Y1 = 17;//输出第几步的位置
const int X2 = 9;//输出汉诺塔的底座位置
const int Y2 = 12;//输出汉诺塔的底座位置
const int X3 = 12;
const int X4 = 44;
const int X5 = 76;//三根柱子的中心
const int Y3 = 15;//图形化柱子的底座



int hanoi_menu();
void hanoi_input(int& n, char& src, char& tmp, char& dst,char choice);
void hanoi(int n, char src, char tmp, char dst, char choice);
void to_be_continued(int X=0,int Y=22);
void hanoi_draw_column();
void hanoi_draw_plate(char src, int n);
void hanoi_plate_move(char src, char dst);
void hanoi_game(int n, char dst, char choice);