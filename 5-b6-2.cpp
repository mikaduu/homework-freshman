/* 2350233 叶辰 信21 */
#include <iostream>
#include <iomanip>
using namespace std;

int i = 0;//计数器
int column[3][10] = { {0},{0},{0} };//0,1,2分别对应A,B,C柱
int top[3] = {0};

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
    int j = 0, m = 0;
    if (n == 1)
    {
        i++;
        cout <<"第"<< setw(4)<< i<<" 步" <<"(" << setw(2) << n << ")"<< ": " << src << "-->" << dst << " " ;
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
    cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{   int n,j;
    char src, tmp, dst;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
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
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)" << endl;
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
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
    cout << "初始:";
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

