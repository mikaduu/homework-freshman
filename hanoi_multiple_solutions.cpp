/* ��21 2350233 Ҷ�� */

#include <iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
static int i=0,speed=5;
static int column[3][10] = { {0},{0},{0} };//0,1,2�ֱ��ӦA,B,C��
static int top[3] = { 0 };


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ʾ��ʾ��Ϣ
     ���������
     �� �� ֵ��
     ˵    �����������������ʱ���ţ���ָ�������ѧϰ��ɺ����Ķ�
   ***************************************************************************/
 void to_be_continued(int X,int Y)
{
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(X, Y);
    cout << "���س�������...";

    /* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}
 void hanoi_output_hengxiangshuzu()//�����ڲ���gotoxy����Ҫ�ں�����ָ��
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
 void hanoi_output_zongxiangshuzu(char choice)//������gotoxy����ʹ��ʱҪ�ǵ��޸ĺ���
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
    i = 0; 
    speed = 5;
    if (choice == '4'||choice=='8')
    {
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
        cout << "��" << setw(2) << src << " �ƶ���" << setw(2) << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;
        hanoi_output_zongxiangshuzu(choice);
        if (choice == '4')
        {
            cct_gotoxy(X1, Y1);
        }
        else if (choice == '8')
        {
            cct_gotoxy(X1, Y1+15);
        }
        
        cout << "��ʼ:  ";
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
        cout << "��" << setw(2) << src << " �ƶ���" << setw(2) << dst << "���� " << n << " ��";
        
        cct_gotoxy(X1, Y1 + 15);
        cout << "��ʼ:  ";
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
        cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")" << endl;
    }
    else if (choice == '3'||choice=='4')
    {
        if (choice == '4')
        {
            cct_gotoxy(X1, Y1);
            cout << "                                                                                                                                                                                                       ";
            cct_gotoxy(X1, Y1);
        }
        cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")  ";
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
        cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << src << "-->" << dst << ")  ";
        
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
        complete = 1;//��ѭ��Ĭ����ɣ���Ϸ�Ƿ����������������ж�
        cct_gotoxy(X1, Y1 + 16);
        cout << "                                                                                                                                                      ";
        cct_gotoxy(X1, Y1 + 16);
        cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C,Q=�˳�) ��";
        for (j = 0; j < 20; j++)
        {
            input[j] = 0;//��ʼ��
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
                cout << "��Ϸ��ֹ!!!!!";
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
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[0] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "A" << "-->" << "B" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'A' && input[1] == 'C')
            {
                if (top[0] != 0 && top[2] != 0 && column[0][top[0] - 1] > column[2][top[2] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[0] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "A" << "-->" << "C" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'B' && input[1] == 'C')
            {
                if (top[1] != 0 && top[2] != 0 && column[1][top[1] - 1] > column[2][top[2] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[1] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "B" << "-->" << "C" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'B' && input[1] == 'A')
            {
                if (top[1] != 0 && top[0] != 0 && column[1][top[1] - 1] > column[0][top[0] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[1] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "B" << "-->" << "A" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'C' && input[1] == 'A')
            {
                if (top[2] != 0 && top[0] != 0 && column[2][top[2] - 1] > column[0][top[0] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[2] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "C" << "-->" << "A" << ")  ";
                    hanoi_output_hengxiangshuzu();
                    hanoi_output_zongxiangshuzu(choice);

                }
            }
            else if (input[0] == 'C' && input[1] == 'B')
            {
                if (top[2] != 0 && top[1] != 0 && column[2][top[2] - 1] > column[1][top[1] - 1])
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "����ѹС�̣��Ƿ��ƶ���";
                    Sleep(500);
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "                                                               ";
                    
                }
                else if (top[2] == 0)
                {
                    cct_gotoxy(X1, Y1 + 17);
                    cout << "Դ��Ϊ�գ�";
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
                    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << "#" << ": " << "C" << "-->" << "B" << ")  ";
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
            cout << "��Ϸ����!!!!!";
        }

       
    }
    
    return;
}