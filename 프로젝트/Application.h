#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
using namespace std;

#include "ItemType.h"
#include "SortedLinkedList.h"
#include "SortedArrayList.h"
#include "EventType.h"
#include "PeopleType.h"
#include "PlaceType.h"
#include "FavType.h"

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
	int SearchTime();// 생성시간 순으로 검색 및 저장
	int SearchEvent(); // event별로 검색 및 저장
	int SearchPeople(); // 사람별로 검색 및 저장
	int SearchPlace(); // 장소별로 검색 및 저장
	int BothType(); // 하나 이상의 키 조합 검색
	
	
private:
	SortedLinkedList<ItemType> m_Contents;	// 콘텐츠 리스트
	int m_nCurCommand;	///< current command number

	SortedArrayList<EventType> eventList; // 이벤트 리스트
	SortedArrayList<PeopleType> peopleList; // 사람 리스트
	SortedArrayList<PlaceType> placeList; // 장소 리스트
	SortedArrayList<FavType> favPicList; // 자주보는 사진 리스트
	SortedArrayList<FavType> favVidList; // 자주보는 동영상 리스트
};

#endif