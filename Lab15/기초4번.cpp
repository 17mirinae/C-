#include <iostream>
#include <vector>
using namespace std;
int main_b() {
	vector<int> v{ 1, 2, 3, 4 };

	int index;
	cin >> index;
	try {
		if (v.at(index) == v[index])
			cout << v[index] << endl;
		else
			throw v;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << "ÀÎµ¦½º ¿¡·¯" << endl;
	}

	cout << "[Program is running]" << endl;
	return 0;
}