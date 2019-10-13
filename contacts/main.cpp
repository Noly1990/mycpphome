#include <iostream>
#include <string>
using namespace std;

#define Max_Person 1000

struct Person
{
    string name;
    string avatar;
    int sex; // 0 unknown 1 male 2 female
    int age;
    string phone;
    string address;
};

class MyAddressBook
{
private:
    struct Person personArr[Max_Person];
    int size;

public:
    MyAddressBook(/* args */);
    ~MyAddressBook();

    bool checkFull()
    {
        return this->size == Max_Person;
    }

    void addPerson(Person newPerson)
    {
        if (this->size == Max_Person)
        {
            std::cout << "����" << std::endl;
        }
        else
        {
            this->personArr[this->size] = newPerson;
            this->size++;
            std::cout << "��ӳɹ�" << std::endl;
        }
    }

    void deletePerson(string name)
    {
        int check = this->hasName(name);
        if (check > -1)
        {
            for (int i = check; i < this->size; i++)
            {
                this->personArr[i] = this->personArr[i + 1];
            }
            this->size--;
            std::cout << "ɾ���ɹ�" << std::endl;
        }
        else
        {
            std::cout << "���޴���" << std::endl;
        }
    }

    void printPerson()
    {
        if (this->size == 0)
        {
            std::cout << "ͨѶ¼Ϊ��" << std::endl;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                Person temp = this->personArr[i];
                std::cout << i + 1 << ". ������" << temp.name << " ���䣺" << temp.age << " �绰��" << temp.phone << std::endl;
            }
        }
        system("pause");
        system("cls");
    }

    void searchPerson(string name)
    {
        int check = this->hasName(name);
        if (check > -1)
        {
            Person temp = this->personArr[check];
            std::cout << "�����ɹ�"
                      << " ������" << temp.name << " ���䣺" << temp.age << " �绰��" << temp.phone << std::endl;
        }
        else
        {
            std::cout << "���޴���" << std::endl;
        }
    }

    int hasName(string name)
    {
        if (this->size == 0)
        {
            return -1;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->personArr[i].name == name)
                {
                    return i;
                }
            }
            return -1;
        }
    }
};

MyAddressBook::MyAddressBook(/* args */)
{
    this->size = 0;
}

MyAddressBook::~MyAddressBook()
{
    std::cout << "MyAddressBook destoryed" << std::endl;
}

void showMainMenu()
{
    std::cout << "***************************" << std::endl;
    std::cout << "*******1.�����ϵ��*********" << std::endl;
    std::cout << "*******2.��ʾ��ϵ��*********" << std::endl;
    std::cout << "*******3.ɾ����ϵ��*********" << std::endl;
    std::cout << "*******4.������ϵ��*********" << std::endl;
    std::cout << "*******5.�޸���ϵ��*********" << std::endl;
    std::cout << "*******6.�����ϵ��*********" << std::endl;
    std::cout << "*******0.�˳�ͨѶ¼*********" << std::endl;
    std::cout << "***************************" << std::endl;
}

void searchPerson(MyAddressBook *book)
{
    string sName;
    std::cout << "��������Ҫ���������֣�" << std::endl;
    cin >> sName;
    book->searchPerson(sName);
    system("pause");
    system("cls");
}

void deletePerson(MyAddressBook *book)
{
    string delName;
    std::cout << "��������Ҫɾ�������֣�" << std::endl;
    cin >> delName;

    book->deletePerson(delName);

    system("pause");
    system("cls");
}

void addPerson(MyAddressBook *book)
{
    if (book->checkFull())
    {
        std::cout << "ͨѶ¼����" << std::endl;
        return;
    }
    else
    {
        Person newOne;
        std::cout << "������������" << std::endl;
        cin >> newOne.name;

        while (true)
        {
            std::cout << "�������Ա�1���У�2��Ů����" << std::endl;
            cin >> newOne.sex;
            if (newOne.sex == 1 || newOne.sex == 2)
            {
                break;
            }
            std::cout << "������������������" << std::endl;
        }
        std::cout << "���������䣺" << std::endl;
        cin >> newOne.age;
        std::cout << "������绰���룺" << std::endl;
        cin >> newOne.phone;

        book->addPerson(newOne);

        system("pause");
        system("cls");
    }
}

int main()
{
    int select = 0;
    // 1.��ʾ���˵�

    MyAddressBook myBook;

    while (true)
    {
        showMainMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            addPerson(&myBook);
            break;
        case 2:
            myBook.printPerson();
            break;
        case 3:
            deletePerson(&myBook);
            break;
        case 4:
            searchPerson(&myBook);
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            std::cout << "��ӭ�´�ʹ��" << std::endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }

    system("pause");
    return 0;
}
