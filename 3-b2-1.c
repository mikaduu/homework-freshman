/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	int a,w,q,b,s,g;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &a);
	w = a/10000;
	q = (a / 1000) % 10;
	b = (a / 100) % 10;
	s = (a / 10) % 10;
	g = a % 10;
	printf("万位 : %d\n", w);
	printf("千位 : %d\n", q);
	printf("百位 : %d\n", b);
	printf("十位 : %d\n", s);
	printf("个位 : %d\n", g);
	return 0;
}