/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	float s;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d %d %d", &a, &b, & c);
	s = 0.5F * a * b * (float)sin(c / 180.0 * pi);
	printf("���������Ϊ : %.3f", s);
	return 0;
}