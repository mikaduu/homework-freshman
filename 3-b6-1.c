/*2350233	Ҷ��	��21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf",&a);
	printf("��д�����:\n");
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
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 1:
			printf("Ҽʰ");
			break;
	}
	switch (y + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 7:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
	}
	if (sy != 0 && y == 0)
	{
		printf("��");
	}

	//�����λ���漰���㡱
	switch (qw + 0)
	{
		case 9:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 1:
			printf("ҼǪ");
			break;
	}
	if ((sy != 0 || y != 0) && (qw == 0 && bw != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		printf("��");
	}
	switch (bw + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("�ư�");
			break;
		case 7:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("���");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0) && (bw == 0 && sw != 0))//ǰ�����֣���λ0��ʮλ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		printf("��");
	}
	switch (sw + 0)
	{
		case 9:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 1:
			printf("Ҽʰ");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0) && (sw == 0 && w != 0))//ǰ�����֣�ʮλ0����λ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		printf("��");
	}
	switch (w + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 7:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
	}
	if ((qw != 0 && bw == 0 && sw == 0 && w == 0) || (bw != 0 && sw == 0 && w == 0) || (sw != 0 && w == 0))
	{
		printf("��");
	}
	//Բ����λ���漰���㡱��ĩβ�̶�Բ������ͬ�����λ
	switch (q + 0)
	{
		case 9:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 1:
			printf("ҼǪ");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && (q == 0 && b != 0))//ǰ�����֣�ǧλ0����λ��0
	{
		printf("��");
	}
	switch (b + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("�ư�");
			break;
		case 7:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("���");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0) && (b == 0 && s != 0))//ǰ�����֣���λ0��ʮλ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		printf("��");
	}
	switch (s + 0)
	{
		case 9:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 1:
			printf("Ҽʰ");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0) && (s == 0 && yuan != 0))//ǰ�����֣�ʮλ0����λ��0������֮ǰ��if��Զ����ͬʱ�������㲻���ظ�
	{
		printf("��");
	}
	switch (yuan + 0)
	{
		case 9:
			printf("��Բ");
			break;
		case 8:
			printf("��Բ");
			break;
		case 7:
			printf("��Բ");
			break;
		case 6:
			printf("½Բ");
			break;
		case 5:
			printf("��Բ");
			break;
		case 4:
			printf("��Բ");
			break;
		case 3:
			printf("��Բ");
			break;
		case 2:
			printf("��Բ");
			break;
		case 1:
			printf("ҼԲ");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0) && yuan == 0)
	{
		printf("Բ");
	}
	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		printf("��Բ");
	}

	//ĩ��λ�ǣ��֣��漰���㡱��������������ǰ���Բ��ȫ�ֿ�
	switch (jiao + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 7:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("���");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0) && jiao == 0 && fen != 0)
	{
		printf("��");
	}
	switch (fen + 0)
	{
		case 9:
			printf("����");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 7:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 5:
			printf("���");
			break;
		case 4:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 0:
			printf("��");
			break;
	}
	printf("\n");
	return 0;
}