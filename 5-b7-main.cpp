/* 2350233 叶辰 信21 */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include"5-b7.h"
using namespace std;

int i = 0;//计数器
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//a,b,c分别对应A,B,C柱
int a_top = 0, b_top = 0, c_top = 0;
static int appearance;
const int X1 = 20;//输出第几步的位置
const int Y1 = 25;//输出第几步的位置
const int X2 = 9;//输出汉诺塔的底座位置
const int Y2 = 20;//输出汉诺塔的底座位置

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,int speed)
{
    int j = 0, m = 0;
    if (n == 1)
    {
        i++;
        cct_gotoxy(X2, Y2);
        cout << "=========================";
        cct_gotoxy(X2, Y2+1);
        cout << "  A         B         C";
        for (j = 0; j < 10; j++)
        {
            if (a[j] != 0)
            {
                cct_gotoxy(X2 + 2, Y2 - 1 - j);
                cout << a[j];
            }
            else
            {
                cct_gotoxy(X2 + 2, Y2 - 1 - j);
                cout << " ";
            }
        }
        for (j = 0; j < 10; j++)
        {
            if (b[j] != 0)
            {
                cct_gotoxy(X2 + 12, Y2 - 1 - j);
                cout << b[j];
            }
            else
            {
                cct_gotoxy(X2 + 12, Y2 - 1 - j);
                cout << " ";
            }
        }
        for (j = 0; j < 10; j++)
        {
            if (c[j] != 0)
            {
                cct_gotoxy(X2 + 22, Y2 - 1 - j);
                cout << c[j];
            }
            else
            {
                cct_gotoxy(X2 + 22, Y2 - 1 - j);
                cout << " ";
            }
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
        else if (speed == 1)
        {
            Sleep(500);
        }
        else if (speed == 2)
        {
            Sleep(400);
        }
        else if (speed == 3)
        {
            Sleep(300);
        }
        else if (speed == 4)
        {
            Sleep(200);
        }
        else if (speed == 5)
        {
            Sleep(100);
        }
        cct_gotoxy(X1, Y1);
        cout << "第" << setw(4) << i << "步" << "(" << n << "#" << ": " << src << "-->" << dst << ")  ";
        if (src == 'A' && dst == 'B')
        {
            a[--a_top] = 0;
            b[b_top++] = n;
        }
        else if (src == 'A' && dst == 'C')
        {
            a[--a_top] = 0;
            c[c_top++] = n;
        }
        else if (src == 'B' && dst == 'A')
        {
            b[--b_top] = 0;
            a[a_top++] = n;
        }
        else if (src == 'B' && dst == 'C')
        {
            b[--b_top] = 0;
            c[c_top++] = n;
        }
        else if (src == 'C' && dst == 'A')
        {
            c[--c_top] = 0;
            a[a_top++] = n;
        }
        else if (src == 'C' && dst == 'B')
        {
            c[--c_top] = 0;
            b[b_top++] = n;
        }
        if (appearance)
        {
            cout << "A:";
            for (j = 0; j < 10; j++)
            {
                if (a[j] != 0)
                {
                    cout << setw(2) << a[j];
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
                if (b[j] != 0)
                {
                    cout << setw(2) << b[j];
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
                if (c[j] != 0)
                {
                    cout << setw(2) << c[j];
                }
                else
                {
                    break;
                }
            }
            cout << setw(21 - 2 * j) << " ";
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
        else if (speed == 1)
        {
            Sleep(500);
        }
        else if (speed == 2)
        {
            Sleep(400);
        }
        else if (speed == 3)
        {
            Sleep(300);
        }
        else if (speed == 4)
        {
            Sleep(200);
        }
        else if (speed == 5)
        {
            Sleep(100);
        }
        return;
    }
    hanoi(n - 1, src, dst, tmp,speed);
    i++;
    cct_gotoxy(X2, Y2);
    cout << "=========================";
    cct_gotoxy(X2, Y2 + 1);
    cout << "  A         B         C";
    for (j = 0; j < 10; j++)
    {
        if (a[j] != 0)
        {
            cct_gotoxy(X2 + 2, Y2 - 1 - j);
            cout << a[j];
        }
        else
        {
            cct_gotoxy(X2 + 2, Y2 - 1 - j);
            cout << " ";
        }
    }
    for (j = 0; j < 10; j++)
    {
        if (b[j] != 0)
        {
            cct_gotoxy(X2 + 12, Y2 - 1 - j);
            cout << b[j];
        }
        else
        {
            cct_gotoxy(X2 + 12, Y2 - 1 - j);
            cout << " ";
        }
    }
    for (j = 0; j < 10; j++)
    {
        if (c[j] != 0)
        {
            cct_gotoxy(X2 + 22, Y2 - 1 - j);
            cout << c[j];
        }
        else
        {
            cct_gotoxy(X2 + 22, Y2 - 1 - j);
            cout << " ";
        }
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
    else if (speed == 1)
    {
        Sleep(500);
    }
    else if (speed == 2)
    {
        Sleep(400);
    }
    else if (speed == 3)
    {
        Sleep(300);
    }
    else if (speed == 4)
    {
        Sleep(200);
    }
    else if (speed == 5)
    {
        Sleep(100);
    }
    cct_gotoxy(X1, Y1);
    cout << "第" << setw(4) << i << "步" << "(" << n << "#" << ": " << src << "-->" << dst << ")  ";
    if (src == 'A' && dst == 'B')
    {
        a[--a_top] = 0;
        b[b_top++] = n;
    }
    else if (src == 'A' && dst == 'C')
    {
        a[--a_top] = 0;
        c[c_top++] = n;
    }
    else if (src == 'B' && dst == 'A')
    {
        b[--b_top] = 0;
        a[a_top++] = n;
    }
    else if (src == 'B' && dst == 'C')
    {
        b[--b_top] = 0;
        c[c_top++] = n;
    }
    else if (src == 'C' && dst == 'A')
    {
        c[--c_top] = 0;
        a[a_top++] = n;
    }
    else if (src == 'C' && dst == 'B')
    {
        c[--c_top] = 0;
        b[b_top++] = n;
    }
    if (appearance)
    {
        cout << "A:";
        for (j = 0; j < 10; j++)
        {
            if (a[j] != 0)
            {
                cout << setw(2) << a[j];
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
            if (b[j] != 0)
            {
                cout << setw(2) << b[j];
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
            if (c[j] != 0)
            {
                cout << setw(2) << c[j];
            }
            else
            {
                break;
            }
        }
        cout << setw(21 - 2 * j) << " ";
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
    else if (speed == 1)
    {
        Sleep(500);
    }
    else if (speed == 2)
    {
        Sleep(400);
    }
    else if (speed == 3)
    {
        Sleep(300);
    }
    else if (speed == 4)
    {
        Sleep(200);
    }
    else if (speed == 5)
    {
        Sleep(100);
    }
    hanoi(n - 1, tmp, src, dst,speed);
    return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n, j,speed;
    char src, tmp, dst;
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
            cin.clear();
            cin.ignore(10000000, '\n');
        }
        else if (dst == 'b' || dst == 'B')
        {
            dst = 'B';
            cin.clear();
            cin.ignore(10000000, '\n');
        }
        else if (dst == 'c' || dst == 'C')
        {
            dst = 'C';
            cin.clear();
            cin.ignore(10000000, '\n');
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
    if (src == 'A')
    {
        for (j = 0; j < n; j++)
        {
            a[j] = n - j;
        }
        a_top = n;
    }
    else if (src == 'B')
    {
        for (j = 0; j < n; j++)
        {
           b[j] = n - j;
        }
        b_top = n;
    }
    else if (src == 'C')
    {
        for (j = 0; j < n; j++)
        {
            c[j] = n - j;
        }
        c_top = n;
    }
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
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> appearance;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        if (0 <= appearance && appearance <= 1)
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
    cct_cls();
    cout << "从" << setw(2) << src << " 移动到" << setw(2) << dst << "，共 " << n << " 层，延时设置为 "<<speed<<"，";
    if (appearance)
    {
        cout << "显示内部数组值";
        cct_gotoxy(X1, Y1);
        cout << "初始:" << setw(16) << " ";
        cout << "A:";
        for (j = 0; j < 10; j++)
        {
            if (a[j] != 0)
            {
                cout << setw(2) << a[j];
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
            if (b[j] != 0)
            {
                cout << setw(2) << b[j];
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
            if (c[j] != 0)
            {
                cout << setw(2) << c[j];
            }
            else
            {
                break;
            }
        }
        cout << setw(21 - 2 * j) << " ";
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
        else if (speed == 1)
        {
            Sleep(500);
        }
        else if (speed == 2)
        {
            Sleep(400);
        }
        else if (speed == 3)
        {
            Sleep(300);
        }
        else if (speed == 4)
        {
            Sleep(200);
        }
        else if (speed == 5)
        {
            Sleep(100);
        }
    }
    else
    {
        cout << "不显示内部数组值";
    }

    hanoi(n, src, tmp, dst,speed);
    cct_gotoxy(X2, Y2);
    cout << "=========================";
    cct_gotoxy(X2, Y2 + 1);
    cout << "  A         B         C";
    for (j = 0; j < 10; j++)
    {
        if (a[j] != 0)
        {
            cct_gotoxy(X2 + 2, Y2 - 1 - j);
            cout << a[j];
        }
        else
        {
            cct_gotoxy(X2 + 2, Y2 - 1 - j);
            cout << " ";
        }
    }
    for (j = 0; j < 10; j++)
    {
        if (b[j] != 0)
        {
            cct_gotoxy(X2 + 12, Y2 - 1 - j);
            cout << b[j];
        }
        else
        {
            cct_gotoxy(X2 + 12, Y2 - 1 - j);
            cout << " ";
        }
    }
    for (j = 0; j < 10; j++)
    {
        if (c[j] != 0)
        {
            cct_gotoxy(X2 + 22, Y2 - 1 - j);
            cout << c[j];
        }
        else
        {
            cct_gotoxy(X2 + 22, Y2 - 1 - j);
            cout << " ";
        }
    }
    cct_gotoxy(X1, Y1 + 10);
    system("pause");
    return 0;
}

