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
	string name; //������ �̸�(PK)
	int time; // ������ �����ð�
	string event; // �̺�Ʈ��
	string people; // �����
	string place; // ��Ҹ�
	string type; // ������Ÿ��(ex)picture, video, music)

public:
	// ������
	ItemType() {
		name = "";
		time = 0;
	}

	~ItemType() {} // �Ҹ���

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

		cout << "\tTime(���� ������� index��ȣ(1����~) : ";
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

	//������ �����ε�
	bool operator == (ItemType& item) {
		if (this->name == item.GetName()) //�������̸����� ��
			return true;
		return false;
	}

	//������ �����ε�
	bool operator < (ItemType& item) {
		return (this->name < item.GetName());
	}

	//������ �����ε�
	bool operator > (ItemType& item) {
		return (this->name > item.GetName());
	}

	//������ �����ε��� ���� �����͸� ����
	void operator=(ItemType& item) {
		this->name = item.GetName();
		this->time = item.GetTime();
		this->event = item.GetEvent();
		this->people = item.GetPeople();
		this->place = item.GetPlace();
		this->type = item.GetType();
	}
	
	virtual void play() = 0; // ���� ���� �Լ��� ����

	virtual void Read() = 0; // ���� ���� �Լ��� ����
	
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
		cout << "�������̵� : " << picid << endl;
		cout << "���� �������� ȣ��Ǿ����ϴ�." << endl;
	}
	virtual void Read()
	{
		Picture pic;
		pic.SetRecordFromKB();
		cout << "���� ���̵� �Է����ּ��� : ";
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
		cout << "���� ���̵� : " << vidid << endl;
		cout << "���� �������� ȣ��Ǿ����ϴ�."<<endl;
	}
	virtual void Read()
	{
		Video video;
		video.SetRecordFromKB();
		cout << "���� ���̵� �Է����ּ��� : ";
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
		cout << "���� ���̵� : " << musid << endl;
		cout << "���� �������� ȣ��Ǿ����ϴ�."<<endl;
	}
	virtual void Read()
	{
		Music music;
		music.SetRecordFromKB();
		cout << "���� ���̵� �Է����ּ��� : ";
		cin >> musid;
	}
};


#endif	// _ITEMTYPE_H

