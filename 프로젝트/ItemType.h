#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	Relation between two items.
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/
class ItemType
{
public:
	// 생성자
	ItemType(){}

	~ItemType()	{} // 소멸자

	/**
	*	@brief	Get event.
	*	@pre	event is set.
	*	@post	none.
	*	@return	event.
	*/
	int GetTime() { return time; }

	/**
	*	@brief	Get event.
	*	@pre	event is set.
	*	@post	none.
	*	@return	event.
	*/
	string GetEvent() { return event; }

	/**
	*	@brief	Get poople.
	*	@pre	peopleis set.
	*	@post	none.
	*	@return	people.
	*/
	string GetPeople() { return people; }

	/**
	*	@brief	Get Place
	*	@pre	Place is set.
	*	@post	none.
	*	@return	Place.
	*/
	string GetPlace() { return place; }

	/**
	*	@brief	Set time.
	*	@pre	none.
	*	@post	time is set.
	*	@param	intime	time.
	*/
	void SetTime(int intime) { intime = time; }
	
	/**
	*	@brief	Set event.
	*	@pre	none.
	*	@post	event is set.
	*	@param	inEvent	event.
	*/
	void SetEvent(string inEvent) { inEvent = event; }
	
	/**
	*	@brief	Set people.
	*	@pre	none.
	*	@post	people is set.
	*	@param	inPeo	people.
	*/
	void SetPeople(string inPeo) { inPeo = people; }
	
	/**
	*	@brief	Set place.
	*	@pre	none.
	*	@post	place is set.
	*	@param	inPlace	place.
	*/
	void SetPlace(string inPlace) { inPlace = place; }

	/**
	*	@brief	Set Multimedia Contents
	*	@pre	none.
	*	@post	Multimedia Contents is set.
	*	@param		student id.
	*	@param	inName	student name.
	*	@param	inAddress	student address.
	*/
	void SetRecord(int intime, string inEvent, string inPeo, string inPlace)
	{
		SetTime(intime);
		SetEvent(inEvent);
		SetPeople(inPeo);
		SetPlace(inPlace);

	}
	/**
	*	@brief	Set multimedia contents from keyboard.
	*	@pre	none.
	*	@post	multimedia contents is set.
	*/
	void SetRecordFromKB();

protected:
	int time; // 생성시간
	string event; // 이벤트명
	string people; // 사람명
	string place; // 장소명

};

#endif	// _ITEMTYPE_H