/* 2350233	叶辰	信21 */
#include <iostream>
using namespace std;

const int MAX = 33;//32+1(尾零)


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
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	calculate_dec(str, &dec_number);
	cout << dec_number << endl;
}