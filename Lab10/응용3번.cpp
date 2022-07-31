#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int id;
    string dpt;
    vector<string> subject;
    vector<char> grade;
public:
    Student() : name("default"), id(0), dpt("depart") {}
    Student(string _name, int _id, string _dpt) {
        name = _name;
        id = _id;
        dpt = _dpt;
    }
    void setName(string _name) {
        name = _name;
    }
    void setID(int _id) {
        id = _id;
    }
    void setDpt(string _dpt) {
        dpt = _dpt;
    }
    string getName() {
        return name;
    }
    int getID() {
        return id;
    }
    string getdpt() {
        return dpt;
    }
    void print() {
        cout << name << " " << id << " " << dpt << endl;
    }
    void addGrade(string _dpt, char _grade) {
        subject.push_back(_dpt);
        grade.push_back(_grade);
    }
    void printGrades() {
        for (int i = 0; i < subject.size(); i++) {
            cout << subject[i] << " " << grade[i] << endl;
        }
        cout << "GPA : " << getGPA() << endl;
    }
    float getGPA() {
        float avg = 0.0;
        int sum = 0;

        for (int i = 0; i < grade.size(); i++) {
            if (grade[i] == 'A')
                sum += 4;
            else if (grade[i] == 'B')
                sum += 3;
            else if (grade[i] == 'C')
                sum += 2;
            else if (grade[i] == 'D')
                sum += 1;
            else if (grade[i] == 'F')
                sum += 0;
        }

        avg = (float)sum / grade.size();

        return avg;
    }
    void getYear(int year) {
        int y;
        y = getID() / 1000000;
        int temp = year - y;

        switch (temp) {
        case 0:
            cout << "Freshmen(1학년)" << endl;
            break;
        case 1:
            cout << "Sophomore(2학년)" << endl;
            break;
        case 2:
            cout << "Junior(3학년)" << endl;
            break;
        case 3:
            cout << "Senior(4학년)" << endl;
            break;
        default:
            cout << "About to graduate(5학년)" << endl;
            break;
        }
    }

};

int main_c() {
    Student Harry("Harry", 2017310973, "CS");
    Harry.print();
    Harry.getYear(2019);
    Harry.addGrade("programming", 'A');
    Harry.addGrade("Basic Circuit", 'B');
    Harry.printGrades();
    cout << "\n\n";

    Student Ron;
    Ron.print();
    cout << "\n";
    Ron.setName("Ron");
    Ron.setID(2014103959);
    Ron.setDpt("EE");
    Ron.print();
    Ron.getYear(2019);
    Ron.addGrade("Computer Architecture", 'B');
    Ron.addGrade("Maching Learning", 'B');
    Ron.addGrade("Computer Vision", 'C');
    Ron.printGrades();
    cout << "\n\n";


    return 0;
}