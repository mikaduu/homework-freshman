/* 2350233	Ҷ��	��21 */
#include <iostream>

using namespace std;

const int LINE = 3;
const int ROW = 128;
int main()
{
	char str[LINE][ROW] = { 0 };
	int i = 0, j = 0;
	int xiaoxie = 0, daxie = 0, shuzi = 0, kongge = 0, qita = 0;
	for (i = 0; i < LINE; )
	{
		cout << "�������" << ++i << "��" << endl;
		cin.getline(str[i-1], ROW, '\n');
	}
	for (i = 0; i < LINE; i++)
	{
		j = 0;
		while (str[i][j] != '\0' && j < ROW)
		{
			if (str[i][j] == ' ')
			{
				kongge++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
			{
				xiaoxie++;
			}
			else if (str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				daxie++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				shuzi++;
			}
			else
			{
				qita++;
			}
			j++;
		}
		
	}
	cout << "��д : " << daxie << endl;
	cout << "Сд : " << xiaoxie << endl;
	cout << "���� : " << shuzi << endl;
	cout << "�ո� : " << kongge << endl;
	cout << "���� : " << qita << endl;
	return 0;
}