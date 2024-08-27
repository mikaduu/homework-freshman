/* 2350233 叶辰 信21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int i = 0;//计数器
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//a,b,c分别对应A,B,C柱
int a_top=0, b_top=0, c_top=0;

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int j=0,m=0;
    if (n == 1)
    {
        i++;
        printf("第%4d 步(%2d): %c-->%c ", i, n, src, dst);
        if (src == 'A' && dst == 'B')
        {
            a[--a_top] = 0;
            b[b_top++] = n;
        }
        else if (src == 'A' && dst == 'C')
        {
            a[--a_top] = 0;
            c[c_top++] = n;
        }
        else if (src == 'B' && dst == 'A')
        {
            b[--b_top] = 0;
            a[a_top++] = n;
        }
        else if (src == 'B' && dst == 'C')
        {
            b[--b_top] = 0;
            c[c_top++] = n;
        }
        else if (src == 'C' && dst == 'A')
        {
            c[--c_top] = 0;
            a[a_top++] = n;
        }
        else if (src == 'C' && dst == 'B')
        {
            c[--c_top] = 0;
            b[b_top++] = n;
        }
        printf("A:");
        for (j = 0; j < 10; j++)
        {
            if (a[j] != 0)
            {
                printf("%2d", a[j]);
            }
            else
            {
                break;
            }
        }
        for (m = 0; m < 21 - 2 * j; m++)
        {
            printf(" ");
        }
        printf("B:");
        for (j = 0; j < 10; j++)
        {
            if (b[j] != 0)
            {
                printf("%2d", b[j]);
            }
            else
            {
                break;
            }
        }
        for (m = 0; m < 21 - 2 * j; m++)
        {
            printf(" ");
        }
        printf("C:");
        for (j = 0; j < 10; j++)
        {
            if (c[j] != 0)
            {
                printf("%2d", c[j]);
            }
            else
            {
                break;
            }
        }
        for (m = 0; m < 21 - 2 * j; m++)
        {
            printf(" ");
        }
        printf("\n");
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    i++;
    printf("第%4d 步(%2d): %c-->%c ", i, n, src, dst);
    if (src == 'A' && dst == 'B')
    {
        a[--a_top] = 0;
        b[b_top++] = n;
    }
    else if (src == 'A' && dst == 'C')
    {
        a[--a_top] = 0;
        c[c_top++] = n;
    }
    else if (src == 'B' && dst == 'A')
    {
        b[--b_top] = 0;
        a[a_top++] = n;
    }
    else if (src == 'B' && dst == 'C')
    {
        b[--b_top] = 0;
        c[c_top++] = n;
    }
    else if (src == 'C' && dst == 'A')
    {
        c[--c_top] = 0;
        a[a_top++] = n;
    }
    else if (src == 'C' && dst == 'B')
    {
        c[--c_top] = 0;
        b[b_top++] = n;
    }
    printf("A:");
    for (j = 0; j < 10; j++)
    {
        if (a[j] != 0)
        {
            printf("%2d", a[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("B:");
    for (j = 0; j < 10; j++)
    {
        if (b[j] != 0)
        {
            printf("%2d", b[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("C:");
    for (j = 0; j < 10; j++)
    {
        if (c[j] != 0)
        {
            printf("%2d", c[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("\n");
    hanoi(n - 1, tmp, src, dst);
    return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int m,n,j, ret = 0;
    char src=0, tmp = 0, dst=0;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret = scanf("%d", &n);
        if (ret == 0)
        {
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            continue;
        }
        if (1 <= n && n <= 10)
        {
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            break;
        }
        else
        {
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            continue;
        }
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        if (src == 'a' || src == 'A')
        {
            src = 'A';
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            break;
        }
        else if (src == 'b' || src == 'B')
        {
            src = 'B';
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            break;
        }
        else if (src == 'c' || src == 'C')
        {
            src = 'C';
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            break;
        }
        else
        {
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            continue;
        }
    }
    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        if (dst == 'a' || dst == 'A')
        {
            dst = 'A';
        }
        else if (dst == 'b' || dst == 'B')
        {
            dst = 'B';
        }
        else if (dst == 'c' || dst == 'C')
        {
            dst = 'C';
        }
        else
        {
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            continue;
        }
        if (dst == src)
        {
            printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            while (getchar() != '\n')// 清除输入缓冲区中的多余内容
                ;
            continue;
        }
        else
        {
            break;
        }
    }
    tmp = 65 + 66 + 67 - dst - src;
    if (src == 'A')
    {
        for (j = 0; j < n; j++)
        {
            a[j] = n - j;
        }
        a_top = n;
    }
    else if (src == 'B')
    {
        for (j = 0; j < n; j++)
        {
            b[j] = n - j;
        }
        b_top = n;
    }
    else if (src == 'C')
    {
        for (j = 0; j < n; j++)
        {
            c[j] = n - j;
        }
        c_top = n;
    }
    printf("初始:                A:");
    for (j = 0; j < 10; j++)
    {
        if (a[j] != 0)
        {
            printf("%2d", a[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("B:");
    for (j = 0; j < 10; j++)
    {
        if (b[j] != 0)
        {
            printf("%2d", b[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("C:");
    for (j = 0; j < 10; j++)
    {
        if (c[j] != 0)
        {
            printf("%2d", c[j]);
        }
        else
        {
            break;
        }
    }
    for (m = 0; m < 21 - 2 * j; m++)
    {
        printf(" ");
    }
    printf("\n");
    hanoi(n, src, tmp, dst);
    return 0;
}

