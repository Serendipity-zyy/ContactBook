#include<iostream>
#include<string>
using namespace std;
const int Max = 1e3;
//联系人结构体
struct Person {
	string m_Name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};

//通讯录结构体
struct AddressBooks {
	Person personArray[Max];
	int m_Size;
};

//添加联系人
void addPerson(AddressBooks* abs) {
	//判断通讯录是否已满
	if (abs->m_Size == Max) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		//添加联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "您输入的性别有误，请重新输入" << endl;
			}
		}

		int age=0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//更新通讯录中的人数
		cout << "添加成功" << endl;

		system("pause");
		system("cls");//清屏操作
	}
}

//显示联系人
void showPerson(AddressBooks* abs) {
	//判断通讯录中的人数是否为0
	if (abs->m_Size == 0) {
		cout << "通讯录中暂无联系人" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name <<"\t"
				<< "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" << abs->personArray[i].m_Age <<"\t"
				<< "联系方式：" << abs->personArray[i].m_Phone <<"\t" 
				<< "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检查联系人是否存在,如果存在，返回索引
int isExist(AddressBooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(AddressBooks* abs) {
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
			
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(AddressBooks* abs) {
	cout << "请输入您要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t"
			<< "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t"
			<< "年龄：" << abs->personArray[ret].m_Age << "\t"
			<< "联系方式：" << abs->personArray[ret].m_Phone << "\t"
			<< "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(AddressBooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "请输入姓名：" << endl;
		
		cin>>abs->personArray[ret].m_Name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "您输入的性别有误，请重新输入" << endl;
			}
		}

		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功！" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人;
void cleanPerson(AddressBooks* abs) {
	cout << "您确定要清空联系人吗（yes/no）" << endl;
	string option;
	while (true) {
		cin >> option;
		if (option == "yes"||option=="YES"||option=="Yes") {
			break;
		}
		else if (option == "no"||option=="NO"||option=="No") {
			cout << "已取消清空联系人操作" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "您的输入有误，请重新输入" << endl;
		}
	}
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls");
}

//显示菜单界面
void showMenu() {
	cout << "******************************" << endl;
	cout << "******* 1、添加联系人 ********" << endl;
	cout << "******* 2、显示联系人 ********" << endl;
	cout << "******* 3、删除联系人 ********" << endl;
	cout << "******* 4、查找联系人 ********" << endl;
	cout << "******* 5、修改联系人 ********" << endl;
	cout << "******* 6、清空联系人 ********" << endl;
	cout << "******* 0、退出通讯录 ********" << endl;
	cout << "******************************" << endl;
}

int main() {
	AddressBooks abs;//创建联系人通讯录
	abs.m_Size = 0;//初始化通讯录中的人员个数

	int select = -1;//用户选择

	while (true) {
		//菜单调用
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "已退出通讯录，欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "选择有误，请重新输入" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}