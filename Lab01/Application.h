#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MasterList.h"

#define FILENAMESIZE 1024

class Application {
public:
	Application() { m_Command = 0; }
	~Application() {}

	void Run(); // Ű����� �Է¹޾� ��ȣ������ ��� ����
	int GetCommand(); // Ű����� �Է¹޴� �޴�ȭ��
	int AddContents(); // ������ ������ �Է� �޾� ����Ʈ�� �߰�
	int DeleteContents();// �������� �̸��� �Է� �޾� ����Ʈ���� ����
	int ReplaceContents();
	// Ű����� ���� �޾Ƽ� list���� ã�� �������� ������ ���� �Էµ� ������ ����
	int RetrieveContents(); // �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش���� ã�� ȭ�� ���
	void DisplayAllContents(); // ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
	void MakeEmpty(); // ����Ʈ�� �Էµ� ��� ������ ����
	int ReadDataFromFile(); // ���Ϸκ��� ����Ʈ �о����
	int WriteDataToFile(); // ���Ͽ� ����Ʈ �����ϱ�
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);

private:
	ifstream m_InFile; // ���Ͽ� �Է�
	ofstream m_OutFile; // ���Ͽ��� ��������

	MasterList m_List; // item list
	int m_Command; // ���� command ��ȣ

};

#endif