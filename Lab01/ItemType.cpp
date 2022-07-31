#include "ItemType.h"


// Ű����� ������ ���ϸ� �Է� �Լ�
void ItemType::SetNameFromKB() {
	cout << "\tContents Name : ";
	cin >> m_cname;
}

// Ű����� ������ ���� �Է� �Լ�
void ItemType::SetTypeFromKB() {
	cout << "\tContents Type : ";
	cin >> m_ctype;
}

// Ű����� ������ ������¥�� �ð� �Է� �Լ�
void ItemType::SetDateFromKB() {
	cout << "\tContents Date( ex) 2020_13) : ";
	cin >> m_cdate;
}

// Ű����� �������� ���Ե� ��� �Է� �Լ�
void ItemType::SetPeoFromKB() {
	cout << "\tPeople in Contents : ";
	cin >> m_cpeople;
}

// Ű����� �̺�Ʈ�� �Է� �Լ�
void ItemType::SetEventnameFromKB() {
	cout << "\tEvent name : ";
	cin >> m_eventname;
}

// Ű����� ������ ��� �Է� �Լ�
void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetPeoFromKB();
	SetEventnameFromKB();
}

//�л� ������ ���Ͽ��� �д� �Լ�
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_cname;
	fin >> m_ctype;
	fin >> m_cdate;
	fin >> m_cpeople;
	fin >> m_eventname;

	return 1;
}

//�л� ������ ���Ϸ� ����ϴ� �Լ�
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_cname << " ";
	fout << m_ctype << " ";
	fout << m_cdate << " ";
	fout << m_cpeople << " ";
	fout << m_eventname << " ";

	return 1;

}

//primary key(Name)�� �������� ������ ������ ���ϴ� �Լ�
RelationType ItemType::CompareByName(const ItemType& data) {
	if (this->m_cname > data.m_cname)
		return GREATER;
	else if (this->m_cname < data.m_cname)
		return LESS;
	else
		return EQUAL;
}