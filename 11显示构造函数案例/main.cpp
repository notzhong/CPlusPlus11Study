#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;


struct Base
{
    virtual void foo(int) {
        int n = 1;
    };

    //����final�󣬺������ܼ̳�
    virtual void one() final {};
};

//����final��class������Ϊ����̳�
struct SubClass final:Base {
    SubClass() = default;
    void foo(int n) override{
    };
};

//����final��class������Ϊ����̳�
//struct sub2 :SubClass {
//
//};


class Magic {
public:
    //Ĭ�Ϲ��캯��
    Magic() = default;

    //��ʹ�ñ����������ɺ���
    Magic& operator=(const Magic&) = delete;

    //�Զ����Լ��ĺ���
    Magic(int magic_number) {
    };
};



int main(int agrn, char** args) {

    Base* L90= new SubClass();
    L90->foo(8);

    return agrn;
}