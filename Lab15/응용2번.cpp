#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main_e() {
	vector<int> list;
	// vector �� 1~100 ������ random �� ũ��� ����� ä��� �ڵ� ����
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
			cout << "���� list�� " << cnt << "�� ũ�⸦ ������ �ִ�." << endl;
			break;
		}
	}

	return 0;
}