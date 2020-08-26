#include"Management.h"

int main()
{
	//初始化通讯录变量
	Addressbooks abs;
	abs.m_size = 0;

	while (true)
	{
		showMenu();
		int select;
		cout << endl << "请输入功能选择:";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "***************************************" << endl;
			cout << "          激活功能：添加联系人           " << endl;
			cout << "***************************************" << endl;
			addPerson(&abs);
			system("pause");
			system("cls");//清屏
			break;
		case 2:
			cout << "***************************************" << endl;
			cout << "          激活功能：显示联系人           " << endl;
			cout << "***************************************" << endl;
			showPerson(&abs);
			system("pause");
			system("cls");//清屏
			break;
		case 3:
		{
			string delet_name;
			cout << "***************************************" << endl;
			cout << "           激活功能：删除联系人          " << endl;
			cout << "***************************************" << endl;
			deletPerson(&abs);
			system("pause");
			system("cls");//清屏
			break;
		}
		case 4:
		{
			string find_name;
			cout << "***************************************" << endl;
			cout << "           激活功能：查找联系人          " << endl;
			cout << "***************************************" << endl;
			int Posi = findPerson(&abs);
			if (Posi == -1)
				cout << "查无此人,查找操作失败" << endl << endl;
			else
				Show_person_exist(abs.personArray[Posi]);
			system("pause");
			system("cls");//清屏
			break;
		}
		case 5:
			cout << "***************************************" << endl;
			cout << "           激活功能：修改联系人          " << endl;
			cout << "***************************************" << endl;
			modifyPerson(&abs);
			system("pause");
			system("cls");//清屏
			break;
		case 6:
			cout << "***************************************" << endl;
			cout << "            激活功能：清空联系人         " << endl;
			cout << "***************************************" << endl;
			clearPerson(&abs);
			system("pause");
			system("cls");//清屏
			break;
		case 7:
			cout << "***************************************" << endl;
			cout << "            激活功能：退出通信录         " << endl;
			cout << "***************************************" << endl;
			system("pause");
			exit(0);  //退出系统
			break;
		default:
			cout << "功能输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}

