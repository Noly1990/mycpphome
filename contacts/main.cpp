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
            std::cout << "满了" << std::endl;
        }
        else
        {
            this->personArr[this->size] = newPerson;
            this->size++;
            std::cout << "添加成功" << std::endl;
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
            std::cout << "删除成功" << std::endl;
        }
        else
        {
            std::cout << "查无此人" << std::endl;
        }
    }

    void printPerson()
    {
        if (this->size == 0)
        {
            std::cout << "通讯录为空" << std::endl;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                Person temp = this->personArr[i];
                std::cout << i + 1 << ". 姓名：" << temp.name << " 年龄：" << temp.age << " 电话：" << temp.phone << std::endl;
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
            std::cout << "搜索成功"
                      << " 姓名：" << temp.name << " 年龄：" << temp.age << " 电话：" << temp.phone << std::endl;
        }
        else
        {
            std::cout << "查无此人" << std::endl;
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
    std::cout << "*******1.添加联系人*********" << std::endl;
    std::cout << "*******2.显示联系人*********" << std::endl;
    std::cout << "*******3.删除联系人*********" << std::endl;
    std::cout << "*******4.查找联系人*********" << std::endl;
    std::cout << "*******5.修改联系人*********" << std::endl;
    std::cout << "*******6.清空联系人*********" << std::endl;
    std::cout << "*******0.退出通讯录*********" << std::endl;
    std::cout << "***************************" << std::endl;
}

void searchPerson(MyAddressBook *book)
{
    string sName;
    std::cout << "请输入想要搜索的名字：" << std::endl;
    cin >> sName;
    book->searchPerson(sName);
    system("pause");
    system("cls");
}

void deletePerson(MyAddressBook *book)
{
    string delName;
    std::cout << "请输入想要删除的名字：" << std::endl;
    cin >> delName;

    book->deletePerson(delName);

    system("pause");
    system("cls");
}

void addPerson(MyAddressBook *book)
{
    if (book->checkFull())
    {
        std::cout << "通讯录已满" << std::endl;
        return;
    }
    else
    {
        Person newOne;
        std::cout << "请输入姓名：" << std::endl;
        cin >> newOne.name;

        while (true)
        {
            std::cout << "请输入性别（1：男，2：女）：" << std::endl;
            cin >> newOne.sex;
            if (newOne.sex == 1 || newOne.sex == 2)
            {
                break;
            }
            std::cout << "输入有误！请重新输入" << std::endl;
        }
        std::cout << "请输入年龄：" << std::endl;
        cin >> newOne.age;
        std::cout << "请输入电话号码：" << std::endl;
        cin >> newOne.phone;

        book->addPerson(newOne);

        system("pause");
        system("cls");
    }
}

int main()
{
    int select = 0;
    // 1.显示主菜单

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
            std::cout << "欢迎下次使用" << std::endl;
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
