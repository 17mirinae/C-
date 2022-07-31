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

	void MakeEmpty(); // ���� ���ڵ� ��� ����
	int GetLength(); // ���� ���ڵ� �� ��ȯ
	bool IsFull(); // ��� �迭�� ��� ����
	int Add(ItemType inData); // ���ο� ������ �߰�
	void ResetList(); //���ڵ� ������(current pointer) �ʱ�ȭ
	int GetNextItem(ItemType& data);
	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ�
	// record index�� ����, ���̸� -1�� ����
	bool IsEmpty(); // �迭�� ������� ����
	int Get(ItemType& data);
	// primary key�� �������� �����͸� �˻��ϰ� �ش� ������ ������
	int Delete(ItemType data); // ���� ���ڵ� ����
	int Replace(ItemType data); // �Էµ� data�� primary key��
		// ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ
private:
	ItemType m_Array[MAXSIZE]; // ���ڵ� �迭
	int m_Length; // ����Ʈ�� ����� ���ڵ� ��
	int m_CurPointer; // current pointer
};

#endif // _LAB01_H