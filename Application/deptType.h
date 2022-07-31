#pragma once
#ifndef _DEPTTYPE_H
#define _DEPTTYPE_H
#include <iostream>
#include <string>

using namespace std;

#include "SortedLinkedList.h"


// �� �а��� ������ ǥ���ϴ� class
class deptType {
private:
    string name; // �а� ��
    int numOfStudent; // �л� ��
    SortedLinkedList<int> studentList; // �Ҽ��л����� �й� ����Ʈ

public:
    deptType() {
        name = "";
        numOfStudent = studentList.GetLength();
    }
    ~deptType() {}

    string GetName() { return name; } // �а����� ��ȯ�ϴ� �Լ�
    int GetNum() { return numOfStudent; } // �л� ���� ��ȯ�ϴ� �Լ�
    int GetStudent() {
        return studentList.GetStudentID();
    }
    void SetName(string inname) { name = inname; }

    void DisplayNameOnScreen()
    {
        cout << "\tDept Name   : " << name << endl;
    };

    void DisplayNumOnScreen()
    {
        cout << "\tNum Of Student : " << numOfStudent << endl;
    };

    void DisplayStudentIDOnScreen()
    {
        cout << "\tStudent ID : ";
        studentList.DIsplayOnScreen();
    };

    void DisplayRecordOnScreen()
    {
        DisplayNameOnScreen();
        DisplayNumOnScreen();
        DisplayStudentIDOnScreen();
    };

    // Set dept name from keyboard.
    void SetNameFromKB()
    {
        cout << "\tDept Name : ";
        cin >> name;
    }

    // Set num of student from keyboard.
    void SetNum_IDFromKB()
    {
        cout << "\tNum of Student : ";
        cin >> numOfStudent;

        for (int i = 0; i < numOfStudent; i++) {
            int studentid;
            cout << "\tStudent ID : ";
            cin >> studentid;
            studentList.Add(studentid); // studentList�� �߰�
        }
    }

    // Set student record from keyboard.
    void SetRecordFromKB()
    {
        SetNameFromKB();
        SetNum_IDFromKB();

    }

    bool operator < (deptType& item) {
        return (this->GetName() < item.GetName());
    }

    bool operator==(deptType& item)
    {
        return (this->GetName() == item.GetName());
    }
    
    bool operator > (deptType& item)
    {
        return (this->GetName() > item.GetName());
    }

    //friend ostream& operator << (ostream& os, const deptType& item);

};

/*ostream& operator << (ostream& os, const deptType& item)
{
    os << item.name << '\t' << item.numOfStudent << endl;
    return os;
}*/

#endif