#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <string>

using namespace std;


/**
*	item information class.
*/
class ItemType
{
private:
	string name; //콘텐츠 이름(PK)
	int time; // 콘텐츠 생성시간
	string event; // 이벤트명
	string people; // 사람명
	string place; // 장소명
	string type; // 콘텐츠타입(ex)picture, video, music)

public:
	// 생성자
	ItemType() {
		name = "";
		time = 0;
	}

	~ItemType() {} // 소멸자

	/**
	*	@brief	Get name.
	*	@pre	name is set.
	*	@post	none.
	*	@return	name.
	*/
	string GetName() { return name; }

	/**
	*	@brief	Get event.
	*	@pre	time is set.
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
	*	@brief	Get Type
	*	@pre	Type is set.
	*	@post	none.
	*	@return	Type.
	*/
	string GetType() { return type; }

	/**
	*	@brief	Set name.
	*	@pre	inname
	*	@post	name is set.
	*	@param	inname = name.
	*/
	void SetName(string inname) { name = inname; }

	/**
	*	@brief	Set time.
	*	@pre	intime
	*	@post	time is set.
	*	@param	intime	time.
	*/
	void SetTime(int intime) { time = intime; }

	/**
	*	@brief	Set event.
	*	@pre	inEvent
	*	@post	event is set.
	*	@param	inEvent	event.
	*/
	void SetEvent(string inEvent) { event = inEvent; }

	/**
	*	@brief	Set people.
	*	@pre	inPeople
	*	@post	people is set.
	*	@param	inPeo	people.
	*/
	void SetPeople(string inPeo) { people = inPeo; }

	/**
	*	@brief	Set place.
	*	@pre	inPlace
	*	@post	place is set.
	*	@param	inPlace	place.
	*/
	void SetPlace(string inPlace) { place = inPlace; }

	/**
	*	@brief	Set type.
	*	@pre	inType
	*	@post	type is set.
	*	@param	inType	type.
	*/
	void SetType(string inType) { type = inType; }

	/**
	*	@brief	Set Multimedia Contents
	*	@pre	inname, intime, inEvent,inPeo,inPlace
	*	@post	Multimedia Contents is set.
	*/
	void SetRecord(string inname, int intime, string inEvent, string inPeo, string inPlace, string inType)
	{
		SetName(inname);
		SetTime(intime);
		SetEvent(inEvent);
		SetPeople(inPeo);
		SetPlace(inPlace);
		SetType(inType);
	}

	/**
	*	@brief	Display name on screen.
	*	@pre	name is set.
	*	@post	name is on screen.
	*/
	void DisplayNameOnScreen() {
		cout << "\tName   : " << name << endl;
	};

	/**
	*	@brief	Display time on screen.
	*	@pre	time is set.
	*	@post	time is on screen.
	*/
	void DisplayTimeOnScreen() {
		cout << "\tTime   : " << time << endl;
	};

	/**
	*	@brief	Display event on screen.
	*	@pre	Event is set.
	*	@post	Event is on screen.
	*/
	void DisplayEventOnScreen() {
		cout << "\tEvent : " << event << endl;
	};

	/**
	*	@brief	Display people on screen.
	*	@pre	people is set.
	*	@post	people is on screen.
	*/
	void DisplayPeopleOnScreen() {
		cout << "\tPeople : " << people << endl;
	};

	/**
	*	@brief	Display place on screen.
	*	@pre	place is set.
	*	@post	place is on screen.
	*/
	void DisplayPlaceOnScreen() {
		cout << "\tPeople : " << people << endl;
	};

	/**
	*	@brief	Display type on screen.
	*	@pre	type is set.
	*	@post	type is on screen.
	*/
	void DisplaTypeOnScreen() {
		cout << "\tType : " << type << endl;
	};

	/**
	*	@brief	Display an content record on screen.
	*	@pre	contents record is set.
	*	@post	contents record is on screen.
	*/
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayTimeOnScreen();
		DisplayEventOnScreen();
		DisplayPeopleOnScreen();
		DisplayPlaceOnScreen();
		DisplaTypeOnScreen();
	};

	/**
	*	@brief	Set name from keyboard.
	*	@pre	none.
	*	@post	name is set.
	*/
	void SetNameFromKB() {

		cout << "\tName : ";
		cin >> name;
	}

	/**
	*	@brief	Set time from keyboard.
	*	@pre	none.
	*	@post	time is set.
	*/
	void SetTimeFromKB() {

		cout << "\tTime(생성 순서대로 index번호(1부터~) : ";
		cin >> time;
	}

	/**
	*	@brief	Set event from keyboard.
	*	@pre	none.
	*	@post	event is set.
	*/
	void SetEventFromKB() {
		cout << "\tEvent : ";
		cin >> event;
	}

	/**
	*	@brief	Set people from keyboard.
	*	@pre	none.
	*	@post	people is set.
	*/
	void SetPeopleFromKB() {
		cout << "\tPeople : ";
		cin >> people;
	}

	/**
	*	@brief	Set place from keyboard.
	*	@pre	none.
	*	@post	place is set.
	*/
	void SetPlaceFromKB() {
		cout << "\tPlace : ";
		cin >> place;
	}

	/**
	*	@brief	Set type from keyboard.
	*	@pre	none.
	*	@post	type is set.
	*/
	void SetTypeFromKB() {
		cout << "\tType : ";
		cin >> type;
	}

	/**
	*	@brief	Set multimedia contents from keyboard.
	*	@pre	none.
	*	@post	multimedia contents is set.
	*/
	void SetRecordFromKB() {
		SetNameFromKB();
		SetTimeFromKB();
		SetEventFromKB();
		SetPeopleFromKB();
		SetPlaceFromKB();
		SetTypeFromKB();
	}

	//연산자 오버로딩
	bool operator == (ItemType& item) {
		if (this->name == item.GetName()) //콘텐츠이름으로 비교
			return true;
		return false;
	}

	//연산자 오버로딩
	bool operator < (ItemType& item) {
		return (this->name < item.GetName());
	}

	//연산자 오버로딩
	bool operator > (ItemType& item) {
		return (this->name > item.GetName());
	}

	//연산자 오버로딩을 통해 데이터를 대입
	void operator=(ItemType& item) {
		this->name = item.GetName();
		this->time = item.GetTime();
		this->event = item.GetEvent();
		this->people = item.GetPeople();
		this->place = item.GetPlace();
		this->type = item.GetType();
	}
	
	virtual void play() = 0; // 순수 가상 함수로 선언

	virtual void Read() = 0; // 순수 가상 함수로 선언
	
};

class Picture : public ItemType
{
private:
	int picid;
public:
	Picture() {
		picid = 0;
	}
	virtual void play()
	{
		DisplayRecordOnScreen();
		cout << "사진아이디 : " << picid << endl;
		cout << "사진 콘텐츠가 호출되었습니다." << endl;
	}
	virtual void Read()
	{
		Picture pic;
		pic.SetRecordFromKB();
		cout << "사진 아이디를 입력해주세요 : ";
		cin >> picid;
	}
};

class Video : public ItemType
{
private:
	int vidid;
public:
	virtual void play()
	{
		DisplayRecordOnScreen();
		cout << "비디오 아이디 : " << vidid << endl;
		cout << "비디오 콘텐츠가 호출되었습니다."<<endl;
	}
	virtual void Read()
	{
		Video video;
		video.SetRecordFromKB();
		cout << "비디오 아이디를 입력해주세요 : ";
		cin >> vidid;
	}
};

class Music : public ItemType
{
private:
	int musid;
public:
	virtual void play()
	{
		DisplayRecordOnScreen();
		cout << "음악 아이디 : " << musid << endl;
		cout << "음악 콘텐츠가 호출되었습니다."<<endl;
	}
	virtual void Read()
	{
		Music music;
		music.SetRecordFromKB();
		cout << "음악 아이디를 입력해주세요 : ";
		cin >> musid;
	}
};


#endif	// _ITEMTYPE_H

