#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main_e() {
	vector<int> list;
	// vector 를 1~100 사이의 random 한 크기로 만들고 채우는 코드 구현
	srand((unsigned int)time(0));

	int num = rand() % 45;

	for (int i = 0; i < num; i++) {
		list.push_back(i);
	}

	int cnt = -1;
	while (1) {
		cnt++;
		try {
			if (cnt == list.size()) {
				throw cnt;
			}
		}
		catch (int cnt) {
			cout << "현재 list는 " << cnt << "의 크기를 가지고 있다." << endl;
			break;
		}
	}

	return 0;
}