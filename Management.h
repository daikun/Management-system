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

//通信录的结构体，包含结构体Person的数目
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};

void showMenu()
{
	cout << "*********************" << endl;
	cout << "****1、添加联系人****" << endl;
	cout << "****2、显示联系人****" << endl;
	cout << "****3、删除联系人****" << endl;
	cout << "****4、查找联系人****" << endl;
	cout << "****5、修改联系人****" << endl;
	cout << "****6、清空联系人****" << endl;
	cout << "****7、退出通讯录****" << endl;
	cout << "*********************" << endl;
}

//添加联系人
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法继续添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名:";
		cin >> name;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].name = name;

		int sex;
		cout << "请输入性别(1:男，0:女):";
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[abs->m_size].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入(1:男，0:女):";
		}

		int age;
		cout << "******************************************" << endl;
		cout << "请输入年龄:";
		cin >> age;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].age = age;

		string tele;
		cout << "请输入电话:";
		cin >> tele;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].address = tele;

		string address;
		cout << "请输入住址:";
		cin >> address;
		cout << "******************************************" << endl;
		abs->personArray[abs->m_size].address = address;

		cout << "添加完成" << endl;
		abs->m_size++;
	}
}


//显示联系人
void Show_person_exist(struct Person per)
{
	cout << "姓名:" << per.name << "\t";
	if (per.sex == 0)
		cout << "性别:" << "女" << "\t";
	else
		cout << "性别:" << "男" << "\t";
	cout << "性别:" << per.sex << "\t";
	cout << "年龄:" << per.age << "\t";
	cout << "电话:" << per.telephone << "\t";
	cout << "地址:" << per.address << "\t";
	cout << endl;
}

void showPerson(struct Addressbooks* abs)
{
	if (abs->m_size == 0) {
		cout << "通信录中没有人，错误！" << endl;
		cout << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_size; i++)
			Show_person_exist(abs->personArray[i]);
	}
}

//寻找联系人
int findPerson(struct Addressbooks* abs)
{
	string per;
	cout << "请输入要 查找/删除/修改 的联系人:";    cin >> per;
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
			//数据前移，相比链表，运行速度慢
			abs->personArray[Posi] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
}

//修改联系人
void modifyPerson(struct Addressbooks* abs)
{
	int Posi = findPerson(abs);
	if (Posi == -1)
	{
		cout << "查无此人，输入错误！" << endl;
		return;
	}
	else 
	{
		string name;
		cout << "请输入姓名:";
		cin >> name;
		cout << "******************************************" << endl;
		abs->personArray[Posi].name = name;

		int sex;
		cout << "请输入性别(1:男，0:女):";
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[Posi].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入(1:男，0:女):";
		}

		int age;
		cout << "******************************************" << endl;
		cout << "请输入年龄:";
		cin >> age;
		cout << "******************************************" << endl;
		abs->personArray[Posi].age = age;

		string tele;
		cout << "请输入电话:";
		cin >> tele;
		cout << "******************************************" << endl;
		abs->personArray[Posi].address = tele;

		string address;
		cout << "请输入住址:";
		cin >> address;
		cout << "******************************************" << endl;
		abs->personArray[Posi].address = address;
	}
}

//清空联系人
void clearPerson(struct Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
}




#endif 
