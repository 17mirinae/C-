#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
#include <string>
using namespace std;

#include "DoublyLinkedList.h"

#include "ItemType.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
private:
	int m_nCurCommand;	///< current command number

	DoublyLinkedList<ItemType*> m_Contents;	// 콘텐츠 리스트

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
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();


	/**
	*	@brief	Read()함수를 이용하여 여러개의 콘텐츠를 MasterList에 저장.
	*	@pre	생성된 객체
	*	@post	제대로 저장되면 1반환,
	*/
	int AddContents(ItemType item);
};

#endif
