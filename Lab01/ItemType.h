#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


enum RelationType { LESS, GREATER, EQUAL };
class ItemType {
public:
	ItemType() {}
	~ItemType() {}

	string GetName() const { return m_cname; } // ������ ���ϸ� ��ȯ �Լ�
	int GetType() const { return m_ctype; } // ������ ���� ��ȯ �Լ�
	string GetDate() const { return m_cdate; } // ������¥�� �ð� ��ȯ �Լ�
	string GetPeople() const { return m_cpeople; } // �������� ���Ե� ��� ��ȯ �Լ�
	string GetEventName() const { return m_eventname; } // �̺�Ʈ�� ��ȯ �Լ�

	void SetName(string inName) { m_cname = inName; } // ������ ���ϸ� ���� �Լ�
	void SetCType(int inCType) { m_ctype = inCType; } // ������ ���� ���� �Լ�
	void SetDate(string inDate) { m_cdate = inDate; }//������¥�� �ð� ���� �Լ�
	void SetPeople(string inPeo) { m_cpeople = inPeo; } // �������� ���Ե� ��� ���� �Լ�
	void SetEventName(string inename) { m_eventname = inename; }// �̺�Ʈ�� ���� �Լ�
	void SetRecord(string inName, int inCType, string inDate, string inPeo, string inename) {
		SetName(inName);
		SetCType(inCType);
		SetDate(inDate);
		SetPeople(inPeo);
		SetEventName(inename);
	}

	// ������ ���ϸ� ��� �Լ�
	void DisplayNameOnScreen() {
		cout << "\tName	: " << GetName() << endl;
	};
	// ������ ���� ��� �Լ�
	void DisplayTypeOnScreen() {
		cout << "\tContentType	: " << GetType() << endl;
	};
	// ������¥�� �ð� ��� �Լ�
	void DisplayDateOnScreen() {
		cout << "\tDate	: " << GetDate() << endl;
	};
	// �������� ���Ե� ��� ��� �Լ�
	void DisplayPeoOnScreen() {
		cout << "\tPeople in Contents	: " << GetPeople() << endl;
	};
	// �̺�Ʈ�� ��� �Լ�
	void DisplayEventnameOnScreen() {
		cout << "\tEvent name	: " << GetEventName() << endl;
	};
	// �� ��� ��� �Լ�
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayTypeOnScreen();
		DisplayDateOnScreen();
		DisplayPeoOnScreen();
		DisplayEventnameOnScreen();
		cout << endl;
	};

	void SetNameFromKB(); // Ű����� ������ ���ϸ� �Է� �Լ�
	void SetTypeFromKB(); // Ű����� ������ ���� �Է� �Լ�
	void SetDateFromKB(); // Ű����� ������ ������¥�� �ð� �Է� �Լ�
	void SetPeoFromKB(); // Ű����� �������� ���Ե� ��� �Է� �Լ�
	void SetEventnameFromKB(); // Ű����� �̺�Ʈ�� �Է� �Լ�
	void SetRecordFromKB(); // Ű����� ������ ��� �Է� �Լ�


	int ReadDataFromFile(ifstream& fin); //�л� ������ ���Ͽ��� �д� �Լ�
	int WriteDataToFile(ofstream& fout); //�л� ������ ���Ϸ� ����ϴ� �Լ�
	
	RelationType CompareByName(const ItemType& data);
	//primary key(Name)�� �������� ������ ������ ���ϴ� �Լ�

	bool operator==(const ItemType& A) {
		if (m_cname == A.GetName())
			return true;
		return false;
	}

	void operator=(const ItemType& _item) {
		m_cname = _item.GetName();
		m_ctype = _item.GetType();
		m_cdate = _item.GetDate();
		m_cpeople = _item.GetPeople();
		m_eventname = _item.GetEventName();
	}


private:
	string m_cname =""; // ������ ���ϸ�
	int m_ctype=0; //������ ����
	/*
	1: ����
	2. ���
	3. ��ȭ
	4. �뷡
	5. ��Ÿ
	*/
	string m_cdate="200910_13"; // ������¥�� �ð�
	string m_cpeople=""; // �������� ���Ե� ���
	string m_eventname=""; // �̺�Ʈ��

};

#endif // _ITEMTYPE_H