#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
using namespace std;

#include "ItemType.h"
#include "SortedLinkedList.h"
#include "SortedArrayList.h"
#include "deptType.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_nCurCommand = 0;
	}

	/**
	*	destructor.
	*/
	~Application()
	{
	}
	
	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int InsertItem();

	/**
	*	@brief	Delete record into list.
	*	@pre	list should be not empty.
	*	@post	record is deleted into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int DeleteItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();

	/**
	*	@brief	Make empty list.
	*	@pre	none.
	*	@post	Make empty list in this member.
	*/
	int MakeEmpty();

	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveItem();

	/**
	*	@brief	Change item's value in the list.
	*	@pre	none.
	*	@post	target item's value is changed.
	*	@return	1 if succeeded changing item's value, otherwise 0.
	*/
	int Update();

		/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();


	/**
	*	@brief	Add new record into master list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the master list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddMasterList();

	/**
	*	@brief	Add new record into dept list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the dept list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddDeptList();

	/*
	학과 검색 : deptList에 입력된 학과를 찾아서 해당 학과에 소속된 학생들의
	학번을 차례대로 읽어서 학생들의 자세한 정보를 masterList에서 찾아 화면에 출력
	*/


	// KB로 입력받은 name과 같은 이름을 deptList에서 찾기
	deptType* searchDeptByName(string name);
	void printStudentsFromDept(deptType* dept);
	void searchFromMasterList();


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedLinkedList<ItemType> m_List;	///< Linked-list for ItemType.
	int m_nCurCommand;	///< current command number

	SortedArrayList<ItemType> masterList; // 학생 리스트
	SortedLinkedList<deptType> deptList; // 학과 리스트
};

#endif
