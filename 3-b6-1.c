/*2350233	叶辰	信21*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf",&a);
	printf("大写结果是:\n");
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

	//前两位十亿，亿，不涉及“零”
	switch (sy + 0)
	{
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
	}
	switch (y + 0)
	{
		case 9:
			printf("玖亿");
			break;
		case 8:
			printf("捌亿");
			break;
		case 7:
			printf("柒亿");
			break;
		case 6:
			printf("陆亿");
			break;
		case 5:
			printf("伍亿");
			break;
		case 4:
			printf("肆亿");
			break;
		case 3:
			printf("叁亿");
			break;
		case 2:
			printf("贰亿");
			break;
		case 1:
			printf("壹亿");
			break;
	}
	if (sy != 0 && y == 0)
	{
		printf("亿");
	}

	//万的四位，涉及“零”
	switch (qw + 0)
	{
		case 9:
			printf("玖仟");
			break;
		case 8:
			printf("捌仟");
			break;
		case 7:
			printf("柒仟");
			break;
		case 6:
			printf("陆仟");
			break;
		case 5:
			printf("伍仟");
			break;
		case 4:
			printf("肆仟");
			break;
		case 3:
			printf("叁仟");
			break;
		case 2:
			printf("贰仟");
			break;
		case 1:
			printf("壹仟");
			break;
	}
	if ((sy != 0 || y != 0) && (qw == 0 && bw != 0))//前有数字，千位0，百位非0
	{
		printf("零");
	}
	switch (bw + 0)
	{
		case 9:
			printf("玖佰");
			break;
		case 8:
			printf("捌佰");
			break;
		case 7:
			printf("柒佰");
			break;
		case 6:
			printf("陆佰");
			break;
		case 5:
			printf("伍佰");
			break;
		case 4:
			printf("肆佰");
			break;
		case 3:
			printf("叁佰");
			break;
		case 2:
			printf("贰佰");
			break;
		case 1:
			printf("壹佰");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0) && (bw == 0 && sw != 0))//前有数字，百位0，十位非0，且与之前的if永远不会同时成立，零不会重复
	{
		printf("零");
	}
	switch (sw + 0)
	{
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0) && (sw == 0 && w != 0))//前有数字，十位0，个位非0，且与之前的if永远不会同时成立，零不会重复
	{
		printf("零");
	}
	switch (w + 0)
	{
		case 9:
			printf("玖万");
			break;
		case 8:
			printf("捌万");
			break;
		case 7:
			printf("柒万");
			break;
		case 6:
			printf("陆万");
			break;
		case 5:
			printf("伍万");
			break;
		case 4:
			printf("肆万");
			break;
		case 3:
			printf("叁万");
			break;
		case 2:
			printf("贰万");
			break;
		case 1:
			printf("壹万");
			break;
	}
	if ((qw != 0 && bw == 0 && sw == 0 && w == 0) || (bw != 0 && sw == 0 && w == 0) || (sw != 0 && w == 0))
	{
		printf("万");
	}
	//圆的四位，涉及“零”，末尾固定圆，大体同万的四位
	switch (q + 0)
	{
		case 9:
			printf("玖仟");
			break;
		case 8:
			printf("捌仟");
			break;
		case 7:
			printf("柒仟");
			break;
		case 6:
			printf("陆仟");
			break;
		case 5:
			printf("伍仟");
			break;
		case 4:
			printf("肆仟");
			break;
		case 3:
			printf("叁仟");
			break;
		case 2:
			printf("贰仟");
			break;
		case 1:
			printf("壹仟");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0) && (q == 0 && b != 0))//前有数字，千位0，百位非0
	{
		printf("零");
	}
	switch (b + 0)
	{
		case 9:
			printf("玖佰");
			break;
		case 8:
			printf("捌佰");
			break;
		case 7:
			printf("柒佰");
			break;
		case 6:
			printf("陆佰");
			break;
		case 5:
			printf("伍佰");
			break;
		case 4:
			printf("肆佰");
			break;
		case 3:
			printf("叁佰");
			break;
		case 2:
			printf("贰佰");
			break;
		case 1:
			printf("壹佰");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0) && (b == 0 && s != 0))//前有数字，百位0，十位非0，且与之前的if永远不会同时成立，零不会重复
	{
		printf("零");
	}
	switch (s + 0)
	{
		case 9:
			printf("玖拾");
			break;
		case 8:
			printf("捌拾");
			break;
		case 7:
			printf("柒拾");
			break;
		case 6:
			printf("陆拾");
			break;
		case 5:
			printf("伍拾");
			break;
		case 4:
			printf("肆拾");
			break;
		case 3:
			printf("叁拾");
			break;
		case 2:
			printf("贰拾");
			break;
		case 1:
			printf("壹拾");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0) && (s == 0 && yuan != 0))//前有数字，十位0，个位非0，且与之前的if永远不会同时成立，零不会重复
	{
		printf("零");
	}
	switch (yuan + 0)
	{
		case 9:
			printf("玖圆");
			break;
		case 8:
			printf("捌圆");
			break;
		case 7:
			printf("柒圆");
			break;
		case 6:
			printf("陆圆");
			break;
		case 5:
			printf("伍圆");
			break;
		case 4:
			printf("肆圆");
			break;
		case 3:
			printf("叁圆");
			break;
		case 2:
			printf("贰圆");
			break;
		case 1:
			printf("壹圆");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0) && yuan == 0)
	{
		printf("圆");
	}
	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		printf("零圆");
	}

	//末两位角，分，涉及“零”，“整”，但与前面的圆完全分开
	switch (jiao + 0)
	{
		case 9:
			printf("玖角");
			break;
		case 8:
			printf("捌角");
			break;
		case 7:
			printf("柒角");
			break;
		case 6:
			printf("陆角");
			break;
		case 5:
			printf("伍角");
			break;
		case 4:
			printf("肆角");
			break;
		case 3:
			printf("叁角");
			break;
		case 2:
			printf("贰角");
			break;
		case 1:
			printf("壹角");
			break;
	}
	if ((sy != 0 || y != 0 || qw != 0 || bw != 0 || sw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || yuan != 0) && jiao == 0 && fen != 0)
	{
		printf("零");
	}
	switch (fen + 0)
	{
		case 9:
			printf("玖分");
			break;
		case 8:
			printf("捌分");
			break;
		case 7:
			printf("柒分");
			break;
		case 6:
			printf("陆分");
			break;
		case 5:
			printf("伍分");
			break;
		case 4:
			printf("肆分");
			break;
		case 3:
			printf("叁分");
			break;
		case 2:
			printf("贰分");
			break;
		case 1:
			printf("壹分");
			break;
		case 0:
			printf("整");
			break;
	}
	printf("\n");
	return 0;
}