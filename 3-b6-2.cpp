/* 2350233	Ҷ��	��21 */
#include <iostream>
using namespace std;

int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
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
	
	//ǰ��λʮ�ڣ��ڣ����漰���㡱
	switch (sy + 0)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
	}
	switch (y + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
	}
	if (sy != 0 && y == 0)
	{
		cout << "��";
	}

	//�����λ���漰���㡱
	switch (qw + 0)
	{
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
	}
	if ((sy != 0 || y != 0) && (qw == 0 && bw != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		cout << "��";
	}
	switch (bw + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0) && (bw == 0 && sw != 0))//ǰ�����֣���λ0��ʮλ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		cout << "��";
	}
	switch (sw + 0)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0) && (sw == 0 && w != 0))//ǰ�����֣�ʮλ0����λ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		cout << "��";
	}
	switch (w + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
	}
	if ((qw != 0 && bw == 0 && sw == 0 && w == 0) || (bw != 0 && sw == 0 && w == 0) || (sw != 0 && w == 0))
	{
		cout << "��";
	}
	//Բ����λ���漰���㡱��ĩβ�̶�Բ������ͬ�����λ
	switch (q + 0)
	{
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && (q == 0 && b != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		cout << "��";
	}
	switch (b + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0) && (b == 0 && s != 0))//ǰ�����֣���λ0��ʮλ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		cout << "��";
	}
	switch (s + 0)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0) && (s == 0 && yuan != 0))//ǰ�����֣�ʮλ0����λ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		cout << "��";
	}
	switch (yuan + 0)
	{
		case 9:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 1:
			cout << "ҼԲ";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0) && yuan == 0)
	{
		cout << "Բ";
	}
	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		cout << "��Բ";
	}

	//ĩ��λ�ǣ��֣��漰���㡱��������������ǰ���Բ��ȫ�ֿ�
	switch (jiao + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0) && jiao == 0 && fen != 0)
	{
		cout << "��";
	}
	switch (fen + 0)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			cout << "��";
			break;
	}
	cout << endl;
	return 0;
}