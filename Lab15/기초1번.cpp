#include <iostream>
using namespace std;

int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int, int), int x, int y) {
	return f(x, y);
}

int main_a() {
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;

	// lambda 함수: [](입력변수)->리턴타입 {본문}
	// sum(): [](int x, int y)->int { return x + y; }
	//cout << evaluate(/* 구현 */, 20, 30) << endl;

	// simplified lambda 함수 표현: [](입력변수) {본문}
	// mult(): [](int x, int y) { return x * y; }
	//cout << evaluate(/*구현*/, 20, 30) << endl;

	//생성과 호출을 동시에: 람다함수(입력값)
	//[](/*구현*/) {/*구현*/}(20, 30);

	auto f = [](int x, int y) { return x - y; };
	cout << f(1000, 2000) << endl;

	return 0;
}