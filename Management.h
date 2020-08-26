#ifndef _Management_System
#define _Management_System
#include<iostream>
#include<string>
#include<stdlib.h>

#define MAX 1000

using namespace std;


struct Person
{
	string name;
	int sex;
	int age;
	string telephone;
	string address;
};

//ͨ��¼�Ľṹ�壬�����ṹ��Person����Ŀ
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};

void showMenu()
{
	cout << "*********************" << endl;
	cout << "****1�������ϵ��****" << endl;
	cout << "****2����ʾ��ϵ��****" << endl;
	cout << "****3��ɾ����ϵ��****" << endl;
	cout << "****4��������ϵ��****" << endl;
	cout << "****5���޸���ϵ��****" << endl;
	cout << "****6�������ϵ��****" << endl;
	cout << "****7���˳�ͨѶ¼****" << endl;
	cout << "*********************" << endl;
}

//�����ϵ��
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷��������" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������:";
		cin >> name;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].name = name;

		int sex;
		cout << "�������Ա�(1:�У�0:Ů):";
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[abs->m_size].sex = sex;
				break;
			}
			cout << "�����������������(1:�У�0:Ů):";
		}

		int age;
		cout << "******************************************" << endl;
		cout << "����������:";
		cin >> age;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].age = age;

		string tele;
		cout << "������绰:";
		cin >> tele;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].address = tele;

		string address;
		cout << "������סַ:";
		cin >> address;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].address = address;

		cout << "������" << endl;
		abs->m_size++;
	}
}


//��ʾ��ϵ��
void Show_person_exist(struct Person per)
{
	cout << "����:" << per.name << "\t";
	if (per.sex == 0)
		cout << "�Ա�:" << "Ů" << "\t";
	else
		cout << "�Ա�:" << "��" << "\t";
	cout << "�Ա�:" << per.sex << "\t";
	cout << "����:" << per.age << "\t";
	cout << "�绰:" << per.telephone << "\t";
	cout << "��ַ:" << per.address << "\t";
	cout << endl;
}

void showPerson(struct Addressbooks* abs)
{
	if (abs->m_size == 0) {
		cout << "ͨ��¼��û���ˣ�����" << endl;
		cout << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_size; i++)
			Show_person_exist(abs->personArray[i]);
	}
}

//Ѱ����ϵ��
int findPerson(struct Addressbooks* abs)
{
	string per;
	cout << "������Ҫ ����/ɾ��/�޸� ����ϵ��:";    cin >> per;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].name == per)
			return i;
	}
	return -1;
}

void deletPerson(struct Addressbooks* abs)
{
	int Posi = findPerson(abs);
	if (Posi != -1)
	{
		for (int i = Posi; i < abs->m_size - 1; i++) {
			//����ǰ�ƣ�������������ٶ���
			abs->personArray[Posi] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
}

//�޸���ϵ��
void modifyPerson(struct Addressbooks* abs)
{
	int Posi = findPerson(abs);
	if (Posi == -1)
	{
		cout << "���޴��ˣ��������" << endl;
		return;
	}
	else 
	{
		string name;
		cout << "����������:";
		cin >> name;
		cout << "******************************************" << endl;
		abs->personArray[Posi].name = name;

		int sex;
		cout << "�������Ա�(1:�У�0:Ů):";
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[Posi].sex = sex;
				break;
			}
			cout << "�����������������(1:�У�0:Ů):";
		}

		int age;
		cout << "******************************************" << endl;
		cout << "����������:";
		cin >> age;
		cout << "******************************************" << endl;
		abs->personArray[Posi].age = age;

		string tele;
		cout << "������绰:";
		cin >> tele;
		cout << "******************************************" << endl;
		abs->personArray[Posi].address = tele;

		string address;
		cout << "������סַ:";
		cin >> address;
		cout << "******************************************" << endl;
		abs->personArray[Posi].address = address;
	}
}

//�����ϵ��
void clearPerson(struct Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
}




#endif 
