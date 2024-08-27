/* 2350233 Ҷ�� ��21 */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include"5-b7.h"
using namespace std;

int i = 0;//������
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//a,b,c�ֱ��ӦA,B,C��
int a_top = 0, b_top = 0, c_top = 0;
static int appearance;
const int X1 = 20;//����ڼ�����λ��
const int Y1 = 25;//����ڼ�����λ��
const int X2 = 9;//�����ŵ���ĵ���λ��
const int Y2 = 20;//�����ŵ���ĵ���λ��

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
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
        cout << "��" << setw(4) << i << "��" << "(" << n << "#" << ": " << src << "-->" << dst << ")  ";
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
    cout << "��" << setw(4) << i << "��" << "(" << n << "#" << ": " << src << "-->" << dst << ")  ";
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n, j,speed;
    char src, tmp, dst;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
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
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
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
    cout << "��" << setw(2) << src << " �ƶ���" << setw(2) << dst << "���� " << n << " �㣬��ʱ����Ϊ "<<speed<<"��";
    if (appearance)
    {
        cout << "��ʾ�ڲ�����ֵ";
        cct_gotoxy(X1, Y1);
        cout << "��ʼ:" << setw(16) << " ";
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
        cout << "����ʾ�ڲ�����ֵ";
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

