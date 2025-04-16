#include<iostream>
#include<string>
using namespace std;
const int Max = 1e3;
//��ϵ�˽ṹ��
struct Person {
	string m_Name;//����
	int m_Sex;//�Ա�
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};

//ͨѶ¼�ṹ��
struct AddressBooks {
	Person personArray[Max];
	int m_Size;
};

//�����ϵ��
void addPerson(AddressBooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == Max) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		//�����ϵ��
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "��������Ա���������������" << endl;
			}
		}

		int age=0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//����ͨѶ¼�е�����
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");//��������
	}
}

//��ʾ��ϵ��
void showPerson(AddressBooks* abs) {
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼��������ϵ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name <<"\t"
				<< "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" << abs->personArray[i].m_Age <<"\t"
				<< "��ϵ��ʽ��" << abs->personArray[i].m_Phone <<"\t" 
				<< "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����,������ڣ���������
int isExist(AddressBooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(AddressBooks* abs) {
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
			
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(AddressBooks* abs) {
	cout << "��������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t"
			<< "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺" << abs->personArray[ret].m_Age << "\t"
			<< "��ϵ��ʽ��" << abs->personArray[ret].m_Phone << "\t"
			<< "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(AddressBooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "������������" << endl;
		
		cin>>abs->personArray[ret].m_Name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "��������Ա���������������" << endl;
			}
		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ���" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��;
void cleanPerson(AddressBooks* abs) {
	cout << "��ȷ��Ҫ�����ϵ����yes/no��" << endl;
	string option;
	while (true) {
		cin >> option;
		if (option == "yes"||option=="YES"||option=="Yes") {
			break;
		}
		else if (option == "no"||option=="NO"||option=="No") {
			cout << "��ȡ�������ϵ�˲���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "����������������������" << endl;
		}
	}
	abs->m_Size = 0;
	cout << "��ϵ�������" << endl;
	system("pause");
	system("cls");
}

//��ʾ�˵�����
void showMenu() {
	cout << "******************************" << endl;
	cout << "******* 1�������ϵ�� ********" << endl;
	cout << "******* 2����ʾ��ϵ�� ********" << endl;
	cout << "******* 3��ɾ����ϵ�� ********" << endl;
	cout << "******* 4��������ϵ�� ********" << endl;
	cout << "******* 5���޸���ϵ�� ********" << endl;
	cout << "******* 6�������ϵ�� ********" << endl;
	cout << "******* 0���˳�ͨѶ¼ ********" << endl;
	cout << "******************************" << endl;
}

int main() {
	AddressBooks abs;//������ϵ��ͨѶ¼
	abs.m_Size = 0;//��ʼ��ͨѶ¼�е���Ա����

	int select = -1;//�û�ѡ��

	while (true) {
		//�˵�����
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "���˳�ͨѶ¼����ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "ѡ����������������" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}