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

    //声明final后，函数不能继承
    virtual void one() final {};
};

//声明final后，class不能作为基类继承
struct SubClass final:Base {
    SubClass() = default;
    void foo(int n) override{
    };
};

//声明final后，class不能作为基类继承
//struct sub2 :SubClass {
//
//};


class Magic {
public:
    //默认构造函数
    Magic() = default;

    //不使用编译器的生成函数
    Magic& operator=(const Magic&) = delete;

    //自定义自己的函数
    Magic(int magic_number) {
    };
};



int main(int agrn, char** args) {

    Base* L90= new SubClass();
    L90->foo(8);

    return agrn;
}