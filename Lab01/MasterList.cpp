#include "MasterList.h"


// ���� ���ڵ� ��� ����
void MasterList::MakeEmpty() {
	m_Length = 0;
}

// ���� ���ڵ� �� ��ȯ
int MasterList::GetLength() {
	return m_Length;
}

// ��� �迭�� ��� ����
bool MasterList::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// ���ο� ������ �߰�
int MasterList::Add(ItemType inData) {
	if (!IsFull()) {
		m_Array[m_Length] = inData; // ������ �߰�
		m_Length++; // ���� �ø�
	}
	else
		return 0;

	return 1;
}

//���ڵ� ������(current pointer) �ʱ�ȭ
void MasterList::ResetList() {
	m_CurPointer = -1;
}

// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ�
// record index�� ����, ���̸� -1�� ����
int MasterList::GetNextItem(ItemType& data) {
	m_CurPointer++; //list pointer ����
	if (m_CurPointer == MAXSIZE) // ���̸� -1 ����
		return -1;
	data = m_Array[m_CurPointer]; // ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

// �迭�� ������� ����
bool MasterList::IsEmpty() {
	if (m_Length == 0)
		return true;
	else
		return false;
}

// primary key(name)�� �������� �����͸� �˻��ϰ� �ش� ������ ������
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

// ���� ���ڵ� ����
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
// �Էµ� data�� primary key��
// ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ
int MasterList::Replace(ItemType data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		if (data == m_Array[m_CurPointer]) {
			m_Array[m_CurPointer] = data;
		}
	}
	return -1;
}