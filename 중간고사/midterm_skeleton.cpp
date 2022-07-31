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

	/* �� �Է糪 Ȯ��
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

//������ ��������
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout;
	fout.open("students.txt"); //�����
	for (unsigned i = 0; i < studentIds.size(); i++) {
		fout << studentIds[i] << '\t' << passwords[i] << '\t' << names[i] << '\t' << credits[i] << '\t' << appliedLectureCodes[i].size() << '\t';
		for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++)
			fout << appliedLectureCodes[i][j] << '\t';
		fout << endl;
	}

	fout.close();
}

//������ ��������
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout;
	fout.open("lectures.txt"); //�����
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		fout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	}

	fout.close();
}

// �α��� : ��ȯ �� : ����� �Է� ���̵�
string getInputId() {
	string _id;
	cout << "���̵� : ";
	cin >> _id;

	return _id;
}

// �α��� : ��ȯ �� : ����� �Է� ��й�ȣ
string getInputPassword() {
	string _pw;
	cout << "��й�ȣ : ";
	cin >> _pw;

	return _pw;
}

//�л� �α��� : ��ȯ �� : ����(�л� ���̵� ���� �������� �ε���)
//                     ����(-1)
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
					cout << "�α��� " << ++failnum << "ȸ ���� (3ȸ ���н� ����)" << endl;
				}
			}
		}
		if (failnum == 3) {
			cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
			return -1;
			exit(100);
		}
	}
}

//������ �α��� : ��ȯ �� : ����(true), ����(false)
bool adminLogin() {
	/* ���� ȣ�� �Լ�: getInputId(), getInputPassword()*/
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
				cout << "�α��� " << ++failnum << "ȸ ���� (3ȸ ���н� ����)" << endl;
			}
		}
		if (failnum == 3) {
			cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
			return false;
			exit(100);
		}
	}
}

//��ü���� �α��� ������ �����ϴ� �Լ�
//��ȯ �� : �л� ����(�л� ���̵� ���� �������� �ε���)
//         ������ ����(-100, ����(-999)
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	/* ���� ȣ�� �Լ�: studentLogin(), adminLogin()*/
	cout << "-----------------------------------" << endl;
	cout << "1. �л� �α���" << endl;
	cout << "2. ������ �α���" << endl;
	cout << "3. ����" << endl;
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
	cout << "�����ڵ�" << '\t' << "���Ǹ�" << "\t\t" << "����" << '\t' << "���������ο�" << '\n';
	int temp = user + 1;

	if (temp > 0) { // ������ �л��� ��
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

//�л��߰�
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string _newstid;
	string _newstpw;
	string _newstname;
	while (1) {
		int check = 1;

		cout << "-------------------------------" << endl;
		cout << "�й� : ";
		cin >> _newstid;
		cout << "��й�ȣ : ";
		cin >> _newstpw;
		cout << "�л� �̸� : ";
		cin >> _newstname;
		cout << "-------------------------------" << endl;

		for (unsigned i = 0; i < studentIds.size(); i++) {
			if (_newstid == studentIds[i]) {
				cout << "�̹� �����ϴ� �й��Դϴ�." << endl;
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
			cout << "���������� ��ϵǾ����ϴ�." << endl;
			writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
			system("Pause");
		}
	}
}

//���� ����
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string _newleccode;
	string _newlecname;
	int _newleccred;
	int _newlimit;

	while (1) {
		int check = 1;

		cout << "-------------------------------" << endl;
		cout << "�����ڵ�: ";
		cin >> _newleccode;
		cout << "�����: ";
		cin >> _newlecname;
		cout << "����: ";
		cin >> _newleccred;
		cout << "�����ο�: ";
		cin >> _newlimit;
		cout << "-------------------------------" << endl;


		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			if (_newleccode == lectureCodes[i]) {
				cout << "�̹� �����ϴ� �����ڵ� �Դϴ�." << endl;
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
			cout << "���������� ���ǰ� �����Ǿ����ϴ�." << endl;
			system("Pause");
		}
	}

}

//���� ����
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* ���� ȣ�� �Լ�: printLectures*/
	string _delcode;
	// ���� lectureCodes, lectureNames, lectureCredits, limits
	// ȸ�� credits, appliedLectureCodes
	int check = 1;
	int index;
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
	cout << "������ ���� �ڵ� (0: �ڷΰ���) >>";
	cin >> _delcode;

	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		/*if (_delcode != lectureCodes[i]) {
			cout << "��ġ�ϴ� �ڵ尡 �����ϴ�." << endl;
			check = 0;
		}*/
		if (_delcode == lectureCodes[i]) {
			/*for (unsigned i = 0; i < lectureCodes.size(); i++) {
				if (_delcode == lectureCodes[i])
					index = i;
			}*/

			index = i;

			// �л����� ����
			for (unsigned i = 0; i < appliedLectureCodes.size(); i++) {
				for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++) {
					if (_delcode == appliedLectureCodes[i][j]) {
						credits[i] = credits[i] + lectureCredits[index]; // ���� +
						appliedLectureCodes[i].erase(appliedLectureCodes[i].begin() + j); // ���� �ڵ� ����
						break;
					}
				}
			}

			// ���� ��ü�� ����
			lectureCodes.erase(lectureCodes.begin() + index);
			lectureNames.erase(lectureNames.begin() + index);
			lectureCredits.erase(lectureCredits.begin() + index);
			limits.erase(limits.begin() + index);
		}
	}

}

//������ �޴��� �Ѱ�
//��ȯ�� : �α׾ƿ�(-1), ����(1)
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	/* ���� ȣ�� �Լ�: addStudent, addLecture, deleteLecture*/
	int select;
	cout << "-----------------------------------" << endl;
	cout << "1. �л� �߰�" << endl;
	cout << "2. ���� ����" << endl;
	cout << "3. ���� ����" << endl;
	cout << "4. �α׾ƿ�" << endl;
	cout << "0. ����" << endl;
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

//������ �л� ���� ���
//�й�, �̸�, ������������
//�л��޴����� ������û, ������Ȳ, ����öȸ �޴����� ȣ��
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "-------------------------------" << endl;
	cout << "�й�: " << studentIds[user] << '\t' << "�̸�: " << names[user] << "\t" << "������������: " << credits[user] << endl;
	cout << "-------------------------------" << endl;
}

//������û�� ó���ϴ� �Լ�
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	string _lec;
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
	cout << "��û�� ���� �ڵ�(0: �ڷΰ���) >> ";
	cin >> _lec;
	int check = 1;
	int index = 0;
	if (_lec != "0") {
		//_lec���� ���� �����ڵ� indexȮ��
		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			if (_lec == lectureCodes[i])
				index = i;
		}

		//���� �����ο��� 0�� ���
		if (limits[index] == 0) {
			cout << "�����ο��� �� á���ϴ�." << endl;
			system("Pause");
			check = 0;
		}

		//���� ���� ��п���
		if (credits[user] < lectureCredits[index]) {
			cout << "�������������� �����մϴ�." << endl;
			system("Pause");
			check = 0;
		}

		//���� �ڵ� �ߺ�����
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
			if (_lec == appliedLectureCodes[user][i]) {
				cout << "�̹� �ش� ������ ��û�߽��ϴ�" << endl;
				system("Pause");
				check = 0;
			}
		}

		//����� �ߺ� ����
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
			string idx_str = appliedLectureCodes[user][i]; // ������û�� �ڵ� GET
			int idx;

			for (unsigned j = 0; j < lectureCodes.size(); j++) {
				if (lectureCodes[j] == idx_str)
					idx = j;
			}

			if (lectureNames[index] == lectureNames[idx]) {
				cout << "�̹� ���ϸ��� ������ ��û�߽��ϴ�." << endl;
				system("Pause");
				check = 0;
			}
		}

		if (check == 1) {
			cout << "[" << _lec << "]" << " " << lectureNames[index] << "(��)�� ���������� ��û�Ͽ����ϴ�." << endl;
			appliedLectureCodes[user].push_back(_lec);
			credits[user] = credits[user] - lectureCredits[index];
			limits[index]--;
		}

		system("Pause");
	}
	else {
		cout << "�ȳ��� �輼��" << endl;
		exit(100);
	}
}

//���� öȸ
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
	string _str; // �Է¹��� öȸ�� ���� �ڵ�
	cout << "öȸ�� ���� �ڵ�(0: �ڷΰ���) >> ";
	cin >> _str;

	int index;

	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (_str == lectureCodes[i]) {
			index = i;
		}
	}

	for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
		if (_str == appliedLectureCodes[user][i]) {
			cout << "[" << _str << "] " << lectureNames[index] << "(��)�� öȸ�Ͽ����ϴ�." << endl;
			appliedLectureCodes[user].erase(appliedLectureCodes[user].begin() + i);
			credits[user] = credits[user] + lectureCredits[index];
			limits[index]++;
		}
		else {
			cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�." << endl;
			system("Pause");
			// �ƹ� Ű�� �Է� �� �ش� �޴��� �ӹ�����.
		}
	}
}


//��й�ȣ ����
void changePassword(vector<string>& passwords, const int& user) {
	string _pw;
	string _newpw;
	cout << "-------------------------------" << endl;
	cout << "���� Ȯ���� ���� ��й�ȣ�� �� �� �� �Է����ּ���." << endl;
	cout << "��й�ȣ: ";
	cin >> _pw;
	cout << "-------------------------------" << endl;
	cout << "-------------------------------" << endl;
	if (passwords[user] == _pw) {
		cout << "���� ������ ��й�ȣ�� �Է��ϼ���." << endl;
		cout << "��й�ȣ: ";
		cin >> _newpw;
		passwords[user] = _newpw;
		cout << "����Ǿ����ϴ�." << endl;
		system("Pause");
	}
	else {
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("Pause");
	}
}

//�л� �޴��� �Ѱ��ϴ� �Լ�
//��ȯ �� : �α׾ƿ�(-1), ����(1)
// �α׾ƿ� : �Լ����� main���� -1�� ��ȯ�Ѵ�.
// ���� : �Լ����� main���� 1�� ��ȯ�Ѵ�.
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	/* ���� ȣ�� �Լ�: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	cout << "-------------------------------" << endl;
	cout << "1. ���� ��û" << endl;
	cout << "2. ���� ��Ȳ" << endl;
	cout << "3. ���� öȸ" << endl;
	cout << "4. ��й�ȣ ����" << endl;
	cout << "5. �α׾ƿ�" << endl;
	cout << "0. ����" << endl;
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