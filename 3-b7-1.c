/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double money;
	int fifty = 0, twenty = 0, ten = 0, five_yuan = 0, yuan = 0, five_jiao = 0, jiao = 0, five_fen = 0, two_fen = 0, fen = 0, total = 0;
	printf("����������ֵ��\n");
	scanf("%lf",&money);
	money = money * 100;
	switch ((int)money / 5000)
	{
		case 0:
		{
			break;
		}
		default:
		{
			fifty = (int)money / 5000;
			total = total + fifty;
			break;
		}
	}
	switch (((int)money - fifty * 5000) / 2000)
	{
		case 0:
		{
			break;
		}
		default:
		{
			twenty = ((int)money - fifty * 5000) / 2000;
			total = total + twenty;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000) / 1000)
	{
		case 0:
		{
			break;
		}
		default:
		{
			ten = ((int)money - fifty * 5000 - twenty * 2000) / 1000;
			total = total + ten;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000) / 500)
	{
		case 0:
		{
			break;
		}
		default:
		{
			five_yuan = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000) / 500;
			total = total + five_yuan;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500) / 100)
	{
		case 0:
		{
			break;
		}
		default:
		{
			yuan = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500) / 100;
			total = total + yuan;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100) / 50)
	{
		case 0:
		{
			break;
		}
		default:
		{
			five_jiao = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100) / 50;
			total = total + five_jiao;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50) / 10)
	{
		case 0:
		{
			break;
		}
		default:
		{
			jiao = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50) / 10;
			total = total + jiao;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10) / 5)
	{
		case 0:
		{
			break;
		}
		default:
		{
			five_fen = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10) / 5;
			total = total + five_fen;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10 - five_fen * 5) / 2)
	{
		case 0:
		{
			break;
		}
		default:
		{
			two_fen = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10 - five_fen * 5) / 2;
			total = total + two_fen;
			break;
		}
	}
	switch (((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10 - five_fen * 5 - two_fen * 2) / 1)
	{
		case 0:
		{
			break;
		}
		default:
		{
			fen = ((int)money - fifty * 5000 - twenty * 2000 - ten * 1000 - five_yuan * 500 - yuan * 100 - five_jiao * 50 - jiao * 10 - five_fen * 5 - two_fen * 2) / 1;
			total = total + fen;
			break;
		}
	}
	printf("��%d�����㣬�������£�\n",total);
	if (fifty != 0)
	{
		printf("50Ԫ : %d��\n",fifty);
	}
	if (twenty != 0)
	{
		printf("20Ԫ : %d��\n", twenty);
	}
	if (ten != 0)
	{
		printf("10Ԫ : %d��\n", ten);
	}
	if (five_yuan != 0)
	{
		printf("5Ԫ  : %d��\n", five_yuan);
	}
	if (yuan != 0)
	{
		printf("1Ԫ  : %d��\n", yuan);
	}
	if (five_jiao != 0)
	{
		printf("5��  : %d��\n", five_jiao);
	}
	if (jiao != 0)
	{
		printf("1��  : %d��\n", jiao);
	}
	if (five_fen != 0)
	{
		printf("5��  : %d��\n", five_fen);
	}
	if (two_fen != 0)
	{
		printf("2��  : %d��\n", two_fen);
	}
	if (fen != 0)
	{
		printf("1��  : %d��\n", fen);
	}
	return 0;
}