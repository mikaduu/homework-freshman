/* 2350233 信21 叶辰 */
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：求num是不是base的幂
     输入参数：
     返 回 值：0 - 不是
               1 - 是
     说    明：函数名、形参、返回类型均不准动
   ***************************************************************************/
int is_power(int num, int base)
{
    int i=0;
    if (num == 1)
    {
        i=1;
    }
    else if (num % base == 0)
    {
        num = num / base;
        i=is_power(num, base);
    }
    else
    {
        i=0;
    }
    if (i == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入、调用递归函数、输出
***************************************************************************/
int main()
{
    int num, base;
    cout << "请输入整数num及基数base" << endl;
    cin >> num >> base;
    if (is_power(num, base))
    {
        cout << num << "是" << base << "的幂" << endl;
    }
    else
    {
        cout << num << "不是" << base << "的幂" << endl;
    }
    return 0;
}
