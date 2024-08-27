/* 2350233	Ҷ��	��21 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	char round1[MAX_NAME_LEN];//��һ�ֵı�ʶ
	char round2[MAX_NAME_LEN];//�ڶ��ֵı�ʶ
	friend class stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void hebin();
	void paixu();
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::hebin()
{
	int i,j,chongfu,k,m;
	for (k=0,i = 0; i<list_num_1; i++)//ѭ���ϲ���һ���ļ����޳��ظ�
	{
		chongfu = 0;
		for (j = 0; j < k; j++)
		{
			if (list_round_1[i].no == list_merge[j].stu_no)
			{
				chongfu = 1;
				break;
			}
		}
		if (chongfu == 0)
		{
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			strcpy(list_merge[k].round1,"Y");
			k++;
		}
	}
	for (i = 0; i<list_num_2 && k < MAX_STU_NUM; i++)//ѭ���ϲ��ڶ����ļ����޳��ظ�(Ҫ�����ڵڶ����ļ��б����ظ������)
	{
		chongfu = 0;
		for (m = 0; m < i; m++)
		{
			if (list_round_2[i].no == list_round_2[m].no)
			{
				chongfu = 1;
				break;
			}
		}
		if (chongfu == 0)
		{
			for (j = 0; j < k; j++)
			{
				if (list_round_2[i].no == list_merge[j].stu_no)
				{
					chongfu = 1;
					strcpy(list_merge[j].round2, "Y");
					break;
				}
			}
		}
		if (chongfu == 0)
		{
			list_merge[k].stu_no = list_round_2[i].no;
			strcpy(list_merge[k].stu_name, list_round_2[i].name);
			strcpy(list_merge[k].round1, "/");
			strcpy(list_merge[k].round2, "��ѡ");
			k++;
		}
	}
	list_merge_num = k;
	for (i = 0; i < list_merge_num; i++)//����ڶ����˿�
	{
		chongfu = 0;
		for (j = 0; j < list_num_2; j++)
		{
			if (list_merge[i].stu_no == list_round_2[j].no)
			{
				chongfu = 1;
				break;
			}
		}
		if (chongfu == 0)
		{
			strcpy(list_merge[i].round2, "�˿�");
		}
	}
}

void stu_list::paixu()
{
	stu_merge middle;
	int i,j,k;
	for (i = 0; i < list_merge_num - 1; i++)
	{
		k = i;
		for (j = i + 1; j < list_merge_num; j++)
		{
			if (list_merge[k].stu_no > list_merge[j].stu_no)
			{
				k = j;
			}
		}
		middle = list_merge[i];
		list_merge[i] = list_merge[k];
		list_merge[k] = middle;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	int i;
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (i = 1; i<=list_merge_num; i++)
	{
		cout << setw(5) << setiosflags(ios::left) << i << setw(9) << list_merge[i - 1].stu_no << setw(32) << list_merge[i - 1].stu_name << setw(7) << list_merge[i - 1].round1 << list_merge[i - 1].round2 << endl;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);
	
	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.hebin();
	list.paixu();
	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}
