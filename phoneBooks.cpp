#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

constexpr int MAX = 1000;

void showMeun()
{
	cout << "******************************" << endl;
	cout << "******** 1、添加联系人 *******" << endl;
	cout << "******** 2、修改联系人 *******" << endl;
	cout << "******** 3、删除联系人 *******" << endl;
	cout << "******** 4、显示联系人 *******" << endl;
	cout << "******** 5、查找联系人 *******" << endl;
	cout << "******** 6、清除通讯录 *******" << endl;
	cout << "******** 0、退出通讯录 *******" << endl;
	cout << "******************************" << endl;
}

struct person
{
	string m_name;   //姓名
	int m_sex;    //性别 1-男 2-女
	int m_age;	//年龄
	string m_phone; //号码
	string m_address;    //住址
};

struct phoneBook
{
	person m_books[MAX];
	int capacity = 0;
};

void add_phoneBook(phoneBook* item)
{
	printf("%s\n", "请输入联系人的姓名:");
	string name;
	cin >> name;
	item->m_books[item->capacity].m_name = name;

	printf("%s\n%s\n%s\n", "请输入联系人的性别:", "1--男", "2--女");
	int sex;
	do
	{
		cin >> sex;
	} while (sex != 1 && sex != 2);
	item->m_books[item->capacity].m_sex = sex;

	printf("%s\n", "请输入联系人年龄:");
	int age;
	cin >> age;
	item->m_books[item->capacity].m_age = age;

	printf("%s\n", "请输入联系人电话号码:");
	string phoneNumber;
	cin >> phoneNumber;
	item->m_books[item->capacity].m_phone = phoneNumber;

	printf("%s\n", "请输入联系人住址:");
	string address;
	cin >> address;
	item->m_books[item->capacity].m_address = address;

	item->capacity++;
	printf("%s\n", "添加成功");

	system("pause");
	system("cls");
}

//查找是否存在联系人
int findName(phoneBook *item, string name)
{
	for (int i = 0; i <= item->capacity; i++)
	{
		if (item->m_books[i].m_name == name)
			return i;
	}
	return -1;
}

//修改联系人
void modifyBooks(phoneBook *item)
{
	printf("%s\n", "请输入需要修改的联系人姓名:");
	string name;
	cin >> name;

	int result = 0;
	if ((result = findName(item, name)) != -1)
	{

		printf("%s\n", "请输入联系人电话号码:");
		string phoneNumber;
		cin >> phoneNumber;
		item->m_books[result].m_phone = phoneNumber;

		printf("%s\n", "请输入联系人住址:");
		string address;
		cin >> address;
		item->m_books[result].m_address = address;

		printf("%s\n", "修改成功");

		system("pause");
		system("cls");
	}
	else {
		printf("%s\n", "查无此人");
		system("pause");
		system("cls");
	}

}

//显示联系人
void showBooks(phoneBook *item)
{
	if (item->capacity == 0)
		printf("%s\n", "通讯录为空");
	else
	{
		for (int i = 0; i < item->capacity; i++)
		{
			printf("姓名：%s\t性别:%s\t年龄：%d\t电话号码:%s\t住址:%s\n",
				item->m_books[i].m_name.c_str(),
				item->m_books[i].m_sex == 1 ? "男" : "女",
				item->m_books[i].m_age,
				item->m_books[i].m_phone.c_str(),
				item->m_books[i].m_address.c_str());
		}
	}
	system("pause");
	system("cls");
}

//删除联系人
void deleteBook(phoneBook *item)
{
	printf("请输入想要删除的联系人姓名\n");
	string name;
	cin >> name;

	int result = findName(item, name);
	if (result != -1)
	{
		for (int i = result; i < item->capacity; i++)
		{
			item->m_books[i] = item->m_books[i + 1];
		}
		item->capacity--;
		printf("删除联系人成功\n");
	}
	else
	{
		printf("未找到该联系人\n");
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(phoneBook *item)
{
	printf("请输入想要查找的联系人姓名\n");
	string name;
	cin >> name;

	int ret = findName(item, name);
	if (ret != -1)
	{
		printf("姓名：%s\t性别:%s\t年龄：%d\t电话号码:%s\t住址:%s\n",
			item->m_books[ret].m_name.c_str(),
			item->m_books[ret].m_sex == 1 ? "男" : "女",
			item->m_books[ret].m_age,
			item->m_books[ret].m_phone.c_str(),
			item->m_books[ret].m_address.c_str());
	}
	else
	{
		printf("查无此人\n");
	}
	system("pause");
	system("cls");
}

//清空联系人
void deleteBooks(phoneBook *item)
{
	item->capacity = 0;
	printf("清空联系人成功\n");
	system("pause");
	system("cls");
}

int main(int argc, char argv[])
{
	phoneBook phoneBooks;

	while (true)
	{
		showMeun();
		printf("%s\n", "请输入你要进行的操作:");
		int meun;
		cin >> meun;

		switch (meun)
		{
		case 1:
			add_phoneBook(&phoneBooks);
			break;
		case 2:
			modifyBooks(&phoneBooks);
			break;
		case 3:
			deleteBook(&phoneBooks);
			break;
		case 4:
			showBooks(&phoneBooks);
			break;
		case 5:
			findPerson(&phoneBooks);
			break;
		case 6:
			deleteBooks(&phoneBooks);
			break;
		default:
			printf("%s\n", "欢迎下次使用");
			system("pause");
			return 0;
		}
	}
}