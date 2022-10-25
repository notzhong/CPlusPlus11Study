#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;

class A {
public:
    int* pointer;
    A() :pointer(new int(1)) { cout << "构造" << pointer << endl; };
    A(A& a) :pointer(new int(*a.pointer)) { cout << "拷贝" << endl; };
    A(A&& a) noexcept :pointer(a.pointer) {
        a.pointer = nullptr;
        cout << "移动" << pointer << endl;
    };

    ~A()
    {
        cout << "析构:"<<pointer << endl;
        delete pointer;
    }
};

A return_rvalue(bool test) {
    A a, b;
    if (test) return a;
    return b;
}



int main(int argv, char** args)
{
    {
        A obj = return_rvalue(false);
        cout << "obj:" << " " << obj.pointer << ": " << *obj.pointer << endl;
    }
    string str = "Hello world";
    vector<string>v;

    //将使用push_back(const T&), 即产生拷贝行为
    v.push_back(str);
    //将输出"str : Hello world"
    cout << "str : " << str << endl;


    //将使用push_back(const T&&), 不会出现拷贝行为
    //而整个字符串会被移动到vector中，所以有时候move会用来减少拷贝出现的开销
    //这个步骤后，str中的值被置空
    v.push_back(move(str));
    //将输出 “str ：”
    cout << "str : " << str << endl;

    return argv;
}