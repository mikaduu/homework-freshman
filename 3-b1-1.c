/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const double pi = 3.14159;
	double r, h, c_circle, s_circle, s_sphere, v_sphere, v_column;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &r, &h);
	c_circle = 2 * pi * r;
	s_circle = pi * r * r;
	s_sphere = 4 * pi * r * r;
	v_sphere = 4.0 / 3.0 * pi * r * r * r;
	v_column = s_circle * h;
	printf("Բ�ܳ�     : %.2lf\n", c_circle);
	printf("Բ���     : %.2lf\n", s_circle);
	printf("Բ������ : %.2lf\n", s_sphere);
	printf("Բ�����   : %.2lf\n", v_sphere);
	printf("Բ�����   : %.2lf\n", v_column);
	return 0;
}
