/*2350233	Ҷ��	��21*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "������[0-100��)֮�������:" << endl;
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
	cout << "ʮ��λ : " << sy << endl;
	cout << "��λ   : " << y << endl;
	cout << "ǧ��λ : " << qw << endl;
	cout << "����λ : " << bw << endl;
	cout << "ʮ��λ : " << sw << endl;
	cout << "��λ   : " << w << endl;
	cout << "ǧλ   : " << q << endl;
	cout << "��λ   : " << b << endl;
	cout << "ʮλ   : " << s << endl;
	cout << "Բ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;
	return 0;

}