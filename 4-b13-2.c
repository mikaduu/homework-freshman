/* 2350233 Ҷ�� ��21 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */
int i=0;

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
    
    if (n == 1)
    {
        i++;
        printf("%5d:%3d# %c-->%c\n",i,n,src,dst);
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    i++;
    printf("%5d:%3d# %c-->%c\n", i, n, src, dst);
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
    int n,ret=0;
    char src, tmp = 0, dst;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret=scanf("%d", &n);
        if (ret == 0)
        {
            while (getchar() != '\n')// ������뻺�����еĶ�������
                ;
            continue;
        }
        if (1 <= n && n <= 16)
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
        ret=scanf("%c",&src);
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
        ret=scanf("%c", &dst);
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
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n",dst,src);
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);
    return 0;
}

