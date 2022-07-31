#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5
class MasterList {
public:
	MasterList() {
		m_Length = 0;
		ResetList();
	}
	~MasterList(){}

	void MakeEmpty(); // 현재 레코드 모두 삭제
	int GetLength(); // 현재 레코드 수 반환
	bool IsFull(); // 모든 배열의 사용 여부
	int Add(ItemType inData); // 새로운 데이터 추가
	void ResetList(); //레코드 포인터(current pointer) 초기화
	int GetNextItem(ItemType& data);
	// current pointer를 하나 증가시키고 끝이 아니면
	// record index를 리턴, 끝이면 -1를 리턴
	bool IsEmpty(); // 배열이 비었는지 여부
	int Get(ItemType& data);
	// primary key를 기준으로 데이터를 검색하고 해당 데이터 가져옴
	int Delete(ItemType data); // 기존 레코드 삭제
	int Replace(ItemType data); // 입력된 data와 primary key와
		// 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환
private:
	ItemType m_Array[MAXSIZE]; // 레코드 배열
	int m_Length; // 리스트에 저장된 레코드 수
	int m_CurPointer; // current pointer
};

#endif // _LAB01_H