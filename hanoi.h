/* ��21 2350233 Ҷ�� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

const int X1 = 0;//����ڼ�����λ��
const int Y1 = 17;//����ڼ�����λ��
const int X2 = 9;//�����ŵ���ĵ���λ��
const int Y2 = 12;//�����ŵ���ĵ���λ��
const int X3 = 12;
const int X4 = 44;
const int X5 = 76;//�������ӵ�����
const int Y3 = 15;//ͼ�λ����ӵĵ���



int hanoi_menu();
void hanoi_input(int& n, char& src, char& tmp, char& dst,char choice);
void hanoi(int n, char src, char tmp, char dst, char choice);
void to_be_continued(int X=0,int Y=22);
void hanoi_draw_column();
void hanoi_draw_plate(char src, int n);
void hanoi_plate_move(char src, char dst);
void hanoi_game(int n, char dst, char choice);