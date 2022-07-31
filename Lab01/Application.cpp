#include "Application.h"


void Application::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command) {
		case 1: // ������ ������ �Է� �޾� ����Ʈ�� �߰�
			AddContents();
			break;
		case 2: // �������� �̸��� �Է� �޾� ����Ʈ���� ����
			DeleteContents();
			break;
		case 3: // �������� ������ ���� �Էµ� ������ ����
			ReplaceContents();
			break;
		case 4: // �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش���� ã�� ȭ�� ���
			RetrieveContents();
			break;
		case 5: // ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
			DisplayAllContents();
			break;
		case 6: // ����Ʈ�� �Էµ� ��� ������ ����
			m_List.MakeEmpty();
			break;
		case 7: // load list data from a file
			ReadDataFromFile();
			break;
		case 8: // save list data into a file
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tlllegal selection...\n";
			break;
		}
	}
}
int Application::GetCommand() {
	int command = 0;
	cout << endl << endl;
	cout << "\t---ID--Command----" << endl;
	cout << "\t 1: Add Contents" << endl;
	cout << "\t 2: Delete Contents" << endl;
	cout << "\t 3: Replace Contents" << endl;
	cout << "\t 4: Retrieve Contents" << endl;
	cout << "\t 5: Display all Contents" << endl;
	cout << "\t 6: Make empty Contents" << endl;
	cout << "\t 7: Read Data From File" << endl;
	cout << "\t 8: Write Data To File" << endl;
	cout << "\t 0: Quit" << endl;

	cout << endl << "\t Choose a Command -> ";
	cin >> command;
	cout << endl;

	return command;
}

// 1: ������ ������ �Է� �޾� ����Ʈ�� �߰�
int Application::AddContents() {
	// List�� �������� 0 ����
	if (m_List.IsFull()) { 
		cout << "List is full" << endl;
		return 0;
	}
	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	//���� list ���
	DisplayAllContents();

	return 1;
}

// 2: �������� �̸��� �Է� �޾� ����Ʈ���� ����
int Application::DeleteContents() {
	ItemType selectItem;
	selectItem.SetNameFromKB();

	if (m_List.Delete(selectItem)) {
		cout << "\n\t������ ���������� �����Ͽ����ϴ�.";
		return 1;
	}
	else {
		cout << "\n\t�ش� �̸��� �������� �������� �ʽ��ϴ�.";
		return 0;
	}
}

// 3 :Ű����� ���� �޾Ƽ� list���� ã�� �������� ������ ���� �Էµ� ������ ����
int Application::ReplaceContents() {
	ItemType selectItem;
	selectItem.SetRecordFromKB();

	if (m_List.Replace(selectItem)) {
		cout << "\n\t������ ���������� �����Ͽ����ϴ�.";
		return 1;
	}
	else {
		cout << "\n\t�ش� �̸��� �������� �������� �ʽ��ϴ�.";
		return 0;
	}
}

// 4: �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش���� ã�� ȭ�� ���
int Application::RetrieveContents() {
	cout << "\t\t<Enter the label of Music>\n";
	ItemType data;
	data.SetNameFromKB();
	if (m_List.Get(data)) {				//�����Ͱ� �ִٸ� ���
		data.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

// 5: ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
void Application::DisplayAllContents() {
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	//list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1) {
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}

// 6: ����Ʈ�� �Էµ� ��� ������ ����
void Application::MakeEmpty() {
	m_List.MakeEmpty();
}


// 7 : ���Ϸκ��� ����Ʈ �о����
int Application::ReadDataFromFile() {
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�

	// array�� �л����� ������ ����ִ� structure ����
	while (!m_InFile.eof()) {
		// ���Ͽ��� �л� ���� �о����
		data.ReadDataFromFile(m_InFile);
		// ������ ���ڿ����� �Ǵ� �� while�� ����
		if (m_InFile.eof()) break;
		// ����Ʈ�� �ش� �л� ���� �߰�
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllContents();

	return 1;
}

// 8 : ���Ͽ� ����Ʈ �����ϱ�
int Application::WriteDataToFile() {
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}
