#include <iostream>
using namespace std;

class Account {
private:
    string name; //�̸�
    string id; //�й�
    int balance; //�����

public:
    Account() :name("ȫ�浿"), id("2020"), balance(0) {}
    Account(string _name, string _id, int _balance) :name(_name), id(_id), balance(_balance) {}
    string getName() const { return name; }
    string getId() const { return id; }
    int getBalance() const { return balance; }

    Account operator+(const Account& acnt) {
        Account result(this->name, this->id, this->balance + acnt.balance);
        return result;
    }

    Account operator-(const Account& acnt) {
        Account result(this->name, this->id, this->balance - acnt.balance);
        return result;
    }

};

ostream& operator<<(ostream& cout, Account& acnt) {
    cout << "�й�: " << acnt.getName() << ", �̸�: " << acnt.getId() << ", �ܾ�: " << acnt.getBalance();
    return cout;
}

int main_c() {
    Account acnt[3] = {
       Account("����ȣ", "2014",10000),
       Account("������","2019",0),
       Account("������","2013",5000),
    };

    while (true) {
        string sendid, getid;
        int sendIndex = -1, getIndex = -1;

        cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
        cin >> sendid;

        if (sendid == "����") {
            cout << "�����մϴ�" << endl;
            break;
        }

        cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
        cin >> getid;

        //���� ���� �л��� ���� ���� �л��� �й��� ������ ���
        if (sendid == getid) {
            cout << "�Է��� �� �й��� �����մϴ�" << endl;
            continue;
        }
        //���� �л� Ȥ�� ���� �л��� �й��� �������� �ʴ� ���
        //���� �л��� �ܾ��� 0�� ���
        int check = 2;
        for (int i = 0; i < 3; i++) {

            if (check == 1 && acnt[i].getId() != sendid && acnt[i].getId() != getid) {
                cout << "������ �л� Ȥ�� ���� �л��� �й��� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
            }

            if (acnt[i].getId() == sendid || acnt[i].getId() == getid) {
                if (acnt[i].getId() == sendid) { // sendid�� ��
                    sendIndex = i;
                }
                else if (acnt[i].getId() == getid) { // getid�� ��
                    getIndex = i;
                }
                check = 0;
            }
            else
                check = 1;
        }
        
        if (check == 1 && (sendIndex < 0 || getIndex < 0))
            continue;
        else if (acnt[sendIndex].getBalance() != 0) {
            acnt[getIndex] = acnt[getIndex] + acnt[sendIndex];
            acnt[sendIndex] = acnt[sendIndex] - acnt[sendIndex];
            cout << "���� �л��� �ܾ� => " << acnt[sendIndex] << endl;
            cout << "���� �л��� �ܾ� => " << acnt[getIndex] << endl;
        }
        else if (acnt[sendIndex].getBalance() == 0) {
            cout << "������ �л��� �ܾ��� �����մϴ�." << endl;
        }
    }

    for (unsigned i = 0; i < 3; i++) {
        cout << acnt[i] << endl;
    }

    return 0;
}