#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;


class Base
{
public:
	int value1;
	int value2;

    Base() { value1 = 1; };

    //使用该构造函数调用另一个构造函数Base()，即委托构造
    Base(int value) :Base() { value2 = value; };
	virtual ~Base() {};

private:

};


class SubClass : public Base {
private:

public:
    //继承构造，继承Base的委托构造。
    using Base::Base;//相似于 SubClass(int value):Base(value) {};
    
    SubClass() = delete;
    
};



int main(int agrn, char** agrs)
{
    SubClass s(3);
    cout << s.value1 << endl;
    cout << s.value2 << endl;

    return agrn;
}