/* 2350233	Ҷ��	��21 */
#include <iostream>
using namespace std;

const int MAX = 33;//32+1(β��)


void calculate_dec(char *p,unsigned int *number)
{
	for (; *p != 0; p++)
	{
		*number = 2 * (*number) + (*p - '0');
	}
	return;
}
int main()
{
	char str[MAX] = { 0 };
	unsigned int dec_number = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	calculate_dec(str, &dec_number);
	cout << dec_number << endl;
}