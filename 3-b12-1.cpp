/*��21 2350233	Ҷ��*/
#include <iostream>
#include <limits> // ͨ����ѯ������limitsͷ�ļ�������������뻺��������cin.xx�ĳ�Ա������ʽ��
using namespace std;

int main()
{
	int x;

	while (1) 
	{	
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		/*if (cin.rdbuf()->in_avail() != 0)
		{
			cin.clear(); // ������뻺����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е���������
			continue;
		}*/  //�˲������ڽ������78abc����ǰ�����Ч�����ڷ�Χ�ڣ����зǷ���������
		


		if (!cin.good()) // ��������Ƿ�ʧ��
		{ 
			cin.clear(); // ������뻺����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е���������
			continue;
		}
		
		if (x >= 0 && x <= 100)
			break;
		/*else
		{
			cin.clear(); // ������뻺����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е���������
			continue;
		}*/ //�˲���Ϊ����������123abc����ǰ�����Ч���ֳ��ޣ�����Ϊ�Ƿ����뵼�µ�������Ρ�������x��ֵ[0-100] :��
		
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}



