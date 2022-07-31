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
        cout << "이름: " << m_Name << endl;
        cout << "학번: " << m_Number << endl;
        cout << "전공: " << m_Major << endl;
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

    cout << "파일 이름 : ";
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