/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	int a,w,q,b,s,g;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &a);
	w = a/10000;
	q = (a / 1000) % 10;
	b = (a / 100) % 10;
	s = (a / 10) % 10;
	g = a % 10;
	printf("��λ : %d\n", w);
	printf("ǧλ : %d\n", q);
	printf("��λ : %d\n", b);
	printf("ʮλ : %d\n", s);
	printf("��λ : %d\n", g);
	return 0;
}