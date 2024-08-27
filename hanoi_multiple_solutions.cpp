/* 信21 2350233 叶辰 */

#include <iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
static int i=0,speed=5;
static int column[3][10] = { {0},{0},{0} };//0,1,2分别对应A,B,C柱
static int top[3] = { 0 };


   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
   /***************************************************************************
     函数名称：
     功    能：显示提示信息
     输入参数：
     返 回 值：
     说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
   ***************************************************************************/
 void to_be_continued(int X,int Y)
{
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(X, Y);
    cout << "按回车键继续...";

    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}
 void hanoi_output_hengxiangshuzu()//函数内不带gotoxy，需要在函数外指定
 {
     int j;
     cout << "A:";
     for (j = 0; j < 10; j++)
     {
         if (column[0][j] != 0)
         {
             cout << setw(2) << column[0][j];
         }
         else
         {
             break;
         }
     }
     cout << setw(21 - 2 * j) << " ";
     cout << "B:";
     for (j = 0; j < 10; j++)
     {
         if (column[1][j] != 0)
         {
             cout << setw(2) << column[1][j];
         }
         else
         {
             break;
         }
     }
     cout << setw(21 - 2 * j) << " ";
     cout << "C:";
     for (j = 0; j < 10; j++)
     {
         if (column[2][j] != 0)
         {
             cout << setw(2) << column[2][j];
         }
         else
         {
             break;
         }
     }
     cout << setw(21 - 2 * j) << " ";
     cout << endl;
 }
 void hanoi_output_zongxiangshuzu(char choice)//函数带gotoxy，在使用时要记得修改函数
 {
     int j,x=0,y=0;
     if (choice == '4')
     {
         x = X2;
         y = Y2;
     }
     else if (choice == '8'||choice=='9')
     {
         x = X2;
         y = Y2 + 15;
     }
     cct_gotoxy(x, y);
     cout << "=========================";
     cct_gotoxy(x, y + 1);
     cout << "  A         B         C";
     for (j = 0; j < 10; j++)
     {
         if (column[0][j] != 0)
         {
             cct_gotoxy(x + 2, y - 1 - j);
             cout << column[0][j];
         }
         else
         {
             cct_gotoxy(x + 2, y - 1 - j);
             cout << " ";
         }
     }
     for (j = 0; j < 10; j++)
     {
         if (column[1][j] != 0)
         {
             cct_gotoxy(x + 12, y - 1 - j);
             cout << column[1][j];
         }
         else
         {
             cct_gotoxy(x + 12, y - 1 - j);
             cout << " ";
         }
     }
     for (j = 0; j < 10; j++)
     {
         if (column[2][j] != 0)
         {
             cct_gotoxy(x + 22, y - 1 - j);
             cout << column[2][j];
         }
         else
         {
             cct_gotoxy(x + 22, y - 1 - j);
             cout << " ";
         }
     }
 }
void hanoi_input(int& n,char& src,char& tmp,char& dst,char choice)
{
    int j,k;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        if (1 <= n && n <= 10)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (src == 'a' || src == 'A')
        {
            src = 'A';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else if (src == 'b' || src == 'B')
        {
            src = 'B';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else if (src == 'c' || src == 'C')
        {
            src = 'C';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (dst == 'a' || dst == 'A')
        {
            dst = 'A';
        }
        else if (dst == 'b' || dst == 'B')
        {
            dst = 'B';
        }
        else if (dst == 'c' || dst == 'C')
        {
            dst = 'C';
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        if (dst == src)
        {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        else
        {
            break;
        }
    }
    tmp = 65 + 66 + 67 - dst - src;
    i = 0; 
    speed = 5;
    if (choice == '4'||choice=='8')
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> speed;
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(10000000, '\n');
                continue;
            }
            if (0 <= speed && speed <= 5)
            {
                cin.clear();
                cin.ignore(10000000, '\n');
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(10000000, '\n');
                continue;
            }
        }
    }
    for (j = 0; j < 3; j++)
    {
        for (k = 0; k < 10; k++)
        {
            column[j][k] = 0;
        }
    }
    for (j = 0; j < 3; j++)
    {
        top[j] = 0;
    }
    if (src == 'A')
    {
        for (j = 0; j < n; j++)
        {
            column[0][j] = n - j;
        }
        top[0] = n;
    }
    else if (src == 'B')
    {
        for (j = 0; j < n; j++)
        {
            column[1][j] = n - j;
        }
        top[1] = n;
    }
    else if (src == 'C')
    {
        for (j = 0; j < n; j++)
        {
            column[2][j] = n - j;
        }
        top[2] = n;
    }
    if (choice == '4'||choice=='8')
    {
        cct_cls();
        cout << "从" << setw(2) << src << " 移动到" << setw(2) << dst << "，共 " << n << " 层，延时设置为 " << speed;
        hanoi_output_zongxiangshuzu(choice);
        if (choice == '4')
        {
            cct_gotoxy(X1, Y1);
        }
        else if (choice == '8')
        {
            cct_gotoxy(X1, Y1+15);
        }
        
        cout << "初始:  ";
        hanoi_output_hengxiangshuzu();
        if (choice == '8')
        {
            hanoi_draw_column();
            hanoi_draw_plate(src, n);
            cct_setcolor();
        }
        if (speed == 0)
        {
            while (1)
            {
                if (_getch() == 13)
                {
                    break;
                }
            }
        }
        else 
        {
            Sleep(600-speed*100);
        }
    }
    if (choice == '9')
    {
        cct_cls();
        cout << "从" << setw(2) << src << " 移动到" << setw(2) << dst << "，共 " << n << " 层";
        
        cct_gotoxy(X1, Y1 + 15);
        cout << "初始:  ";
        hanoi_output_hengxiangshuzu();
        hanoi_output_zongxiangshuzu(choice);
        hanoi_draw_column();
        hanoi_draw_plate(src, n);
        cct_setcolor();
    }
    return;
}


void hanoi_output(int n,char src,char tmp,char dst,char choice)
{
    if (choice == '1')
    {
        cout << n << "#" << " " << src << "-->" << dst << endl;
    }
    else if (choice == '2')
    {
        cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")" << endl;
    }
    else if (choice == '3'||choice=='4')
    {
        if (choice == '4')
        {
            cct_gotoxy(X1, Y1);
            cout << "                                                                                                                                                                                                       ";
            cct_gotoxy(X1, Y1);
        }
        cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")  ";
        if (src == 'A' && dst == 'B')
        {
            column[0][--top[0]] = 0;
            column[1][top[1]++] = n;
        }
        else if (src == 'A' && dst == 'C')
        {
            column[0][--top[0]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'B' && dst == 'A')
        {
            column[1][--top[1]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'B' && dst == 'C')
        {
            column[1][--top[1]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'C' && dst == 'A')
        {
            column[2][--top[2]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'C' && dst == 'B')
        {
            column[2][--top[2]] = 0;
            column[1][top[1]++] = n;
        }
        hanoi_output_hengxiangshuzu();
        if (choice == '4')
        {
            hanoi_output_zongxiangshuzu(choice);
            cct_gotoxy(0, 22);
            if (speed == 0)
            {
                while (1)
                {
                    if (_getch() == 13)
                    {
                        break;
                    }
                }
            }
            else 
            {
                Sleep(600 - speed * 100);
            }
        }
    }
    else if (choice == '8')
    {
        hanoi_plate_move(src, dst);
        cct_setcolor();
        cct_gotoxy(X1, Y1+15);
        cout << "                                                                                                                                                                                                       ";
        cct_gotoxy(X1, Y1+15);
        cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")  ";
        
        if (src == 'A' && dst == 'B')
        {
            column[0][--top[0]] = 0;
            column[1][top[1]++] = n;
        }
        else if (src == 'A' && dst == 'C')
        {
            column[0][--top[0]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'B' && dst == 'A')
        {
            column[1][--top[1]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'B' && dst == 'C')
        {
            column[1][--top[1]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'C' && dst == 'A')
        {
            column[2][--top[2]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'C' && dst == 'B')
        {
            column[2][--top[2]] = 0;
            column[1][top[1]++] = n;
        }
        hanoi_output_hengxiangshuzu();
        hanoi_output_zongxiangshuzu(choice);
        cct_gotoxy(0, 35);
        
        if (speed == 0)
        {
            while (1)
            {
                if (_getch() == 13)
                {
                    break;
                }
            }
        }
        else
        {
            Sleep(600 - speed * 100);
        }
    }

}

void hanoi(int n, char src, char tmp, char dst,char choice)
{
    if (n == 1)
    {
        i++;
        hanoi_output(n,src,tmp,dst,choice);
        return;
    }
    hanoi(n - 1, src, dst, tmp,choice);
    i++;
    hanoi_output(n, src, tmp, dst, choice);
    hanoi(n - 1, tmp, src, dst,choice);
    return;
}

void hanoi_draw_column()
{
    int j, k;
    
    for (j = Y3; j > 2; j--)
    {
        if (j == Y3)
        {
            for (k = X3 - 11; k <= X3 + 11; k++)
            {
                cct_showch(k, j, ' ', COLOR_HYELLOW);
            }
            for (k = X4 - 11; k <= X4 + 11; k++)
            {
                cct_showch(k, j, ' ', COLOR_HYELLOW);
            }
            for (k = X5 - 11; k <= X5 + 11; k++)
            {
                cct_showch(k, j, ' ', COLOR_HYELLOW);
            }
        }
        else
        {
            cct_showch(X3, j, ' ', COLOR_HYELLOW);
            cct_showch(X4, j, ' ', COLOR_HYELLOW);
            cct_showch(X5, j, ' ', COLOR_HYELLOW);
        }
        Sleep(300);
    }

    cct_setcolor();
    return;
}

void hanoi_draw_plate(char src,int n)
{
    int j, k,x=0;
    if (src == 'A')
    {
        x = X3;
    }
    else if (src == 'B')
    {
        x = X4;
    }
    else if (src == 'C')
    {
        x = X5;
    }
    for (j = n; j > 0; j--)
    {
        for (k = x - j; k <= x + j; k++)
        {
            cct_showch(k, Y3-1-n+j, ' ', j);
        }
        Sleep(100);
    }
    cct_setcolor();
    return;
}

void hanoi_plate_move(char src,char dst)
{
    int x=0, y=0,j=0;
    if (src == 'A' && dst == 'B')
    {
        for (y = Y3 - top[0]; y > 1; y--)
        {
            for (x = X3 - column[0][top[0] - 1]; x <= X3 + column[0][top[0] - 1]; x++)
            {
                if (x == X3&&y>=3)
                {
                    cct_showch(x, y,' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y,' ',0);
                    cct_setcolor();
                }
                
            }
            for (x = X3 - column[0][top[0] - 1]; x <= X3 + column[0][top[0] - 1]; x++)
            {
                cct_showch(x, y - 1,' ', column[0][top[0] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510-100*speed);
            }
        }
        for (x = X3 - column[0][top[0] - 1]; x <= X4 - column[0][top[0] - 1]-1; x++)
        {
            for (j = x; j <= x + 2 * column[0][top[0] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x+1; j <= x + 2 * column[0][top[0] - 1] + 1; j++)
            {
                cct_showch(j, 1, ' ', column[0][top[0] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3-top[1]-1; y++)
        {
            for (x = X4 - column[0][top[0] - 1]; x <= X4 + column[0][top[0] - 1]; x++)
            {
                if (x == X4 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X4 - column[0][top[0] - 1]; x <= X4 + column[0][top[0] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[0][top[0] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
    else if (src == 'B' && dst == 'C')
    {
        for (y = Y3 - top[1]; y > 1; y--)
        {
            for (x = X4 - column[1][top[1] - 1]; x <= X4 + column[1][top[1] - 1]; x++)
            {
                if (x == X4 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X4 - column[1][top[1] - 1]; x <= X4 + column[1][top[1] - 1]; x++)
            {
                cct_showch(x, y - 1, ' ', column[1][top[1] - 1]);
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (x = X4 - column[1][top[1] - 1]; x <= X5 - column[1][top[1] - 1] - 1; x++)
        {
            for (j = x; j <= x + 2 * column[1][top[1] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x + 1; j <= x + 2 * column[1][top[1] - 1] + 1; j++)
            {
                cct_showch(j, 1, ' ', column[1][top[1] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3 - top[2] - 1; y++)
        {
            for (x = X5 - column[1][top[1] - 1]; x <= X5 + column[1][top[1] - 1]; x++)
            {
                if (x == X5 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X5 - column[1][top[1] - 1]; x <= X5 + column[1][top[1] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[1][top[1] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
    else if (src == 'A' && dst == 'C')
    {
        for (y = Y3 - top[0]; y > 1; y--)
        {
            for (x = X3 - column[0][top[0] - 1]; x <= X3 + column[0][top[0] - 1]; x++)
            {
                if (x == X3 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X3 - column[0][top[0] - 1]; x <= X3 + column[0][top[0] - 1]; x++)
            {
                cct_showch(x, y - 1, ' ', column[0][top[0] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (x = X3 - column[0][top[0] - 1]; x <= X5 - column[0][top[0] - 1] - 1; x++)
        {
            for (j = x; j <= x + 2 * column[0][top[0] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x + 1; j <= x + 2 * column[0][top[0] - 1] + 1; j++)
            {
                cct_showch(j, 1, ' ', column[0][top[0] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3 - top[2] - 1; y++)
        {
            for (x = X5 - column[0][top[0] - 1]; x <= X5 + column[0][top[0] - 1]; x++)
            {
                if (x == X5 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X5 - column[0][top[0] - 1]; x <= X5 + column[0][top[0] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[0][top[0] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
    else if (src == 'B' && dst == 'A')
    {
        for (y = Y3 - top[1]; y > 1; y--)
        {
            for (x = X4 - column[1][top[1] - 1]; x <= X4 + column[1][top[1] - 1]; x++)
            {
                if (x == X4 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();

                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X4 - column[1][top[1] - 1]; x <= X4 + column[1][top[1] - 1]; x++)
            {
                cct_showch(x, y - 1, ' ', column[1][top[1] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (x = X4 - column[1][top[1] - 1]; x >= X3 - column[1][top[1] - 1] + 1; x--)
        {
            for (j = x; j <= x + 2 * column[1][top[1] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x - 1; j <= x + 2 * column[1][top[1] - 1] - 1; j++)
            {
                cct_showch(j, 1, ' ', column[1][top[1] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3 - top[0] - 1; y++)
        {
            for (x = X3 - column[1][top[1] - 1]; x <= X3 + column[1][top[1] - 1]; x++)
            {
                if (x == X3 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X3 - column[1][top[1] - 1]; x <= X3 + column[1][top[1] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[1][top[1] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
    else if (src == 'C' && dst == 'A')
    {
        for (y = Y3 - top[2]; y > 1; y--)
        {
            for (x = X5 - column[2][top[2] - 1]; x <= X5 + column[2][top[2] - 1]; x++)
            {
                if (x == X5 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X5 - column[2][top[2] - 1]; x <= X5 + column[2][top[2] - 1]; x++)
            {
                cct_showch(x, y - 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (x = X5 - column[2][top[2] - 1]; x >= X3 - column[2][top[2] - 1] + 1; x--)
        {
            for (j = x; j <= x + 2 * column[2][top[2] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x - 1; j <= x + 2 * column[2][top[2] - 1] - 1; j++)
            {
                cct_showch(j, 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3 - top[0] - 1; y++)
        {
            for (x = X3 - column[2][top[2] - 1]; x <= X3 + column[2][top[2] - 1]; x++)
            {
                if (x == X3 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X3 - column[2][top[2] - 1]; x <= X3 + column[2][top[2] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
    else if (src == 'C' && dst == 'B')
    {
        for (y = Y3 - top[2]; y > 1; y--)
        {
            for (x = X5 - column[2][top[2] - 1]; x <= X5 + column[2][top[2] - 1]; x++)
            {
                if (x == X5 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X5 - column[2][top[2] - 1]; x <= X5 + column[2][top[2] - 1]; x++)
            {
                cct_showch(x, y - 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (x = X5 - column[2][top[2] - 1]; x >= X4 - column[2][top[2] - 1] + 1; x--)
        {
            for (j = x; j <= x + 2 * column[2][top[2] - 1]; j++)
            {
                cct_showch(j, 1, ' ', 0);
                cct_setcolor();
            }
            for (j = x - 1; j <= x + 2 * column[2][top[2] - 1] - 1; j++)
            {
                cct_showch(j, 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }

            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
        for (y = 1; y < Y3 - top[1] - 1; y++)
        {
            for (x = X4 - column[2][top[2] - 1]; x <= X4 + column[2][top[2] - 1]; x++)
            {
                if (x == X4 && y >= 3)
                {
                    cct_showch(x, y, ' ', COLOR_HYELLOW);
                    cct_setcolor();
                }
                else
                {
                    cct_showch(x, y, ' ', 0);
                    cct_setcolor();
                }

            }
            for (x = X4 - column[2][top[2] - 1]; x <= X4 + column[2][top[2] - 1]; x++)
            {
                cct_showch(x, y + 1, ' ', column[2][top[2] - 1]);
                cct_setcolor();
            }
            if (speed == 0)
            {
                Sleep(100);
            }
            else
            {
                Sleep(510 - 100 * speed);
            }
        }
    }
}
void hanoi_game(int n,char dst,char choice)
{
    int x=0, y=0;
    int complete=0,j;
    char input[20] = {0};
    
    while (!complete)
    {
        complete = 1;//进循环默认完成，游戏是否真的完成在最后进行判断
        cct_gotoxy(X1, Y1 + 16);
        cout << "                                                                                                                                                      ";
        cct_gotoxy(X1, Y1 + 16);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C,Q=退出) ：";
        for (j = 0; j < 20; j++)
        {
            input[j] = 0;//初始化
        }
        for (j = 0; j < 20; j++)
        {
            input[j] = _getche();
            if (input[j] == 'a')
            {
                input[j] = 'A';
            }
            if (input[j] == 'b')
            {
                input[j] = 'B';
            }
            if (input[j] == 'c')
            {
                input[j] = 'C';
            }
            if (input[j] == '\b')
            {
                cct_getxy(x, y);
                cct_gotoxy(x + 1, y);
                j--;
                continue;
            }
            if (input[j] == '\r')
            {
                break;
            }
        }
        /*if (j == 19 && input[19] != '\r')
        {
            while (1)
            {
                if (_getch() == '\r')
                {
                    break;
                }
            }
        }*/
        if (j == 1)
        {
            if (input[0] == 'q' || input[0] == 'Q')
            {
                cct_gotoxy(X1, Y1 + 17);
                cout << "游戏中止!!!!!";
                break;
            }
        }
        if (j == 2)
        {
            if (input[0] == 'A' && input[1] == 'B')
            {
                if (top[0]!=0&&top[1] != 0 && column[0][top[0] - 1] > column[1][top[1] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[0] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('A', 'B');
                    cct_setcolor();
                    column[1][top[1]++] = column[0][top[0] - 1];
                    column[0][--top[0]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "A" << "-->" << "B" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'A' && input[1] == 'C')
            {
                if (top[0] != 0 && top[2] != 0 && column[0][top[0] - 1] > column[2][top[2] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[0] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('A', 'C');
                    cct_setcolor();
                    column[2][top[2]++] = column[0][top[0] - 1];
                    column[0][--top[0]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "A" << "-->" << "C" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'B' && input[1] == 'C')
            {
                if (top[1] != 0 && top[2] != 0 && column[1][top[1] - 1] > column[2][top[2] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[1] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('B', 'C');
                    cct_setcolor();
                    column[2][top[2]++] = column[1][top[1] - 1];
                    column[1][--top[1]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "B" << "-->" << "C" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'B' && input[1] == 'A')
            {
                if (top[1] != 0 && top[0] != 0 && column[1][top[1] - 1] > column[0][top[0] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[1] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('B', 'A');
                    cct_setcolor();
                    column[0][top[0]++] = column[1][top[1] - 1];
                    column[1][--top[1]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "B" << "-->" << "A" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'C' && input[1] == 'A')
            {
                if (top[2] != 0 && top[0] != 0 && column[2][top[2] - 1] > column[0][top[0] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[2] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('C', 'A');
                    cct_setcolor();
                    column[0][top[0]++] = column[2][top[2] - 1];
                    column[2][--top[2]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "C" << "-->" << "A" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'C' && input[1] == 'B')
            {
                if (top[2] != 0 && top[1] != 0 && column[2][top[2] - 1] > column[1][top[1] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "大盘压小盘，非法移动！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[2] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "源柱为空！";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else
                {
                    i++;
                    hanoi_plate_move('C', 'B');
                    cct_setcolor();
                    column[1][top[1]++] = column[2][top[2] - 1];
                    column[2][--top[2]] = 0;
                    cct_gotoxy(X1, Y1 + 15);
                    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "#" << ": " << "C" << "-->" << "B" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            
        }
        if (dst == 'A')
        {
            for (j = 0; j < n; j++)
            {
                if (column[0][j] != n - j)
                {
                    complete = 0;
                }
            }
        }
        else if (dst == 'B')
        {
            for (j = 0; j < n; j++)
            {
                if (column[1][j] != n - j)
                {
                    complete = 0;
                }
            }
        }
        else if (dst == 'C')
        {
            for (j = 0; j < n; j++)
            {
                if (column[2][j] != n - j)
                {
                    complete = 0;
                    
                }
            }
        }
        if (complete == 1)
        {
            cct_gotoxy(X1, Y1 + 17);
            cout << "游戏结束!!!!!";
        }

       
    }
    
    return;
}