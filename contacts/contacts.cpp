#include <iostream>
#include <string>

#include "./contacts.h"

using namespace std;


bool MyAddressBook::checkFull() {
    return this->size == Max_Person;
}

void MyAddressBook::showMainMenu() {
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

void MyAddressBook::addOnePerson(Person *newPerson) {
    if (this->size == Max_Person) {
        std::cout << "通讯录已满" << std::endl;
    } else {
        this->personArr[this->size] = *newPerson;
        this->size++;
        std::cout << "添加成功" << std::endl;
    }
}

void MyAddressBook::deletePerson(string name) {
    int check = this->hasName(&name);
    if (check > -1) {
        for (int i = check; i < this->size; i++) {
            this->personArr[i] = this->personArr[i + 1];
        }
        this->size--;
        std::cout << "删除成功" << std::endl;
    } else {
        std::cout << "查无此人" << std::endl;
    }
}

void MyAddressBook::printPerson() {
    if (this->size == 0) {
        std::cout << "通讯录为空" << std::endl;
    } else {
        for (int i = 0; i < this->size; i++) {
            Person temp = this->personArr[i];
            std::cout << i + 1 << ". 姓名：" << temp.name << " 年龄：" << temp.age << " 电话：" << temp.phone << std::endl;
        }
    }
    cin.get();
    cin.clear();
}

int MyAddressBook::searchOnePerson(string name) {
    int check = this->hasName(&name);
    if (check > -1) {
        Person temp = this->personArr[check];
        cout << "搜索成功"
        << " 姓名：" << temp.name << " 年龄：" << temp.age << " 电话：" << temp.phone << std::endl;
    } else {
        cout << "查无此人" << std::endl;
    }
}

int MyAddressBook::hasName(string *name) {
    if (this->size == 0) {
        return -1;
    } else {
        for (int i = 0; i < this->size; i++) {
            if (this->personArr[i].name == *name) {
                return i;
            }
        }
        return -1;
    }
}


MyAddressBook::MyAddressBook() {
    this->size = 0;
}

MyAddressBook::~MyAddressBook() {
    std::cout << "MyAddressBook Destroyed" << std::endl;
}


void MyAddressBook::searchPerson() {
    string sName;
    std::cout << "请输入想要搜索的名字：" << std::endl;
    cin >> sName;
    this->searchOnePerson(sName);
    cin.get();
    cin.clear();
}

void MyAddressBook::deletePerson() {
    string delName;
    std::cout << "请输入想要删除的名字：" << std::endl;
    cin >> delName;

    this->deletePerson(delName);

    cin.get();
    cin.clear();
}

void MyAddressBook::addPerson() {
    if (this->checkFull()) {
        std::cout << "通讯录已满" << std::endl;
        return;
    } else {
        Person newOne;
        std::cout << "请输入姓名：" << std::endl;
        cin >> newOne.name;

        while (true) {
            std::cout << "请输入性别（1：男，2：女）：" << std::endl;
            cin >> newOne.sex;
            if (newOne.sex == 1 || newOne.sex == 2) {
                break;
            }
            std::cout << "输入有误！请重新输入" << std::endl;
        }
        std::cout << "请输入年龄：" << std::endl;
        cin >> newOne.age;
        std::cout << "请输入电话号码：" << std::endl;
        cin >> newOne.phone;

        this->addOnePerson(&newOne);

        cin.get();
        cin.clear();
    }
}

void MyAddressBook::clearContact() {
    this->size = 0;
}

void MyAddressBook::modifyPerson() {
    if (this->size == 0) {
        cout << "通信录为空，无法修改" << endl;
    } else {
        string sName;
        std::cout << "请输入想要修改的名字：" << std::endl;
        cin >> sName;
        this->searchOnePerson(sName);

    }

}

void MyAddressBook::init() {

    int select = 0;

    static MyAddressBook myBook;
    static bool flag = true;

    while (flag) {

        myBook.showMainMenu();

        while (!(cin >> select)) {
            cin.clear();
            cin.ignore();
            cout << "你输入的不是数字,请重新输入" << endl;
        }

        switch (select) {
            case 1:
                myBook.addPerson();
                break;
            case 2:
                myBook.printPerson();
                break;
            case 3:
                myBook.deletePerson();
                break;
            case 4:
                myBook.searchPerson();
                break;
            case 5:
                myBook.modifyPerson();
                break;
            case 6:
                myBook.clearContact();
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                flag = false;
                break;
            default:
                break;
        }
    }
}
