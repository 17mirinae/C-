#include "MasterList.h"


// 현재 레코드 모두 삭제
void MasterList::MakeEmpty() {
	m_Length = 0;
}

// 현재 레코드 수 반환
int MasterList::GetLength() {
	return m_Length;
}

// 모든 배열의 사용 여부
bool MasterList::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// 새로운 데이터 추가
int MasterList::Add(ItemType inData) {
	if (!IsFull()) {
		m_Array[m_Length] = inData; // 데이터 추가
		m_Length++; // 길이 늘림
	}
	else
		return 0;

	return 1;
}

//레코드 포인터(current pointer) 초기화
void MasterList::ResetList() {
	m_CurPointer = -1;
}

// current pointer를 하나 증가시키고 끝이 아니면
// record index를 리턴, 끝이면 -1를 리턴
int MasterList::GetNextItem(ItemType& data) {
	m_CurPointer++; //list pointer 증가
	if (m_CurPointer == MAXSIZE) // 끝이면 -1 리턴
		return -1;
	data = m_Array[m_CurPointer]; // 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

// 배열이 비었는지 여부
bool MasterList::IsEmpty() {
	if (m_Length == 0)
		return true;
	else
		return false;
}

// primary key(name)를 기준으로 데이터를 검색하고 해당 데이터 가져옴
int MasterList::Get(ItemType& data) {
	ItemType temp;
	ResetList();
	GetNextItem(temp);
	while (m_CurPointer != -1) {
		if (temp == data) {
			data = temp;
			return 1;
		}
		GetNextItem(temp);
	}
	return 0;
	/*for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		if (data == m_Array[m_CurPointer]) {
			return m_CurPointer;
		}
	}
	return -1;*/
}

// 기존 레코드 삭제
int MasterList::Delete(ItemType data) {
	bool isFind = false;
	for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		if (!isFind) {
			if (data == m_Array[m_CurPointer]) {
				isFind = true;
			}
		}
		else {
			m_Array[m_CurPointer - 1] = m_Array[m_CurPointer];
		}
	}
	m_Length--;
	if (isFind)
		return 1;
	else
		return -1;

}
// 입력된 data와 primary key와
// 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환
int MasterList::Replace(ItemType data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		if (data == m_Array[m_CurPointer]) {
			m_Array[m_CurPointer] = data;
		}
	}
	return -1;
}