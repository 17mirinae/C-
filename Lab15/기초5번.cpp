#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// 예외처리: try/catch 구문, throw 문
// 1. 예외가 발생하는 부분을 try 에 넣는다.
// 2. 예외가 발생하면 catch 구문이 실행된다.
class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};
vector<int> load_vector(string filename) {
	ifstream fin(filename);

	// 파일이 열리지 않으면(파일이 존재하지x)
	if (!fin) {
		// 예외처리 (throw)
		throw FileNotFoundException(filename);
	}

	vector<int> result;
	int num, value;
	// 파일로부터 값을 result 에 저장
	// 파일의 form: size, elements (5 1 2 3 4 4)
	fin >> num;
	for (int i = 0; i < num; i++) {
		fin >> value;
		result.push_back(value);
	}
	return result;
}
int main_c() {
	try {
		vector<int> v;
		v = load_vector("values.dat");
		// values.dat 파일에서 vector 로드
		for (int elem : v)
			cout << elem << ' ';
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}