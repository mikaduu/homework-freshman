/* 2350233	Ҷ��	��21 */
#include <iostream>
#include <string>
#include <cstring>
#include<cmath>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
    int j;
    if (num != 0 || (num == 0 && flag_of_zero == 1))
    {
        for (j = 2 * num; j < 2 * num + 2; j++)
        {
            result = result + chnstr[j];
        }
    }

    return ;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    const int SHI = 0;
    const int BAI = 1;
    const int QIAN = 2;
    const int WAN = 3;
    const int YI = 4;
    const int YUAN = 5;
    const int JIAO = 6;
    const int FEN = 7;
    const int ZHENG = 8;
    /* --���������Ҫ������ --*/
    int ret = 0, i = 0, j = 0;
    double money;
    int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen, flag_of_zero = 0;
    char ch[] = "ʰ��Ǫ����Բ�Ƿ���";
    while (1)
    {
        
        cout << "������[0-100��)֮�������:" << endl;
        cin >> money;
        if (cin.good())
        {
            money = round(money * 100) / 100;
            if (0 <= money && money < 10000000000)
            {
                break;
            }

        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }

    }
    sy = (int)(money / 1000000000);
    y = (int)(money / 100000000) % 10;
    qw = (int)(money / 10000000) % 10;
    bw = (int)(money / 1000000) % 10;
    sw = (int)(money / 100000) % 10;
    w = (int)(money / 10000) % 10;
    q = (int)(money / 1000) % 10;
    b = (int)(money / 100) % 10;
    s = (int)(money / 10) % 10;
    yuan = (int)((money / 10 - (int)(money / 10)) * 1000 + 0.001) / 100;
    jiao = (int)((money / 10 - (int)(money / 10)) * 100 + 0.001) % 10;
    fen = (int)((money / 10 - (int)(money / 10)) * 1000 + 0.001) % 10;
    //ʮ�ں���λ�����迼������㣬flag_of_zeroʼ��Ϊ0
    daxie(sy, flag_of_zero);
    if (sy != 0)
    {
        for (j = 2 * SHI; j < 2 * SHI + 2; j++)
        {
            result = result + ch[j];
        }                          //ʰ
    }
    daxie(y, flag_of_zero);
    if (sy != 0 || y != 0)
    {
        for (j = 2 * YI; j < 2 * YI + 2; j++)
        {
            result = result + ch[j];
        }                           //��
    }
    //�����λ
    if ((sy != 0 || y != 0) && (bw != 0))//ǰ�����֣�ǧλ0����λ��0
    {
        flag_of_zero = 1;
    }
    else
    {
        flag_of_zero = 0;
    }
    daxie(qw, flag_of_zero);
    if (qw != 0)
    {
        for (j = 2 * QIAN; j < 2 * QIAN + 2; j++)
        {
            result = result + ch[j];
        }                                //Ǫ
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
        for (j = 2 * BAI; j < 2 * BAI + 2; j++)
        {
            result = result + ch[j];
        }                               //��
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
        for (j = 2 * SHI; j < 2 * SHI + 2; j++)
        {
            result = result + ch[j];
        }
    }
    flag_of_zero = 0;
    daxie(w, flag_of_zero);
    if (qw != 0 || bw != 0 || sw != 0 || w != 0)
    {
        for (j = 2 * WAN; j < 2 * WAN + 2; j++)
        {
            result = result + ch[j];
        }                                       //��
    }

    //Բ����λ
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && (b != 0))//ǰ�����֣�ǧλ0����λ��0
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
        for (j = 2 * QIAN; j < 2 * QIAN + 2; j++)
        {
            result = result + ch[j];
        }
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
        for (j = 2 * BAI; j < 2 * BAI + 2; j++)
        {
            result = result + ch[j];
        }
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
        for (j = 2 * SHI; j < 2 * SHI + 2; j++)
        {
            result = result + ch[j];
        }
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
        for (j = 2 * YUAN; j < 2 * YUAN + 2; j++)
        {
            result = result + ch[j];
        }
    }
    if (sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0)
    {
        for (j = 2 * YUAN; j < 2 * YUAN + 2; j++)
        {
            result = result + ch[j];
        }
    }


    //�Ǻͷ֣��漰�������
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0) && fen != 0)
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
        for (j = 2 * JIAO; j < 2 * JIAO + 2; j++)
        {
            result = result + ch[j];
        }
    }
    flag_of_zero = 0;
    daxie(fen, flag_of_zero);
    if (fen != 0)
    {
        for (j = 2 * FEN; j < 2 * FEN + 2; j++)
        {
            result = result + ch[j];
        }
    }
    else
    {
        for (j = 2 * ZHENG; j < 2 * ZHENG + 2; j++)
        {
            result = result + ch[j];
        }
    }
    cout << "��д�����:" << endl;
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
