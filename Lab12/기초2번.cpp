#include <iostream>
#include <string>
using namespace std;

// �Լ� �����ε� : int sum(int x, int y),
//					double sum(double x, double y),
//					float sum(float x, float y, float z)
// �Լ� �������̵� (����� Ư���� ��� ���)
// void Text::append(string _extra)
// void Fancy::append(string _extra)

class Text {
private:
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text {
private:
	// string text:b������ �� ��, Base Class���� private
	string left_brac;
	string right_brac;
	string connector;
public:
	// initialization list�� �����ڸ� ȣ���� �� �ְ� ���ش�.
	FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	// override Ű���� ����� get() �Լ� ����, main�Լ� �����Ͽ� ���ȭ��ó�� �ǵ��� ����
	// override Ű���� ����� append() �Լ� ����
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {}
};