/*2350233	Ò¶³½	ÐÅ21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i=1, j=1;
	while (i < 10)
	{
		while (j < i+1)
		{
			printf("%dx%d=%-4d", j, i, i * j);
			j++;
		}
		i++;
		j = 1;
		printf("\n");
	}
	printf("\n");
	return 0;
}