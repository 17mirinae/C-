#include <iostream>
#include <vector>
using namespace std;

int main_d() {
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num; // 출력할 list의 수
	while (1) {
		cout << "출력 할 숫자의 수 : ";
		cin >> num;

		try {
			if (num <= 0) {
				throw -1;
			}
			else if (num > list.size()) {
				for (int elem : list)
					cout << elem << ' ';
				cout << endl;
				throw -1;
			}

			for (int i = 0; i < num; i++) {
				cout << list[i] << ' ';
			}
			cout << endl;
		}
		catch (int exce) {
			cout << "Index is out of range. Please try again." << endl;
			cout << "출력 할 숫자의 수 : " << exce << endl;
			break;
		}
	}
	cout << "Program exit..." << endl;
	return 0;
}