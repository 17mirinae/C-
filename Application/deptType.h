#pragma once
#ifndef _DEPTTYPE_H
#define _DEPTTYPE_H
#include <iostream>
#include <string>

using namespace std;

#include "SortedLinkedList.h"


// 한 학과의 정보를 표현하는 class
class deptType {
private:
    string name; // 학과 명
    int numOfStudent; // 학생 수
    SortedLinkedList<int> studentList; // 소속학생들의 학번 리스트

public:
    deptType() {
        name = "";
        numOfStudent = studentList.GetLength();
    }
    ~deptType() {}

    string GetName() { return name; } // 학과명을 반환하는 함수
    int GetNum() { return numOfStudent; } // 학생 수를 반환하는 함수
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
            studentList.Add(studentid); // studentList에 추가
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