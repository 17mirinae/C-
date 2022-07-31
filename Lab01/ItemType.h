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

	string GetName() const { return m_cname; } // 콘텐츠 파일명 반환 함수
	int GetType() const { return m_ctype; } // 콘텐츠 종류 반환 함수
	string GetDate() const { return m_cdate; } // 생성날짜와 시간 반환 함수
	string GetPeople() const { return m_cpeople; } // 콘텐츠에 포함된 사람 반환 함수
	string GetEventName() const { return m_eventname; } // 이벤트명 반환 함수

	void SetName(string inName) { m_cname = inName; } // 콘텐츠 파일명 저장 함수
	void SetCType(int inCType) { m_ctype = inCType; } // 콘텐츠 종류 저장 함수
	void SetDate(string inDate) { m_cdate = inDate; }//생성날짜와 시간 저장 함수
	void SetPeople(string inPeo) { m_cpeople = inPeo; } // 콘텐츠에 포함된 사람 저장 함수
	void SetEventName(string inename) { m_eventname = inename; }// 이벤트명 저장 함수
	void SetRecord(string inName, int inCType, string inDate, string inPeo, string inename) {
		SetName(inName);
		SetCType(inCType);
		SetDate(inDate);
		SetPeople(inPeo);
		SetEventName(inename);
	}

	// 콘텐츠 파일명 출력 함수
	void DisplayNameOnScreen() {
		cout << "\tName	: " << GetName() << endl;
	};
	// 콘텐츠 종류 출력 함수
	void DisplayTypeOnScreen() {
		cout << "\tContentType	: " << GetType() << endl;
	};
	// 생성날짜와 시간 출력 함수
	void DisplayDateOnScreen() {
		cout << "\tDate	: " << GetDate() << endl;
	};
	// 콘텐츠에 포함된 사람 출력 함수
	void DisplayPeoOnScreen() {
		cout << "\tPeople in Contents	: " << GetPeople() << endl;
	};
	// 이벤트명 출력 함수
	void DisplayEventnameOnScreen() {
		cout << "\tEvent name	: " << GetEventName() << endl;
	};
	// 총 기록 출력 함수
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayTypeOnScreen();
		DisplayDateOnScreen();
		DisplayPeoOnScreen();
		DisplayEventnameOnScreen();
		cout << endl;
	};

	void SetNameFromKB(); // 키보드로 콘텐츠 파일명 입력 함수
	void SetTypeFromKB(); // 키보드로 콘텐츠 종류 입력 함수
	void SetDateFromKB(); // 키보드로 콘텐츠 생성날짜와 시간 입력 함수
	void SetPeoFromKB(); // 키보드로 콘텐츠에 포함된 사람 입력 함수
	void SetEventnameFromKB(); // 키보드로 이벤트명 입력 함수
	void SetRecordFromKB(); // 키보드로 콘텐츠 기록 입력 함수


	int ReadDataFromFile(ifstream& fin); //학생 정보를 파일에서 읽는 함수
	int WriteDataToFile(ofstream& fout); //학생 정보를 파일로 출력하는 함수
	
	RelationType CompareByName(const ItemType& data);
	//primary key(Name)을 기준으로 콘텐츠 정보를 비교하는 함수

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
	string m_cname =""; // 콘텐츠 파일명
	int m_ctype=0; //콘텐츠 종류
	/*
	1: 예능
	2. 드라마
	3. 영화
	4. 노래
	5. 기타
	*/
	string m_cdate="200910_13"; // 생성날짜와 시간
	string m_cpeople=""; // 콘텐츠에 포함된 사람
	string m_eventname=""; // 이벤트명

};

#endif // _ITEMTYPE_H