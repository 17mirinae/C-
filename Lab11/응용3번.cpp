#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name; //이름
    string id; //학번
    int balance; //전재산
    //static int sum; //총 잔액

public:
    Account() :name("홍길동"), id("0"), balance(0) {}
    Account(string _id, string _name, int _balance) :id(_id), name(_name), balance(_balance) {}
    //~Account() { cout << "Hi" << endl; }

    string getName() const { return name; }
    string getId() const { return id; }
    int getBalance() const { return balance; }
};

int main() {
    int numOfStudent;
    int _balance;
    string _name, _id;

    cout << "총 학생 수 입력: ";
    cin >> numOfStudent;

    Account* acnt = new Account[numOfStudent];

    int check = 0;

    for (int i = 0; i < numOfStudent; i++) {
        cout << i + 1 << "번째 학생 계좌 입력 : 학번 : ";
        cin >> _id;

        for (int j = 0; j < numOfStudent; j++) {
            if (acnt[j].getId() == _id) {
                check = 1;
                break;
            }
        }
        
        if (check == 0) {
            cout << "이름 : ";
            cin >> _name;

            cout << "잔액 : ";
            cin >> _balance;

            acnt[i] = Account(_id, _name, _balance);
            cout << "================================================" << endl;
        }
        else
            break;

    }

    delete[] acnt;

    return 0;
}