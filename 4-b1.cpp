/* 2350233	Ҷ��	��21 */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen, flag_of_zero;
	flag_of_zero = 0;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;
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
	//ʮ�ں���λ�����迼������㣬flag_of_zeroʼ��Ϊ0
	daxie(sy, flag_of_zero);
	if (sy != 0)
	{
		cout << "ʰ";
	}
	daxie(y, flag_of_zero);
	if (sy != 0 || y != 0)
	{
		cout << "��";
	}
	
	//�����λ
	if ((sy != 0 || y != 0) && ( bw != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		flag_of_zero=1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(qw, flag_of_zero);
	if (qw != 0)
	{
		cout << "Ǫ";
	}
	if ((sy != 0 || y != 0 || qw != 0) && (sw != 0))//ǰ�����֣���λ0��ʮλ��0
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(bw, flag_of_zero);
	if (bw != 0)
	{
		cout << "��";
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0) && (w != 0))//ǰ�����֣�ʮλ0����λ��0
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(sw, flag_of_zero);
	if (sw != 0)
	{
		cout << "ʰ";
	}
	flag_of_zero = 0;
	daxie(w, flag_of_zero);
	if (qw != 0 || bw != 0 || sw != 0 || w != 0)
	{
		cout << "��";
	}
	
	//Բ����λ
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && ( b != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		flag_of_zero = 1;
	}
	else 
	{
		flag_of_zero = 0;
	}
	daxie(q, flag_of_zero);
	if (q != 0)
	{
		cout << "Ǫ";
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0) && (s != 0))//ǰ�����֣���λ0��ʮλ��0
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(b, flag_of_zero);
	if (b != 0)
	{
		cout << "��";
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0) && (yuan != 0))//ǰ�����֣�ʮλ0����λ��0
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(s, flag_of_zero);
	if (s != 0)
	{
		cout << "ʰ";
	}
	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(yuan, flag_of_zero);
	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		cout << "Բ";
	}
	if (sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0)
	{
		cout << "Բ";
	}
	
	//�Ǻͷ֣��漰�������
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0)&& fen != 0)
	{
		flag_of_zero = 1;
	}
	else
	{
		flag_of_zero = 0;
	}
	daxie(jiao, flag_of_zero);
	if (jiao != 0)
	{
		cout << "��";
	}
	flag_of_zero = 0;
	daxie(fen, flag_of_zero);
	if (fen != 0)
	{
		cout << "��";
	}
	else
	{
		cout << "��";
	}
	cout << endl;
	/* ������� */
	return 0;
}
