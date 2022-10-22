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

    //ʹ�øù��캯��������һ�����캯��Base()����ί�й���
    Base(int value) :Base() { value2 = value; };
	virtual ~Base() {};

private:

};


class SubClass : public Base {
private:

public:
    //�̳й��죬�̳�Base��ί�й��졣
    using Base::Base;//������ SubClass(int value):Base(value) {};
    
    SubClass() = delete;
    
};



int main(int agrn, char** agrs)
{
    SubClass s(3);
    cout << s.value1 << endl;
    cout << s.value2 << endl;

    return agrn;
}