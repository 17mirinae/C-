#include <iostream>
#include <string>

using namespace std;

template <typename T>
T multiple(T x, T y) {
    return x * y;
}

template <typename T>
T divide(T x, T y) {
    return x / y;
}

int main()
{
    int num1 = 10, num2 = 20;
    
    double num3 = 10.52, num4 = 20.24;
    
    cout << multiple(num3, num4) << endl;
    cout << divide(num3, num4) << endl;
    cout << multiple(num1, num2) << endl;
    cout << divide(num1, num2) << endl;

    return 0;
}