#include<iostream>
#include<string>
using namespace std;
#define Max 1000

// 设计联系人结构体
struct Contact{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_phoneNumber;
	string m_Address;
};

// 设计通讯录结构体 
struct Addressbook{
	struct Contact ContactArray[Max];
	int Size; //通讯录人数 
}; 

// 显示菜单 
void showMenu(){
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
} 
// 添加联系人
void addContact (Addressbook * abs){
	if(abs->Size == Max){
		cout << "通讯录已满，无法添加" << endl; 
		return;
	}else{
		// 姓名 
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->ContactArray[abs->Size].m_Name = name;
		// 性别
		cout << "请输入联系人性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while(true){
			cin >> sex; 
			if(sex == 1 || sex == 2){
				abs->ContactArray[abs->Size].m_Sex = sex;
				break;
			}else{
				cout << "输入性别无效，请重新输入" << endl;
			}
		}
		// 年龄 
		int age = 0; 
		cout << "请输入联系人年龄： " << endl;
		while(true){
			cin >> age; 
			if(age >= 0){
				abs->ContactArray[abs->Size].m_Age = age;
				break;
			}else{
				cout << "输入年龄无效，请重新输入" << endl;
			}
		}
		// 联系电话
		string phoneNumber;
		cout << "请输入联系人电话：" << endl;
		cin >> phoneNumber;
		abs->ContactArray[abs->Size].m_phoneNumber = phoneNumber;
		// 住址
		string address; 
		cout << "请输入联系人住址：" << endl; 
		cin >> address;
		abs->ContactArray[abs->Size].m_Address = address;
		// 更新通讯录人数 
		abs->Size ++;
		cout << "添加成功！" << endl; 
		system("pause");
		system("cls");
	}
}

// 显示联系人
void showContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "通讯录空" << endl; 
	}else{
		for (int i = 0; i < abs->Size ; i++){
			cout << "姓名：" << abs->ContactArray[i].m_Name << "     ";
			cout << "性别：" << (abs->ContactArray[i].m_Sex == 1?"男":"女") << "     ";
			cout << "年龄：" << abs->ContactArray[i].m_Age << "     ";
			cout << "电话：" << abs->ContactArray[i].m_phoneNumber << "     ";
			cout << "住址：" << abs->ContactArray[i].m_Address << endl;
		}
	} 
	system("pause");
	system("cls");
} 

// 检测联系人是否存在
int isExist(Addressbook *abs, string name){
	if(abs->Size == 0){
		cout << "通讯录空" << endl;
		return -2;
	}
	for(int i = 0 ; i < abs->Size ; i++){
		if(abs->ContactArray[i].m_Name == name){
			return i;
		}
	}
	return -1;
} 
 
// 删除联系人 
void deleteContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "通讯录空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "查无此人" << endl;
	}else{
		for(int i = ret ; i < abs->Size ; i++){
			abs->ContactArray[i] = abs->ContactArray[i+1];
		}
		abs->Size -- ;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

// 查找联系人
void findContact(Addressbook * abs) {
	if(abs->Size == 0){
		cout << "通讯录空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "查无此人" << endl;
	}else{
		cout << "姓名：" << abs->ContactArray[ret].m_Name << "     ";
		cout << "性别：" << (abs->ContactArray[ret].m_Sex == 1?"男":"女") << "     ";
		cout << "年龄：" << abs->ContactArray[ret].m_Age << "     ";
		cout << "电话：" << abs->ContactArray[ret].m_phoneNumber << "     ";
		cout << "住址：" << abs->ContactArray[ret].m_Address << endl;
	}
	system("pause");
	system("cls");
}

// 修改联系人
void modifyContact(Addressbook * abs){
	if(abs->Size == 0){
		cout << "通讯录空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1){
		cout << "查无此人" << endl;
	}else{
		// 姓名 
		string name;
		cout << "请输入联系人姓名：" <<endl;
		cin >> name;
		abs->ContactArray[ret].m_Name = name;
		// 性别
		cout << "请输入联系人性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while(true){
			cin >> sex; 
			if(sex == 1 || sex == 2){
				abs->ContactArray[ret].m_Sex = sex;
				break;
			}else{
				cout << "输入性别无效，请重新输入" << endl;
			}
		}
		// 年龄 
		int age = 0; 
		cout << "请输入联系人年龄： " << endl;
		while(true){
			cin >> age; 
			if(age >= 0){
				abs->ContactArray[abs->Size].m_Age = age;
				break;
			}else{
				cout << "输入年龄无效，请重新输入" << endl;
			}
		}
		// 联系电话
		string phoneNumber;
		cout << "请输入联系人电话：" << endl;
		cin >> phoneNumber;
		abs->ContactArray[ret].m_phoneNumber = phoneNumber;
		// 住址
		string address; 
		cout << "请输入联系人住址：" << endl; 
		cin >> address;
		abs->ContactArray[ret].m_Address = address;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}

// 清空联系人
void emptyContact(Addressbook * abs){
	abs->Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
} 

int main(){
	Addressbook abs;
	abs.Size = 0;			// 初始化通讯录 
	int select = 0;
	while(true){
		showMenu();			// 菜单调用 
		cin >> select;
		switch(select){
			case 1:         // 添加联系人
				addContact(&abs);
				break;
			case 2:			// 显示联系人
				showContact(&abs);
				break;
			case 3:			// 删除联系人
				deleteContact(&abs);
				break;
			case 4:			// 查找联系人
				findContact(&abs);
				break;	
			case 5:			// 修改联系人
				modifyContact(&abs);
				break;
			case 6:			// 清空联系人
				emptyContact(&abs);
				break;
			case 0:			// 退出通讯录 
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0; 
				break;
			default:
				cout<< "操作无效" << endl; 
				system("pause");
				system("cls");
		}
	}
	system("pause");
	return 0;
}
