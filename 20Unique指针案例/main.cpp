#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>

#include <functional>
#include<memory>
#include<unordered_map>

using namespace std;

//auto pointer = make_unique<int>(10);
//unique_ptr<int>pointer2 = pointer;    //非法，unique独占指针，不允许共享

//C++11代码实现unique_ptr
//template <typename T,typename ...Args>
//std::unique_ptr<T> make_unique(Args&& ... args)
//{
//    return std::unique_ptr<T>(new T(forward<Args>(args)...));
//}


struct Foo
{
    Foo() { std::cout << "Foo::Foo" << endl; };
    ~Foo() { cout << "Foo::~Foo" << endl; };
    void foo() { cout << "Foo::foo" << endl; };
};

void f(const Foo&)
{
    cout << "f(const Foo&)" << endl;
}

int main(int argv, char** args) {

    unique_ptr<Foo>p1(make_unique<Foo>());

    if (p1)p1->foo();
    {
        unique_ptr<Foo>p2(move(p1));
        f(*p2);
        if (p2)p2->foo();
        if (p1)p1->foo();
        p1 = move(p2);
        if (p2)p2->foo();
    }

    if (p1)p1->foo();


    return argv;
}