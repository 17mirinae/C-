#include <iostream>
#include <string>
using namespace std;

class CStudent {
private:
	int number;
	string name;
	string major;
public:
	CStudent() :number(2018000000), name("ȫ�浿"), major("��ǻ�Ͱ��а�") {}

	CStudent(int _number, string _name, string _major) {
		number = _number;
		name = _name;
		major = _major;
	}

	void Display() {
		cout << "�й�: " << number << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << major << endl;
		cout << endl;
	}

	void setNumber(int _number) {
		number = _number;
	}
	void setName(string _name) {
		name = _name;
	}
	void setMajor(string _major) {
		major = _major;
	}

	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

int main_b() {
	CStudent s[3]; // 3���� �л������� ������ class �迭
	int inputNumber; // Ű����� �й��� �Է� ���� ����
	string inputName, inputMajor; // Ű����� �̸�, ������ �Է� ���� ����
	int length = 0; // ���� �Էµ� �л��� ��

	while (1) {
		int check = 1;

		if (length == 3) {
			cout << "--��� �Է��� �Ϸ�Ǿ����ϴ�.--" << endl;
			break;
		}

		cout << length + 1 << " ��° �л� �Է�" << endl;
		cout << "�й�: ";
		cin >> inputNumber;

		cout << "�̸�: ";
		cin >> inputName;

		cout << "����: ";
		cin >> inputMajor;


		for (int i = 0; i <= length; i++) {
			if (inputNumber == s[i].getNumber()) {
				cout << "���ߺ��� �й��� �����մϴ�." << endl;
				cout << endl;
				check = 0;
				break;
			}
		}

		if (check == 1) {
			cout << "���Է� �Ϸ�" << endl;
			cout << endl;
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			length++;
		}
	}

	for (int i = 0; i < 3; i++) {
		s[i].Display();
	}

	return 0;
}