/* 2350233	Ҷ��	��21 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu()
{
	int ch;
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n" );
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n" );
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ�������ƶ�)\n" );
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ�������ƶ�)\n" );
	printf("0.�˳�\n");
	printf("[��ѡ��0-6] ");
	ch = _getche();
	return ch;
}

void move_by_ijkl(const HANDLE hout, int a)
{
	int input, x = 35, y = 9;//input��ʾ�Ӽ��̶��������

	while (1)
	{
		input = _getch();
		if (input == 105 || input == 73)//����i
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
			gotoxy(hout, x, y);
		}
		else if (input == 106 || input == 74)//����j
		{
			x--;
			if (a == 49 && x < 1)
			{
				x = 1;
			}
			else if (a == 50 && x < 1)
			{
				x = 69;
			}
			gotoxy(hout, x, y);
		}
		else if (input == 107 || input == 75)//����k
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
		else if (input == 108 || input == 76)//����L
		{
			x++;
			if (a == 49 && x > 69)
			{
				x = 69;
			}
			else if (a == 50 && x > 69)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input == 32)
		{
			printf(" \b");
		}
		else if (input == 113 || input == 81)
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
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
	int input1, input2, x = 35, y = 9;//input��ʾ�Ӽ��̶��������

	while (1)
	{
		input1 = _getch();
		if (input1 == 224)
		{
			input2 = _getch();
		}
		else if (input1 == 113 || input1 == 81 || input1 == 32)
		{
			;//����䣬ʹ���ո�������q�˳�ֻ�谴һ�ξ������
		}
		else
		{
			continue;
		}

		if (input1 == 224 && input2 == 72)//������
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
		else if (input1 == 224 && input2 == 75)//������
		{
			x--;
			if (a == 51 && x < 1)
			{
				x = 1;
			}
			else if (a == 52 && x < 1)
			{
				x = 69;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 224 && input2 == 80)//������
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
		else if (input1 == 224 && input2 == 77)//������
		{
			x++;
			if (a == 51 && x > 69)
			{
				x = 69;
			}
			else if (a == 52 && x > 69)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
		}
		else if (input1 == 32)
		{
			printf(" \b");
		}
		else if (input1 == 113 || input1 == 81)
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
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
	int input1, input2, x = 35, y = 9;//input��ʾ�Ӽ��̶��������


	while (1)
	{
		input1 = _getch();
		if (input1 == 224)
		{
			input2 = _getch();//������Ĳ����ȡ��
		}

		if (input1 == 105 || input1 == 73)//����i
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
		else if (input1 == 106 || input1 == 74)//����j
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
		else if (input1 == 107 || input1 == 75)//����k
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
		else if (input1 == 108 || input1 == 76)//����L
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
			printf(" \b");
		}
		else if (input1 == 113 || input1 == 81)
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	int a;//(a�洢menu()�ķ���ֵ)
	while (1)
	{
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
		a = menu();
		if (a == 48)//menu()����ֵΪ0
		{
			break;
		}
		else if (a == 49)//menu()����ֵΪ1
		{

			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, a);
		}
		else if (a == 50)//menu()����ֵΪ2
		{

			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, a);
		}
		else if (a == 51)//menu()����ֵΪ3
		{

			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, a);
		}
		else if (a == 52)//menu()����ֵΪ4
		{

			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, a);
		}
		else if (a == 53)//menu()����ֵΪ5
		{

			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_ijkl_correct(hout, a);
		}
		else if (a == 54)//menu()����ֵΪ6
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
Ϊʲô������ɵ���ĸ�����ܲ���20����
��Ϊ��ĸΪ������������������������������ĸ��ͬһλ�����������һ����ĸ�ᶥ��ǰһ����ĸ���������ճ�������Ļ�ϵ���ĸ������20��
*/