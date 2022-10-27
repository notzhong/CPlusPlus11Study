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

struct A;
struct B;


struct A
{
    //弱引用指针，不对内存操作
    weak_ptr<B>pointer;
    ~A() {
        cout << "A 被销毁" << endl;
    }
};

struct B
{
    weak_ptr<A>pointer;
    ~B() {
        cout << "B 被销毁" << endl;
    }
};


int main(int argv, char** args) {

    auto a = make_shared<A>();
    auto b = make_shared<B>();

    a->pointer = b;
    b->pointer = a;

    return argv;
}