/* 2350233	叶辰	信21 */
#include <iostream>
#include <string>
#include <cstring>
#include<cmath>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
    /* --允许添加需要的内容 --*/
    int ret = 0, i = 0, j = 0;
    double money;
    int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen, flag_of_zero = 0;
    char ch[] = "拾佰仟万亿圆角分整";
    while (1)
    {
        
        cout << "请输入[0-100亿)之间的数字:" << endl;
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
    //十亿和亿位，无需考虑输出零，flag_of_zero始终为0
    daxie(sy, flag_of_zero);
    if (sy != 0)
    {
        for (j = 2 * SHI; j < 2 * SHI + 2; j++)
        {
            result = result + ch[j];
        }                          //拾
    }
    daxie(y, flag_of_zero);
    if (sy != 0 || y != 0)
    {
        for (j = 2 * YI; j < 2 * YI + 2; j++)
        {
            result = result + ch[j];
        }                           //亿
    }
    //万的四位
    if ((sy != 0 || y != 0) && (bw != 0))//前有数字，千位0，百位非0
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
        }                                //仟
    }
    if ((sy != 0 || y != 0 || qw != 0) && (sw != 0))//前有数字，百位0，十位非0
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
        }                               //佰
    }
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0) && (w != 0))//前有数字，十位0，个位非0
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
        }                                       //万
    }

    //圆的四位
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && (b != 0))//前有数字，千位0，百位非0
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
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0) && (s != 0))//前有数字，百位0，十位非0
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
    if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0) && (yuan != 0))//前有数字，十位0，个位非0
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


    //角和分，涉及整的输出
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
    cout << "大写结果是:" << endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
