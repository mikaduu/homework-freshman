/* 2350233 Ҷ�� ��21 */
#include <iostream>
#include <iomanip>
using namespace std;

int i = 0;//������
int column[3][10] = { {0},{0},{0} };//0,1,2�ֱ��ӦA,B,C��
int top[3] = {0};

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
    int j = 0, m = 0;
    if (n == 1)
    {
        i++;
        cout <<"��"<< setw(4)<< i<<" ��" <<"(" << setw(2) << n << ")"<< ": " << src << "-->" << dst << " " ;
        if (src == 'A' && dst == 'B')
        {
            column[0][--top[0]] = 0;
            column[1][top[1]++] = n;
        }
        else if (src == 'A' && dst == 'C')
        {
            column[0][--top[0]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'B' && dst == 'A')
        {
            column[1][--top[1]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'B' && dst == 'C')
        {
            column[1][--top[1]] = 0;
            column[2][top[2]++] = n;
        }
        else if (src == 'C' && dst == 'A')
        {
            column[2][--top[2]] = 0;
            column[0][top[0]++] = n;
        }
        else if (src == 'C' && dst == 'B')
        {
            column[2][--top[2]] = 0;
            column[1][top[1]++] = n;
        }
        cout << "A:";
        for (j = 0; j < 10; j++)
        {
            if (column[0][j] != 0)
            {
                cout << setw(2) << column[0][j];
            }
            else
            {
                break;
            }
        }
        cout << setw(21 - 2 * j) << " ";
        cout << "B:";
        for (j = 0; j < 10; j++)
        {
            if (column[1][j] != 0)
            {
                cout << setw(2) << column[1][j];
            }
            else
            {
                break;
            }
        }
        cout << setw(21 - 2 * j) << " ";
        cout << "C:";
        for (j = 0; j < 10; j++)
        {
            if (column[2][j] != 0)
            {
                cout << setw(2) << column[2][j];
            }
            else
            {
                break;
            }
        }
        cout << setw(21 - 2 * j) << " ";
        cout << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    i++;
    cout << "��" << setw(4) << i << " ��" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
    if (src == 'A' && dst == 'B')
    {
        column[0][--top[0]] = 0;
        column[1][top[1]++] = n;
    }
    else if (src == 'A' && dst == 'C')
    {
        column[0][--top[0]] = 0;
        column[2][top[2]++] = n;
    }
    else if (src == 'B' && dst == 'A')
    {
        column[1][--top[1]] = 0;
        column[0][top[0]++] = n;
    }
    else if (src == 'B' && dst == 'C')
    {
        column[1][--top[1]] = 0;
        column[2][top[2]++] = n;
    }
    else if (src == 'C' && dst == 'A')
    {
        column[2][--top[2]] = 0;
        column[0][top[0]++] = n;
    }
    else if (src == 'C' && dst == 'B')
    {
        column[2][--top[2]] = 0;
        column[1][top[1]++] = n;;
    }
    cout << "A:";
    for (j = 0; j < 10; j++)
    {
        if (column[0][j] != 0)
        {
            cout << setw(2) << column[0][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout << "B:";
    for (j = 0; j < 10; j++)
    {
        if (column[1][j] != 0)
        {
            cout << setw(2) << column[1][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout << "C:";
    for (j = 0; j < 10; j++)
    {
        if (column[2][j] != 0)
        {
            cout << setw(2) << column[2][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout << endl;
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
{   int n,j;
    char src, tmp, dst;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear(); 
            cin.ignore(10000000, '\n');
            continue;
        }
        if (1 <= n && n <= 10)
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
    if (src == 'A')
    {
        for (j = 0; j < n; j++)
        {
            column[0][j] = n - j;
        }
        top[0] = n;
    }
    else if (src == 'B')
    {
        for (j = 0; j < n; j++)
        {
            column[1][j] = n - j;
        }
        top[1] = n;
    }
    else if (src == 'C')
    {
        for (j = 0; j < n; j++)
        {
            column[2][j] = n - j;
        }
        top[2] = n;
    }
    cout << "��ʼ:";
    cout << setw(16) << " ";
    cout<< "A:";
    for (j = 0; j < 10; j++)
    {
        if (column[0][j] != 0)
        {
            cout<<setw(2)<< column[0][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout<<"B:";
    for (j = 0; j < 10; j++)
    {
        if (column[1][j] != 0)
        {
            cout << setw(2) << column[1][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout<<"C:";
    for (j = 0; j < 10; j++)
    {
        if (column[2][j] != 0)
        {
            cout << setw(2) << column[2][j];
        }
        else
        {
            break;
        }
    }
    cout << setw(21 - 2 * j) << " ";
    cout<<endl;
    hanoi(n, src, tmp, dst);
    return 0;
}

