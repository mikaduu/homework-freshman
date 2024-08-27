/* 2350233	叶辰	信21 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

const int X1 = 10;//扫雷的行数
const int Y1 = 26;//扫雷的列数

int main()
{
	int i, j, x, y, m = 0, start_x, end_x, start_y, end_y;
	char saolei[X1][Y1] = { 0 };
	srand((unsigned int)(time(0)));
	for (i = 0; i < 50; i++)
	{
		x = rand() % X1;
		y = rand() % Y1;
		if (saolei[x][y] == '*')
		{
			i--;
			continue;
		}
		else
		{
			saolei[x][y] = '*';
		}
	}

	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			m = 0;
			if (saolei[i][j] != '*')
			{
				if (i != 0 && i != X1 - 1)
				{
					start_x = i - 1;
					end_x = i + 1;
				}
				else if (i == 0)
				{
					start_x = i;
					end_x = i + 1;
				}
				else if (i == X1 - 1)
				{
					start_x = i - 1;
					end_x = i;
				}
				if (j != 0 && j != Y1 - 1)
				{
					start_y = j - 1;
					end_y = j + 1;
				}
				else if (j == 0)
				{
					start_y = j;
					end_y = j + 1;
				}
				else if (j == Y1 - 1)
				{
					start_y = j - 1;
					end_y = j;
				}
				for (x = start_x; x <= end_x; x++)
				{
					for (y = start_y; y <= end_y; y++)
					{
						if (saolei[x][y] == '*')
						{
							m++;
						}
					}
				}

				saolei[i][j] = m;
			}

		}
	}
	for (i = 0; i < X1; i++)
	{
		for (j = 0; j < Y1; j++)
		{
			if (saolei[i][j] != '*')
			{
				cout << int(saolei[i][j]) << " ";
			}
			else
			{
				cout << saolei[i][j] << " ";
			}
		}
		cout << endl;
	}
}
