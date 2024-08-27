/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	int sy,y,qw,bw,sw,w,q,b,s,yuan,jiao,fen;
	printf("请输入[0-100亿)之间的数字: \n");
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
	printf("十亿位 : %d\n", sy);
	printf("亿位   : %d\n", y);
	printf("千万位 : %d\n", qw);
	printf("百万位 : %d\n", bw);
	printf("十万位 : %d\n", sw);
	printf("万位   : %d\n", w);
	printf("千位   : %d\n", q);
	printf("百位   : %d\n", b);
	printf("十位   : %d\n", s);
	printf("圆     : %d\n", yuan);
	printf("角     : %d\n", jiao);
	printf("分     : %d\n", fen);
	return 0;
	
}