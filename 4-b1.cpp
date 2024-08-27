/* 2350233	叶辰	信21 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen, flag_of_zero;
	flag_of_zero = 0;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;
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
	//十亿和亿位，无需考虑输出零，flag_of_zero始终为0
	daxie(sy, flag_of_zero);
	if (sy != 0)
	{
		cout << "拾";
	}
	daxie(y, flag_of_zero);
	if (sy != 0 || y != 0)
	{
		cout << "亿";
	}
	
	//万的四位
	if ((sy != 0 || y != 0) && ( bw != 0))//前有数字，千位0，百位非0
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
		cout << "仟";
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
		cout << "佰";
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
		cout << "拾";
	}
	flag_of_zero = 0;
	daxie(w, flag_of_zero);
	if (qw != 0 || bw != 0 || sw != 0 || w != 0)
	{
		cout << "万";
	}
	
	//圆的四位
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && ( b != 0))//前有数字，千位0，百位非0
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
		cout << "仟";
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
		cout << "佰";
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
		cout << "拾";
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
		cout << "圆";
	}
	if (sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0)
	{
		cout << "圆";
	}
	
	//角和分，涉及整的输出
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
		cout << "角";
	}
	flag_of_zero = 0;
	daxie(fen, flag_of_zero);
	if (fen != 0)
	{
		cout << "分";
	}
	else
	{
		cout << "整";
	}
	cout << endl;
	/* 按需完成 */
	return 0;
}
