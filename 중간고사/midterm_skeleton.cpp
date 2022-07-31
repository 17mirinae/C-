#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			break;
		}
		else if (user == -1) { // Exit command
			break;
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}

	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (lectureCodes[i] == code)
			return i;
	}
	return -1;
}

void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin("students.txt");

	while (true) {
		string _str;
		int _int;
		fin >> _str;
		if (!fin)
			break;
		studentIds.push_back(_str);
		fin >> _str;
		passwords.push_back(_str);
		fin >> _str;
		names.push_back(_str);
		fin >> _int;
		credits.push_back(_int);

		fin >> _int;
		int num = _int;
		vector<string> v;
		for (int i = 0; i < num; i++) {
			fin >> _str;
			v.push_back(_str);
		}
		appliedLectureCodes.push_back(v);

	}

	/* 잘 입력됬나 확인
	for (int i = 0; i < studentIds.size(); i++) {
	   cout << studentIds[i] << " " << passwords[i] << " " << names[i] << " " << credits[i];
	   cout << endl;
	}
	cout << endl;

	for (const vector<string>& v : appliedLectureCodes) {
	   for (auto elem : v)
		  cout << "  " << elem;
	   cout << endl;
	}
	cout << appliedLectureCodes.size() << endl;
	*/


	fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin("lectures.txt");
	while (true) {
		string _str;
		int _int;
		fin >> _str;
		if (!fin)
			break;
		lectureCodes.push_back(_str);
		fin >> _str;
		lectureNames.push_back(_str);
		fin >> _int;
		lectureCredits.push_back(_int);
		fin >> _int;
		limits.push_back(_int);
	}

	fin.close();
}

//데이터 내보내기
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout;
	fout.open("students.txt"); //덮어쓰기
	for (unsigned i = 0; i < studentIds.size(); i++) {
		fout << studentIds[i] << '\t' << passwords[i] << '\t' << names[i] << '\t' << credits[i] << '\t' << appliedLectureCodes[i].size() << '\t';
		for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++)
			fout << appliedLectureCodes[i][j] << '\t';
		fout << endl;
	}

	fout.close();
}

//데이터 내보내기
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout;
	fout.open("lectures.txt"); //덮어쓰기
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		fout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	}

	fout.close();
}

// 로그인 : 반환 값 : 사용자 입력 아이디
string getInputId() {
	string _id;
	cout << "아이디 : ";
	cin >> _id;

	return _id;
}

// 로그인 : 반환 값 : 사용자 입력 비밀번호
string getInputPassword() {
	string _pw;
	cout << "비밀번호 : ";
	cin >> _pw;

	return _pw;
}

//학생 로그인 : 반환 값 : 성공(학생 아이디 벡터 내에서의 인덱스)
//                     실패(-1)
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	string stuid, stupw;
	int failnum = 0;

	while (true) {
		stuid = getInputId();
		stupw = getInputPassword();
		for (unsigned i = 0; i < studentIds.size(); i++) {
			if (stuid == studentIds[i]) {
				if (stupw == passwords[i]) {
					return i;
				}
				else {
					cout << "로그인 " << ++failnum << "회 실패 (3회 실패시 종료)" << endl;
				}
			}
		}
		if (failnum == 3) {
			cout << "3회 실패하여 종료합니다." << endl;
			return -1;
			exit(100);
		}
	}
}

//관리자 로그인 : 반환 값 : 성공(true), 실패(false)
bool adminLogin() {
	/* 내부 호출 함수: getInputId(), getInputPassword()*/
	string adid, adpw;
	int failnum = 0;

	while (true) {
		adid = getInputId();
		adpw = getInputPassword();
		if (adid == "admin") {
			if (adpw == "admin") {
				return true;
			}
			else {
				cout << "로그인 " << ++failnum << "회 실패 (3회 실패시 종료)" << endl;
			}
		}
		if (failnum == 3) {
			cout << "3회 실패하여 종료합니다." << endl;
			return false;
			exit(100);
		}
	}
}

//전체적인 로그인 과정을 관리하는 함수
//반환 값 : 학생 성공(학생 아이디 벡터 내에서의 인덱스)
//         관리자 성공(-100, 실패(-999)
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	/* 내부 호출 함수: studentLogin(), adminLogin()*/
	cout << "-----------------------------------" << endl;
	cout << "1. 학생 로그인" << endl;
	cout << "2. 관리자 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "-----------------------------------" << endl;

	int select, _user;

	cout << ">>";
	cin >> select;
	switch (select) {
	case 1:
		_user = studentLogin(studentIds, passwords);
		break;
	case 2:
		_user = adminLogin();
		if (_user)
			_user = -100;
		else
			_user = -999;
		break;
	case 3:
		return -1;
	}

	//system("Pause");

	return _user;
}


void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	cout << "-------------------------------" << endl;
	cout << "과목코드" << '\t' << "강의명" << "\t\t" << "학점" << '\t' << "수강가능인원" << '\n';
	int temp = user + 1;

	if (temp > 0) { // 무조건 학생일 때
		int idx;
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
			for (unsigned j = 0; j < lectureCodes.size(); j++) {
				if (lectureCodes[j] == appliedLectureCodes[user][i]) {
					idx = j;
					cout << lectureCodes[idx] << '\t' << lectureNames[idx] << '\t' << lectureCredits[idx] << '\t' << limits[idx] << endl;
				}
			}
		}
	}
	else {
		for (unsigned i = 0; i < lectureCodes.size(); i++)
			cout << lectureCodes[i] << " " << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << '\n';
	}
	cout << "-------------------------------" << endl;
}

//학생추가
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string _newstid;
	string _newstpw;
	string _newstname;
	while (1) {
		int check = 1;

		cout << "-------------------------------" << endl;
		cout << "학번 : ";
		cin >> _newstid;
		cout << "비밀번호 : ";
		cin >> _newstpw;
		cout << "학생 이름 : ";
		cin >> _newstname;
		cout << "-------------------------------" << endl;

		for (unsigned i = 0; i < studentIds.size(); i++) {
			if (_newstid == studentIds[i]) {
				cout << "이미 존재하는 학번입니다." << endl;
				check = 0;
				system("Pause");
			}
		}
		if (check == 1) {
			studentIds.push_back(_newstid);
			passwords.push_back(_newstpw);
			names.push_back(_newstname);
			credits.push_back(18);
			vector<string> vec;
			appliedLectureCodes.push_back(vec);
			cout << "성공적으로 등록되었습니다." << endl;
			writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
			system("Pause");
		}
	}
}

//강의 개설
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string _newleccode;
	string _newlecname;
	int _newleccred;
	int _newlimit;

	while (1) {
		int check = 1;

		cout << "-------------------------------" << endl;
		cout << "과목코드: ";
		cin >> _newleccode;
		cout << "과목명: ";
		cin >> _newlecname;
		cout << "학점: ";
		cin >> _newleccred;
		cout << "수강인원: ";
		cin >> _newlimit;
		cout << "-------------------------------" << endl;


		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			if (_newleccode == lectureCodes[i]) {
				cout << "이미 존재하는 과목코드 입니다." << endl;
				check = 0;
				system("Pause");
			}
		}
		if (check == 1) {
			lectureCodes.push_back(_newleccode);
			lectureNames.push_back(_newlecname);
			lectureCredits.push_back(_newleccred);
			limits.push_back(_newlimit);
			writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);
			cout << "성공적으로 강의가 개설되었습니다." << endl;
			system("Pause");
		}
	}

}

//강의 삭제
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* 내부 호출 함수: printLectures*/
	string _delcode;
	// 강의 lectureCodes, lectureNames, lectureCredits, limits
	// 회원 credits, appliedLectureCodes
	int check = 1;
	int index;
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
	cout << "삭제할 강의 코드 (0: 뒤로가기) >>";
	cin >> _delcode;

	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		/*if (_delcode != lectureCodes[i]) {
			cout << "일치하는 코드가 없습니다." << endl;
			check = 0;
		}*/
		if (_delcode == lectureCodes[i]) {
			/*for (unsigned i = 0; i < lectureCodes.size(); i++) {
				if (_delcode == lectureCodes[i])
					index = i;
			}*/

			index = i;

			// 학생에서 삭제
			for (unsigned i = 0; i < appliedLectureCodes.size(); i++) {
				for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++) {
					if (_delcode == appliedLectureCodes[i][j]) {
						credits[i] = credits[i] + lectureCredits[index]; // 학점 +
						appliedLectureCodes[i].erase(appliedLectureCodes[i].begin() + j); // 강의 코드 삭제
						break;
					}
				}
			}

			// 강의 자체를 삭제
			lectureCodes.erase(lectureCodes.begin() + index);
			lectureNames.erase(lectureNames.begin() + index);
			lectureCredits.erase(lectureCredits.begin() + index);
			limits.erase(limits.begin() + index);
		}
	}

}

//관리자 메뉴를 총괄
//반환값 : 로그아웃(-1), 종료(1)
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	/* 내부 호출 함수: addStudent, addLecture, deleteLecture*/
	int select;
	cout << "-----------------------------------" << endl;
	cout << "1. 학생 추가" << endl;
	cout << "2. 강의 개설" << endl;
	cout << "3. 강의 삭제" << endl;
	cout << "4. 로그아웃" << endl;
	cout << "0. 종료" << endl;
	cout << "-----------------------------------" << endl;
	cout << ">>";
	cin >> select;
	switch (select) {
	case 1:
		addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
		break;
	case 2:
		addLecture(lectureCodes, lectureNames, lectureCredits, limits);
		break;
	case 3:
		deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
		writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
		writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);
		break;
	case 4:
		system("cls");
		return -1;
	case 5:
		return 1;
	}
}

//간단한 학생 정보 출력
//학번, 이름, 수강가능학점
//학생메뉴에서 수강신청, 수강현황, 수강철회 메뉴에서 호출
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "-------------------------------" << endl;
	cout << "학번: " << studentIds[user] << '\t' << "이름: " << names[user] << "\t" << "수강가능학점: " << credits[user] << endl;
	cout << "-------------------------------" << endl;
}

//수강신청을 처리하는 함수
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	string _lec;
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
	cout << "신청할 과목 코드(0: 뒤로가기) >> ";
	cin >> _lec;
	int check = 1;
	int index = 0;
	if (_lec != "0") {
		//_lec으로 받은 과목코드 index확인
		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			if (_lec == lectureCodes[i])
				index = i;
		}

		//수강 가능인원이 0인 경우
		if (limits[index] == 0) {
			cout << "수강인원이 꽉 찼습니다." << endl;
			system("Pause");
			check = 0;
		}

		//수강 학점 충분여부
		if (credits[user] < lectureCredits[index]) {
			cout << "수강가능학점이 부족합니다." << endl;
			system("Pause");
			check = 0;
		}

		//과목 코드 중복여부
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
			if (_lec == appliedLectureCodes[user][i]) {
				cout << "이미 해당 과목을 신청했습니다" << endl;
				system("Pause");
				check = 0;
			}
		}

		//과목명 중복 여부
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
			string idx_str = appliedLectureCodes[user][i]; // 수강신청한 코드 GET
			int idx;

			for (unsigned j = 0; j < lectureCodes.size(); j++) {
				if (lectureCodes[j] == idx_str)
					idx = j;
			}

			if (lectureNames[index] == lectureNames[idx]) {
				cout << "이미 동일명의 과목을 신청했습니다." << endl;
				system("Pause");
				check = 0;
			}
		}

		if (check == 1) {
			cout << "[" << _lec << "]" << " " << lectureNames[index] << "(을)를 성공적으로 신청하였습니다." << endl;
			appliedLectureCodes[user].push_back(_lec);
			credits[user] = credits[user] - lectureCredits[index];
			limits[index]--;
		}

		system("Pause");
	}
	else {
		cout << "안녕히 계세요" << endl;
		exit(100);
	}
}

//수강 철회
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
	string _str; // 입력받을 철회할 과목 코드
	cout << "철회할 과목 코드(0: 뒤로가기) >> ";
	cin >> _str;

	int index;

	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (_str == lectureCodes[i]) {
			index = i;
		}
	}

	for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
		if (_str == appliedLectureCodes[user][i]) {
			cout << "[" << _str << "] " << lectureNames[index] << "(을)를 철회하였습니다." << endl;
			appliedLectureCodes[user].erase(appliedLectureCodes[user].begin() + i);
			credits[user] = credits[user] + lectureCredits[index];
			limits[index]++;
		}
		else {
			cout << "과목 코드가 올바르지 않습니다." << endl;
			system("Pause");
			// 아무 키나 입력 시 해당 메뉴에 머무른다.
		}
	}
}


//비밀번호 변경
void changePassword(vector<string>& passwords, const int& user) {
	string _pw;
	string _newpw;
	cout << "-------------------------------" << endl;
	cout << "본인 확인을 위해 비밀번호를 한 번 더 입력해주세요." << endl;
	cout << "비밀번호: ";
	cin >> _pw;
	cout << "-------------------------------" << endl;
	cout << "-------------------------------" << endl;
	if (passwords[user] == _pw) {
		cout << "새로 설정할 비밀번호를 입력하세요." << endl;
		cout << "비밀번호: ";
		cin >> _newpw;
		passwords[user] = _newpw;
		cout << "변경되었습니다." << endl;
		system("Pause");
	}
	else {
		cout << "비밀번호가 일치하지 않습니다." << endl;
		system("Pause");
	}
}

//학생 메뉴를 총괄하는 함수
//반환 값 : 로그아웃(-1), 종료(1)
// 로그아웃 : 함수에서 main으로 -1을 반환한다.
// 종료 : 함수에서 main으로 1을 반환한다.
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	/* 내부 호출 함수: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	cout << "-------------------------------" << endl;
	cout << "1. 수강 신청" << endl;
	cout << "2. 수강 현황" << endl;
	cout << "3. 수강 철회" << endl;
	cout << "4. 비밀번호 변경" << endl;
	cout << "5. 로그아웃" << endl;
	cout << "0. 종료" << endl;
	cout << "------------------------------" << endl;

	int select;
	cout << ">>";
	cin >> select;

	switch (select) {
	case 0:
		return 1;
	case 1:
		applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		break;
	case 2:
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		break;
	case 3:
		disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		break;
	case 4:
		changePassword(passwords, user);
		break;
	case 5:
		system("cls");
		return -1;
	}

	return 0;
}