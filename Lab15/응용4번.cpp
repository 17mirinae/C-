#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

class FileNotFoundException : public exception {
	string message; //Identifies the exception and filename
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}

	virtual const char* what() const throw() {
		return message.c_str();
	}
};

vector<vector<int>> read_file(string str) {
	ifstream fin(str);
	vector<vector<int>> result(10, vector<int>(10));

	if (!fin) {
		throw FileNotFoundException(str);
	}

	while (!fin.eof()) {
		for (auto& row : result) {
			for (auto& elem : row) {
				fin >> elem;
			}
		}
	}

	return result;
}

void print_file(vector<vector<int>>& vec, int row, int col) {
	for (int i = 0; i < row; i++) {
		vector<int> temp_vec = vec.at(i);
		for (int j = 0; j < col; j++) {
			cout << temp_vec.at(j) << " ";
		}
		cout << endl;
	}
}

int main() {
	ofstream ofs("temp.txt");
	vector<vector<int>> set(10, vector<int>(10));
	
	srand((unsigned int)time(0));

	for (auto& row : set) {
		for (auto& elem : row) {
			elem = rand() % 101;
			ofs << elem << " ";
		}
		ofs << endl;
	}

	// ������ 10x10 ��� ���� ����
	ofs.close();

	try {
		// �����̸� �Է�
		// �Է¹��� �����̸��� �´� ������ �о�� vector �� �Է� ��, ��� ����
		string filename;
		int row = 0, col = 0;

		cout << "���� �̸� : ";
		cin >> filename;

		ifstream fin(filename);

		if (!fin) {
			throw FileNotFoundException(filename);
		}

		cout << "��� �� ũ�� : ";
		cin >> row;

		cout << "��� �� ũ�� : ";
		cin >> col;
	
		vector<vector<int>> num = read_file(filename);
		print_file(num, row, col);
	}
	catch (FileNotFoundException& e) {
		cout << e.what() << endl;
	}
	catch (exception& e) {
		cout << endl;
		cout << e.what() << endl;
	}

	return 0;
}