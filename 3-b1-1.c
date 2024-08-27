/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const double pi = 3.14159;
	double r, h, c_circle, s_circle, s_sphere, v_sphere, v_column;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &r, &h);
	c_circle = 2 * pi * r;
	s_circle = pi * r * r;
	s_sphere = 4 * pi * r * r;
	v_sphere = 4.0 / 3.0 * pi * r * r * r;
	v_column = s_circle * h;
	printf("圆周长     : %.2lf\n", c_circle);
	printf("圆面积     : %.2lf\n", s_circle);
	printf("圆球表面积 : %.2lf\n", s_sphere);
	printf("圆球体积   : %.2lf\n", v_sphere);
	printf("圆柱体积   : %.2lf\n", v_column);
	return 0;
}
