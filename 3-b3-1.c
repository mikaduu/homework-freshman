/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	int sy,y,qw,bw,sw,w,q,b,s,yuan,jiao,fen;
	printf("������[0-100��)֮�������: \n");
	scanf("%lf", &a);

	sy = (int)(a / 1000000000) ;
	y =  (int)(a / 100000000) % 10;
	qw = (int)(a / 10000000) % 10;
	bw = (int)(a / 1000000) % 10;
	sw = (int)(a / 100000) % 10;
	w  = (int)(a / 10000) % 10;
	q  = (int)(a / 1000) % 10;
	b  = (int)(a / 100) % 10;
	s  = (int)(a / 10) % 10;
	yuan = (int)((a / 10 - (int)(a / 10)) * 1000+0.001)/100;
	jiao = (int)((a / 10 - (int)(a / 10)) * 100+0.001) % 10;
	fen = (int)((a / 10 - (int)(a / 10)) * 1000+0.001) % 10;
	printf("ʮ��λ : %d\n", sy);
	printf("��λ   : %d\n", y);
	printf("ǧ��λ : %d\n", qw);
	printf("����λ : %d\n", bw);
	printf("ʮ��λ : %d\n", sw);
	printf("��λ   : %d\n", w);
	printf("ǧλ   : %d\n", q);
	printf("��λ   : %d\n", b);
	printf("ʮλ   : %d\n", s);
	printf("Բ     : %d\n", yuan);
	printf("��     : %d\n", jiao);
	printf("��     : %d\n", fen);
	return 0;
	
}