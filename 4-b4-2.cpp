/* 2350233	叶辰	信21 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu()
{
	char ch;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头不向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头不向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6] ";
	ch= _getche();
	return int(ch);
}

void move_by_ijkl(const HANDLE hout,int a)
{
	int input,x= MAX_X/2+1,y= MAX_Y/2+1;//input表示从键盘读入的数据
	
	while (1)
	{
		input = _getch();
		if (input == 105 || input == 73)//输入i
		{
			y--;
			if (a == 49 && y < 1)
			{
				y = 1;
			}
			else if (a == 50 && y < 1)
			{
				y = 17;
			}
			gotoxy(hout,x,y);
		}
		else if (input == 106 || input == 74)//输入j
		{
			x--;
			if (a == 49 && x < 1)
			{
				x = 1;
			}
			else if (a == 50 && x < 1)
			{
				x = MAX_X;
			}
			gotoxy(hout, x, y);
		}
		else if (input == 107 || input == 75)//输入k
		{
			y++;
			if (a == 49 && y > 17)
			{
				y = 17;
			}
			else if (a == 50 && y > 17)
			{
				y = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input == 108 || input == 76)//输入L
		{
			x++;
			if (a == 49 && x > MAX_X)
			{
				x = MAX_X;
			}
			else if (a == 50 && x > MAX_X)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input == 32)
		{
			cout <<" "<<"\b";
		}
		else if (input == 113 || input == 81)
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			break;
		}
	}
	while (1)
	{
		input = _getch();
		if (input == 13)
		{
			break;
		}
	}
	return;
}

void move_by_arrow(const HANDLE hout, int a)
{
	int input1, input2, x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;//input表示从键盘读入的数据

	while (1)
	{
		input1 = _getch();
		if (input1 == 224 )
		{
			input2 = _getch();
		}
		else if (input1 == 113 || input1 == 81 || input1 == 32)
		{
			;//空语句，使按空格消除和q退出只需按一次就能完成
		}
		else
		{
			continue;
		}
		
		if (input1 == 224 && input2 == 72)//输入上
		{
			y--;
			if (a == 51 && y < 1)
			{
				y = 1;
			}
			else if (a == 52 && y < 1)
			{
				y = 17;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 224 && input2 == 75)//输入左
		{
			x--;
			if (a == 51 && x < 1)
			{
				x = 1;
			}
			else if (a == 52 && x < 1)
			{
				x = MAX_X;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 224 && input2 == 80)//输入下
		{
			y++;
			if (a == 51 && y > 17)
			{
				y = 17;
			}
			else if (a == 52 && y > 17)
			{
				y = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 224 && input2 == 77)//输入右
		{
			x++;
			if (a == 51 && x > 69)
			{
				x = MAX_X;
			}
			else if (a == 52 && x > 69)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 32)
		{
			cout << " " ;
			gotoxy(hout, x, y);
		}
		else if (input1 == 113 || input1 == 81)
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			break;
		}
	}
	while (1)
	{
		input1 = _getch();
		if (input1 == 13)
		{
			break;
		}
	}
	return;
}

void move_by_ijkl_correct(const HANDLE hout, int a)
{
	int input1,input2,x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;//input表示从键盘读入的数据
	
	
	while (1)
	{
		input1 = _getch();
		if (input1 == 224)
		{
			input2 = _getch();//把左键的残余读取完
		}
		
		if (input1 == 105 || input1 == 73)//输入i
		{
			y--;
			if (a == 53 && y < 1)
			{
				y = 1;
			}
			else if (a == 54 && y < 1)
			{
				y = 17;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 106 || input1 == 74)//输入j
		{
			x--;
			if (a == 53 && x < 1)
			{
				x = 1;
			}
			else if (a == 54 && x < 1)
			{
				x = 69;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 107 || input1 == 75)//输入k
		{
			y++;
			if (a == 53 && y > 17)
			{
				y = 17;
			}
			else if (a == 54 && y > 17)
			{
				y = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 108 || input1 == 76)//输入L
		{
			x++;
			if (a == 53 && x > 69)
			{
				x = 69;
			}
			else if (a == 54 && x > 69)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 32)
		{
			cout << " " << "\b";
		}
		else if (input1 == 113 || input1 == 81)
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			break;
		}
	}
	while (1)
	{
		input1 = _getch();
		if (input1 == 13)
		{
			break;
		}
	}
	return;
}





/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int a;//(a存储menu()的返回值)
	while (1)
	{
	/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
		a=menu();
		if (a == 48)//menu()输入值为0
		{
			break;
		}
		else if(a==49)//menu()输入值为1
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout,a);
		}
		else if (a == 50)//menu()输入值为2
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, a);
		}
		else if (a == 51)//menu()输入值为3
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, a);
		}
		else if (a == 52)//menu()输入值为4
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, a);
		}
		else if (a == 53)//menu()输入值为5
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl_correct(hout, a);
		}
		else if (a == 54)//menu()输入值为6
		{
			
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl_correct(hout, a);
		}
		else
		{
			continue;
		}
	}
	
    
	return 0;
}
/*
为什么随机生成的字母数可能不足20个？
因为字母为依次随机输出，可能遇到连续两个字母在同一位置输出，后面一个字母会顶替前一个字母，导致最终出现在屏幕上的字母数不足20个
*/