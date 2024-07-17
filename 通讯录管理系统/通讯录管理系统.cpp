#include<iostream>
#include<string>
using namespace std;
#define Max 1000

// �����ϵ�˽ṹ��
struct Contact{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_phoneNumber;
	string m_Address;
};

// ���ͨѶ¼�ṹ�� 
struct Addressbook{
	struct Contact ContactArray[Max];
	int Size; //ͨѶ¼���� 
}; 

// ��ʾ�˵� 
void showMenu(){
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
} 
// �����ϵ��
void addContact (Addressbook * abs){
	if(abs->Size == Max){
		cout << "ͨѶ¼�������޷����" << endl; 
		return;
	}else{
		// ���� 
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->ContactArray[abs->Size].m_Name = name;
		// �Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while(true){
			cin >> sex; 
			if(sex == 1 || sex == 2){
				abs->ContactArray[abs->Size].m_Sex = sex;
				break;
			}else{
				cout << "�����Ա���Ч������������" << endl;
			}
		}
		// ���� 
		int age = 0; 
		cout << "��������ϵ�����䣺 " << endl;
		while(true){
			cin >> age; 
			if(age >= 0){
				abs->ContactArray[abs->Size].m_Age = age;
				break;
			}else{
				cout << "����������Ч������������" << endl;
			}
		}
		// ��ϵ�绰
		string phoneNumber;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phoneNumber;
		abs->ContactArray[abs->Size].m_phoneNumber = phoneNumber;
		// סַ
		string address; 
		cout << "��������ϵ��סַ��" << endl; 
		cin >> address;
		abs->ContactArray[abs->Size].m_Address = address;
		// ����ͨѶ¼���� 
		abs->Size ++;
		cout << "��ӳɹ���" << endl; 
		system("pause");
		system("cls");
	}
}

// ��ʾ��ϵ��
void showContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "ͨѶ¼��" << endl; 
	}else{
		for (int i = 0; i < abs->Size ; i++){
			cout << "������" << abs->ContactArray[i].m_Name << "     ";
			cout << "�Ա�" << (abs->ContactArray[i].m_Sex == 1?"��":"Ů") << "     ";
			cout << "���䣺" << abs->ContactArray[i].m_Age << "     ";
			cout << "�绰��" << abs->ContactArray[i].m_phoneNumber << "     ";
			cout << "סַ��" << abs->ContactArray[i].m_Address << endl;
		}
	} 
	system("pause");
	system("cls");
} 

// �����ϵ���Ƿ����
int isExist(Addressbook *abs, string name){
	if(abs->Size == 0){
		cout << "ͨѶ¼��" << endl;
		return -2;
	}
	for(int i = 0 ; i < abs->Size ; i++){
		if(abs->ContactArray[i].m_Name == name){
			return i;
		}
	}
	return -1;
} 
 
// ɾ����ϵ�� 
void deleteContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "ͨѶ¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "���޴���" << endl;
	}else{
		for(int i = ret ; i < abs->Size ; i++){
			abs->ContactArray[i] = abs->ContactArray[i+1];
		}
		abs->Size -- ;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

// ������ϵ��
void findContact(Addressbook * abs) {
	if(abs->Size == 0){
		cout << "ͨѶ¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "���޴���" << endl;
	}else{
		cout << "������" << abs->ContactArray[ret].m_Name << "     ";
		cout << "�Ա�" << (abs->ContactArray[ret].m_Sex == 1?"��":"Ů") << "     ";
		cout << "���䣺" << abs->ContactArray[ret].m_Age << "     ";
		cout << "�绰��" << abs->ContactArray[ret].m_phoneNumber << "     ";
		cout << "סַ��" << abs->ContactArray[ret].m_Address << endl;
	}
	system("pause");
	system("cls");
}

// �޸���ϵ��
void modifyContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "ͨѶ¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "���޴���" << endl;
	}else{
		// ���� 
		string name;
		cout << "��������ϵ��������" <<endl;
		cin >> name;
		abs->ContactArray[ret].m_Name = name;
		// �Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while(true){
			cin >> sex; 
			if(sex == 1 || sex == 2){
				abs->ContactArray[ret].m_Sex = sex;
				break;
			}else{
				cout << "�����Ա���Ч������������" << endl;
			}
		}
		// ���� 
		int age = 0; 
		cout << "��������ϵ�����䣺 " << endl;
		while(true){
			cin >> age; 
			if(age >= 0){
				abs->ContactArray[abs->Size].m_Age = age;
				break;
			}else{
				cout << "����������Ч������������" << endl;
			}
		}
		// ��ϵ�绰
		string phoneNumber;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phoneNumber;
		abs->ContactArray[ret].m_phoneNumber = phoneNumber;
		// סַ
		string address; 
		cout << "��������ϵ��סַ��" << endl; 
		cin >> address;
		abs->ContactArray[ret].m_Address = address;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

// �����ϵ��
void emptyContact(Addressbook * abs){
	abs->Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
} 

int main(){
	Addressbook abs;
	abs.Size = 0;			// ��ʼ��ͨѶ¼ 
	int select = 0;
	while(true){
		showMenu();			// �˵����� 
		cin >> select;
		switch(select){
			case 1:         // �����ϵ��
				addContact(&abs);
				break;
			case 2:			// ��ʾ��ϵ��
				showContact(&abs);
				break;
			case 3:			// ɾ����ϵ��
				deleteContact(&abs);
				break;
			case 4:			// ������ϵ��
				findContact(&abs);
				break;	
			case 5:			// �޸���ϵ��
				modifyContact(&abs);
				break;
			case 6:			// �����ϵ��
				emptyContact(&abs);
				break;
			case 0:			// �˳�ͨѶ¼ 
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0; 
				break;
			default:
				cout<< "������Ч" << endl; 
				system("pause");
				system("cls");
		}
	}
	system("pause");
	return 0;
}
