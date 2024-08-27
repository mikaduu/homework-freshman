/* ��21 2350233 Ҷ�� */
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include"hanoi.h"
#include"cmd_console_tools.h"
using namespace std;


/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
int main()
{
	

	 /*demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	
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
			cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << n << " ��";
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
