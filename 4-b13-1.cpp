/* 2350233 Ҷ�� ��21 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

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
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        i++;
        cout << setw(5) << i << ":" << setw(3) << n << "#" << " " << src << "-->" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    i++;
    cout << setw(5) << i << ":" <<setw(3) << n << "#" << " " << src << "-->" << dst << endl;
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
    int n;
    char src, tmp = 0, dst;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        if (1 <= n && n <= 16)
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (src == 'a' || src == 'A')
        {
            src = 'A';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else if (src == 'b' || src == 'B')
        {
            src = 'B';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else if (src == 'c' || src == 'C')
        {
            src = 'C';
            cin.clear();
            cin.ignore(10000000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
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
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        if (dst == src)
        {
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        else
        {
            break;
        }
    }
    tmp = 65 + 66 + 67 - dst - src;
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}
