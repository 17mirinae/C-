#include <iostream>
using namespace std;

class Account {
private:
    string name; //이름
    string id; //학번
    int balance; //전재산

public:
    Account() :name("홍길동"), id("2020"), balance(0) {}
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
    cout << "학번: " << acnt.getName() << ", 이름: " << acnt.getId() << ", 잔액: " << acnt.getBalance();
    return cout;
}

int main_c() {
    Account acnt[3] = {
       Account("장윤호", "2014",10000),
       Account("김유민","2019",0),
       Account("박진배","2013",5000),
    };

    while (true) {
        string sendid, getid;
        int sendIndex = -1, getIndex = -1;

        cout << "돈을 보낼 학생의 학번을 입력하세요: ";
        cin >> sendid;

        if (sendid == "종료") {
            cout << "종료합니다" << endl;
            break;
        }

        cout << "돈을 받을 학생의 학번을 입력하세요: ";
        cin >> getid;

        //돈을 보낼 학생과 돈을 받을 학생의 학번이 동일한 경우
        if (sendid == getid) {
            cout << "입력한 두 학번이 동일합니다" << endl;
            continue;
        }
        //보낼 학생 혹은 받을 학생의 학번이 존재하지 않는 경우
        //보낼 학생의 잔액이 0인 경우
        int check = 2;
        for (int i = 0; i < 3; i++) {

            if (check == 1 && acnt[i].getId() != sendid && acnt[i].getId() != getid) {
                cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
            }

            if (acnt[i].getId() == sendid || acnt[i].getId() == getid) {
                if (acnt[i].getId() == sendid) { // sendid일 때
                    sendIndex = i;
                }
                else if (acnt[i].getId() == getid) { // getid일 때
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
            cout << "보낸 학생의 잔액 => " << acnt[sendIndex] << endl;
            cout << "받은 학생의 잔액 => " << acnt[getIndex] << endl;
        }
        else if (acnt[sendIndex].getBalance() == 0) {
            cout << "보내는 학생의 잔액이 부족합니다." << endl;
        }
    }

    for (unsigned i = 0; i < 3; i++) {
        cout << acnt[i] << endl;
    }

    return 0;
}