#include "ItemType.h"


// 키보드로 콘텐츠 파일명 입력 함수
void ItemType::SetNameFromKB() {
	cout << "\tContents Name : ";
	cin >> m_cname;
}

// 키보드로 콘텐츠 종류 입력 함수
void ItemType::SetTypeFromKB() {
	cout << "\tContents Type : ";
	cin >> m_ctype;
}

// 키보드로 콘텐츠 생성날짜와 시간 입력 함수
void ItemType::SetDateFromKB() {
	cout << "\tContents Date( ex) 2020_13) : ";
	cin >> m_cdate;
}

// 키보드로 콘텐츠에 포함된 사람 입력 함수
void ItemType::SetPeoFromKB() {
	cout << "\tPeople in Contents : ";
	cin >> m_cpeople;
}

// 키보드로 이벤트명 입력 함수
void ItemType::SetEventnameFromKB() {
	cout << "\tEvent name : ";
	cin >> m_eventname;
}

// 키보드로 콘텐츠 기록 입력 함수
void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetPeoFromKB();
	SetEventnameFromKB();
}

//학생 정보를 파일에서 읽는 함수
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_cname;
	fin >> m_ctype;
	fin >> m_cdate;
	fin >> m_cpeople;
	fin >> m_eventname;

	return 1;
}

//학생 정보를 파일로 출력하는 함수
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_cname << " ";
	fout << m_ctype << " ";
	fout << m_cdate << " ";
	fout << m_cpeople << " ";
	fout << m_eventname << " ";

	return 1;

}

//primary key(Name)을 기준으로 콘텐츠 정보를 비교하는 함수
RelationType ItemType::CompareByName(const ItemType& data) {
	if (this->m_cname > data.m_cname)
		return GREATER;
	else if (this->m_cname < data.m_cname)
		return LESS;
	else
		return EQUAL;
}