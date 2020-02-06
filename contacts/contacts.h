//
// Created by NolyPro13 on 2020/2/5 0005.
//

#ifndef MY_CPP_HOME_CONTACTS_H
#define MY_CPP_HOME_CONTACTS_H

#include <iostream>
#include <string>
#include <cstdlib>

#define Max_Person 1000

using namespace std;

struct Person
{
    string name;
    string avatar;
    int sex; // 0 unknown 1 male 2 female
    int age;
    string phone;
    string address;
};

class MyAddressBook {
private:
    struct Person personArr[Max_Person];
    int size;

public:
    bool checkFull();
    void showMainMenu();
    void addOnePerson(Person *newPerson);
    void deletePerson(string name);
    void printPerson();
    int hasName(string *name);
    int searchOnePerson(string name);

    void addPerson();
    void deletePerson();
    void searchPerson();
    void modifyPerson();
    void clearContact();
    static void init();
    MyAddressBook();
    ~MyAddressBook();
};

#endif //MY_CPP_HOME_CONTACTS_H
