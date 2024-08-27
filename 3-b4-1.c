/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	float s;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d", &a, &b, & c);
	s = 0.5F * a * b * (float)sin(c / 180.0 * pi);
	printf("三角形面积为 : %.3f", s);
	return 0;
}