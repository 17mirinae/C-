#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
	void print_base() { cout << "Base" << endl; }
};

// Base Type | ��� Type | Derived Type
// private | ������� | ���� �Ұ� (Base�Լ��� ����)
// protected | ������� | private
// public | private / protected | private
// public | public | public

class Derived :private Base {
public:
	void print_derived() {
		print_base();
		cout << "Derived" << endl;
	}
};

int main_b() {
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}