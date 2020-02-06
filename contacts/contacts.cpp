#include <iostream>
#include <string>

#include "./contacts.h"

using namespace std;


bool MyAddressBook::checkFull() {
    return this->size == Max_Person;
}

void MyAddressBook::showMainMenu() {
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

void MyAddressBook::addOnePerson(Person *newPerson) {
    if (this->size == Max_Person) {
        std::cout << "ͨѶ¼����" << std::endl;
    } else {
        this->personArr[this->size] = *newPerson;
        this->size++;
        std::cout << "��ӳɹ�" << std::endl;
    }
}

void MyAddressBook::deletePerson(string name) {
    int check = this->hasName(&name);
    if (check > -1) {
        for (int i = check; i < this->size; i++) {
            this->personArr[i] = this->personArr[i + 1];
        }
        this->size--;
        std::cout << "ɾ���ɹ�" << std::endl;
    } else {
        std::cout << "���޴���" << std::endl;
    }
}

void MyAddressBook::printPerson() {
    if (this->size == 0) {
        std::cout << "ͨѶ¼Ϊ��" << std::endl;
    } else {
        for (int i = 0; i < this->size; i++) {
            Person temp = this->personArr[i];
            std::cout << i + 1 << ". ������" << temp.name << " ���䣺" << temp.age << " �绰��" << temp.phone << std::endl;
        }
    }
    cin.get();
    cin.clear();
}

int MyAddressBook::searchOnePerson(string name) {
    int check = this->hasName(&name);
    if (check > -1) {
        Person temp = this->personArr[check];
        cout << "�����ɹ�"
        << " ������" << temp.name << " ���䣺" << temp.age << " �绰��" << temp.phone << std::endl;
    } else {
        cout << "���޴���" << std::endl;
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
    std::cout << "��������Ҫ���������֣�" << std::endl;
    cin >> sName;
    this->searchOnePerson(sName);
    cin.get();
    cin.clear();
}

void MyAddressBook::deletePerson() {
    string delName;
    std::cout << "��������Ҫɾ�������֣�" << std::endl;
    cin >> delName;

    this->deletePerson(delName);

    cin.get();
    cin.clear();
}

void MyAddressBook::addPerson() {
    if (this->checkFull()) {
        std::cout << "ͨѶ¼����" << std::endl;
        return;
    } else {
        Person newOne;
        std::cout << "������������" << std::endl;
        cin >> newOne.name;

        while (true) {
            std::cout << "�������Ա�1���У�2��Ů����" << std::endl;
            cin >> newOne.sex;
            if (newOne.sex == 1 || newOne.sex == 2) {
                break;
            }
            std::cout << "������������������" << std::endl;
        }
        std::cout << "���������䣺" << std::endl;
        cin >> newOne.age;
        std::cout << "������绰���룺" << std::endl;
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
        cout << "ͨ��¼Ϊ�գ��޷��޸�" << endl;
    } else {
        string sName;
        std::cout << "��������Ҫ�޸ĵ����֣�" << std::endl;
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
            cout << "������Ĳ�������,����������" << endl;
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
                cout << "��ӭ�´�ʹ��" << endl;
                flag = false;
                break;
            default:
                break;
        }
    }
}
