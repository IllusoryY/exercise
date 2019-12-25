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
	cout << "******** 1�������ϵ�� *******" << endl;
	cout << "******** 2���޸���ϵ�� *******" << endl;
	cout << "******** 3��ɾ����ϵ�� *******" << endl;
	cout << "******** 4����ʾ��ϵ�� *******" << endl;
	cout << "******** 5��������ϵ�� *******" << endl;
	cout << "******** 6�����ͨѶ¼ *******" << endl;
	cout << "******** 0���˳�ͨѶ¼ *******" << endl;
	cout << "******************************" << endl;
}

struct person
{
	string m_name;   //����
	int m_sex;    //�Ա� 1-�� 2-Ů
	int m_age;	//����
	string m_phone; //����
	string m_address;    //סַ
};

struct phoneBook
{
	person m_books[MAX];
	int capacity = 0;
};

void add_phoneBook(phoneBook* item)
{
	printf("%s\n", "��������ϵ�˵�����:");
	string name;
	cin >> name;
	item->m_books[item->capacity].m_name = name;

	printf("%s\n%s\n%s\n", "��������ϵ�˵��Ա�:", "1--��", "2--Ů");
	int sex;
	do
	{
		cin >> sex;
	} while (sex != 1 && sex != 2);
	item->m_books[item->capacity].m_sex = sex;

	printf("%s\n", "��������ϵ������:");
	int age;
	cin >> age;
	item->m_books[item->capacity].m_age = age;

	printf("%s\n", "��������ϵ�˵绰����:");
	string phoneNumber;
	cin >> phoneNumber;
	item->m_books[item->capacity].m_phone = phoneNumber;

	printf("%s\n", "��������ϵ��סַ:");
	string address;
	cin >> address;
	item->m_books[item->capacity].m_address = address;

	item->capacity++;
	printf("%s\n", "��ӳɹ�");

	system("pause");
	system("cls");
}

//�����Ƿ������ϵ��
int findName(phoneBook *item, string name)
{
	for (int i = 0; i <= item->capacity; i++)
	{
		if (item->m_books[i].m_name == name)
			return i;
	}
	return -1;
}

//�޸���ϵ��
void modifyBooks(phoneBook *item)
{
	printf("%s\n", "��������Ҫ�޸ĵ���ϵ������:");
	string name;
	cin >> name;

	int result = 0;
	if ((result = findName(item, name)) != -1)
	{

		printf("%s\n", "��������ϵ�˵绰����:");
		string phoneNumber;
		cin >> phoneNumber;
		item->m_books[result].m_phone = phoneNumber;

		printf("%s\n", "��������ϵ��סַ:");
		string address;
		cin >> address;
		item->m_books[result].m_address = address;

		printf("%s\n", "�޸ĳɹ�");

		system("pause");
		system("cls");
	}
	else {
		printf("%s\n", "���޴���");
		system("pause");
		system("cls");
	}

}

//��ʾ��ϵ��
void showBooks(phoneBook *item)
{
	if (item->capacity == 0)
		printf("%s\n", "ͨѶ¼Ϊ��");
	else
	{
		for (int i = 0; i < item->capacity; i++)
		{
			printf("������%s\t�Ա�:%s\t���䣺%d\t�绰����:%s\tסַ:%s\n",
				item->m_books[i].m_name.c_str(),
				item->m_books[i].m_sex == 1 ? "��" : "Ů",
				item->m_books[i].m_age,
				item->m_books[i].m_phone.c_str(),
				item->m_books[i].m_address.c_str());
		}
	}
	system("pause");
	system("cls");
}

//ɾ����ϵ��
void deleteBook(phoneBook *item)
{
	printf("��������Ҫɾ������ϵ������\n");
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
		printf("ɾ����ϵ�˳ɹ�\n");
	}
	else
	{
		printf("δ�ҵ�����ϵ��\n");
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(phoneBook *item)
{
	printf("��������Ҫ���ҵ���ϵ������\n");
	string name;
	cin >> name;

	int ret = findName(item, name);
	if (ret != -1)
	{
		printf("������%s\t�Ա�:%s\t���䣺%d\t�绰����:%s\tסַ:%s\n",
			item->m_books[ret].m_name.c_str(),
			item->m_books[ret].m_sex == 1 ? "��" : "Ů",
			item->m_books[ret].m_age,
			item->m_books[ret].m_phone.c_str(),
			item->m_books[ret].m_address.c_str());
	}
	else
	{
		printf("���޴���\n");
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void deleteBooks(phoneBook *item)
{
	item->capacity = 0;
	printf("�����ϵ�˳ɹ�\n");
	system("pause");
	system("cls");
}

int main(int argc, char argv[])
{
	phoneBook phoneBooks;

	while (true)
	{
		showMeun();
		printf("%s\n", "��������Ҫ���еĲ���:");
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
			printf("%s\n", "��ӭ�´�ʹ��");
			system("pause");
			return 0;
		}
	}
}