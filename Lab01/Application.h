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

	void Run(); // 키보드로 입력받아 번호마다의 기능 실행
	int GetCommand(); // 키보드로 입력받는 메뉴화면
	int AddContents(); // 콘텐츠 정보를 입력 받아 리스트에 추가
	int DeleteContents();// 콘텐츠의 이름을 입력 받아 리스트에서 삭제
	int ReplaceContents();
	// 키보드로 정보 받아서 list에서 찾아 콘텐츠의 정보를 새로 입력된 정보로 갱신
	int RetrieveContents(); // 이름을 입력받아서 리스트에서 해당곡을 찾아 화면 출력
	void DisplayAllContents(); // 리스트에 저장된 모든 콘텐츠를 화면에 출력
	void MakeEmpty(); // 리스트에 입력된 모든 내용을 삭제
	int ReadDataFromFile(); // 파일로부터 리스트 읽어오기
	int WriteDataToFile(); // 파일에 리스트 저장하기
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);

private:
	ifstream m_InFile; // 파일에 입력
	ofstream m_OutFile; // 파일에서 가져오기

	MasterList m_List; // item list
	int m_Command; // 현재 command 번호

};

#endif