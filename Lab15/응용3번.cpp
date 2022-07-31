#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileNotFoundException : public exception {
    string message; //Identifies the exception and filename
public:
    FileNotFoundException(const string& fname) :
        message("File \"" + fname + "\" not found") {}

    virtual const char* what() const throw() {
        return message.c_str();
    }
};
class CStudent {
private:
    string m_Name;
    int m_Number;
    string m_Major;
public:
    CStudent() {}
    ~CStudent() {}
    void setAll(string _name, int _num, string _maj) {
        m_Name = _name;
        m_Number = _num;
        m_Major = _maj;
    }
    void Display() {
        cout << "�̸�: " << m_Name << endl;
        cout << "�й�: " << m_Number << endl;
        cout << "����: " << m_Major << endl;
    }
};

vector<CStudent> read_file(string& filename) {
    ifstream fin(filename);

    if (!fin) {
        throw FileNotFoundException(filename);
    }

    try {
        int num;
        vector<CStudent> value;
        CStudent temp;
        string name, major;
        int number;

        fin >> num;
        for (int i = 0; i < num; i++) {
            fin >> name;
            fin >> number;
            fin >> major;
            temp.setAll(name, number, major);
            value.push_back(temp);
        }

        return value;
    }

    catch (FileNotFoundException& e) {
        cout << e.what() << endl;
    }

}

int main_f() {
    string str;

    cout << "���� �̸� : ";
    cin >> str;

    try {
        vector<CStudent> numbers = read_file(str);
        for (CStudent value : numbers) {
            value.Display();
            cout << endl;
        }
    }

    catch (exception& e) {
        cout << e.what() << '\n';
    }

    return 0;
}