/* 2350233 Ҷ�� ��21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int i = 0;//������
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//a,b,c�ֱ��ӦA,B,C��
int a_top=0, b_top=0, c_top=0;

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int j=0,m=0;
    if (n == 1)
    {
        i++;
        printf("��%4d ��(%2d): %c-->%c ", i, n, src, dst);
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
    printf("��%4d ��(%2d): %c-->%c ", i, n, src, dst);
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int m,n,j, ret = 0;
    char src=0, tmp = 0, dst=0;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        ret = scanf("%d", &n);
        if (ret == 0)
        {
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            continue;
        }
        if (1 <= n && n <= 10)
        {
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            break;
        }
        else
        {
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            continue;
        }
    }
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &src);
        if (src == 'a' || src == 'A')
        {
            src = 'A';
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            break;
        }
        else if (src == 'b' || src == 'B')
        {
            src = 'B';
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            break;
        }
        else if (src == 'c' || src == 'C')
        {
            src = 'C';
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            break;
        }
        else
        {
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            continue;
        }
    }
    while (1)
    {
        printf("������Ŀ����(A-C)\n");
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
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            continue;
        }
        if (dst == src)
        {
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
            while (getchar() != '\n')// ������뻺�����еĶ�������
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
    printf("��ʼ:                A:");
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

