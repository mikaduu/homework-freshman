/*2350233	叶辰	信21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	sy = (int)(a / 1000000000);
	y = (int)(a / 100000000) % 10;
	qw = (int)(a / 10000000) % 10;
	bw = (int)(a / 1000000) % 10;
	sw = (int)(a / 100000) % 10;
	w = (int)(a / 10000) % 10;
	q = (int)(a / 1000) % 10;
	b = (int)(a / 100) % 10;
	s = (int)(a / 10) % 10;
	yuan = (int)((a / 10 - (int)(a / 10)) * 1000 + 0.001) / 100;
	jiao = (int)((a / 10 - (int)(a / 10)) * 100 + 0.001) % 10;
	fen = (int)((a / 10 - (int)(a / 10)) * 1000 + 0.001) % 10;
	cout << "十亿位 : " << sy << endl;
	cout << "亿位   : " << y << endl;
	cout << "千万位 : " << qw << endl;
	cout << "百万位 : " << bw << endl;
	cout << "十万位 : " << sw << endl;
	cout << "万位   : " << w << endl;
	cout << "千位   : " << q << endl;
	cout << "百位   : " << b << endl;
	cout << "十位   : " << s << endl;
	cout << "圆     : " << yuan << endl;
	cout << "角     : " << jiao << endl;
	cout << "分     : " << fen << endl;
	return 0;

}