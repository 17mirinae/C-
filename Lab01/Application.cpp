#include "Application.h"


void Application::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command) {
		case 1: // 콘텐츠 정보를 입력 받아 리스트에 추가
			AddContents();
			break;
		case 2: // 콘텐츠의 이름을 입력 받아 리스트에서 삭제
			DeleteContents();
			break;
		case 3: // 콘텐츠의 정보를 새로 입력된 정보로 갱신
			ReplaceContents();
			break;
		case 4: // 이름을 입력받아서 리스트에서 해당곡을 찾아 화면 출력
			RetrieveContents();
			break;
		case 5: // 리스트에 저장된 모든 콘텐츠를 화면에 출력
			DisplayAllContents();
			break;
		case 6: // 리스트에 입력된 모든 내용을 삭제
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

// 1: 콘텐츠 정보를 입력 받아 리스트에 추가
int Application::AddContents() {
	// List가 가득차면 0 리턴
	if (m_List.IsFull()) { 
		cout << "List is full" << endl;
		return 0;
	}
	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	//현재 list 출력
	DisplayAllContents();

	return 1;
}

// 2: 콘텐츠의 이름을 입력 받아 리스트에서 삭제
int Application::DeleteContents() {
	ItemType selectItem;
	selectItem.SetNameFromKB();

	if (m_List.Delete(selectItem)) {
		cout << "\n\t삭제가 정상적으로 동작하였습니다.";
		return 1;
	}
	else {
		cout << "\n\t해당 이름의 콘텐츠가 존재하지 않습니다.";
		return 0;
	}
}

// 3 :키보드로 정보 받아서 list에서 찾아 콘텐츠의 정보를 새로 입력된 정보로 갱신
int Application::ReplaceContents() {
	ItemType selectItem;
	selectItem.SetRecordFromKB();

	if (m_List.Replace(selectItem)) {
		cout << "\n\t수정이 정상적으로 동작하였습니다.";
		return 1;
	}
	else {
		cout << "\n\t해당 이름의 콘텐츠가 존재하지 않습니다.";
		return 0;
	}
}

// 4: 이름을 입력받아서 리스트에서 해당곡을 찾아 화면 출력
int Application::RetrieveContents() {
	cout << "\t\t<Enter the label of Music>\n";
	ItemType data;
	data.SetNameFromKB();
	if (m_List.Get(data)) {				//데이터가 있다면 출력
		data.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t\t<No such information found>\n";
		return 0;
	}
}

// 5: 리스트에 저장된 모든 콘텐츠를 화면에 출력
void Application::DisplayAllContents() {
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	//list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1) {
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}

// 6: 리스트에 입력된 모든 내용을 삭제
void Application::MakeEmpty() {
	m_List.MakeEmpty();
}


// 7 : 파일로부터 리스트 읽어오기
int Application::ReadDataFromFile() {
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가

	// array에 학생들의 정보가 들어있는 structure 저장
	while (!m_InFile.eof()) {
		// 파일에서 학생 정보 읽어오기
		data.ReadDataFromFile(m_InFile);
		// 마지막 문자열인지 판단 후 while문 종료
		if (m_InFile.eof()) break;
		// 리스트에 해당 학생 정보 추가
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllContents();

	return 1;
}

// 8 : 파일에 리스트 저장하기
int Application::WriteDataToFile() {
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}
