#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;

using foo = void(int);//定义一个函数指针

void functiona1(foo f) {//foo*
    f(1);
}

int foo2(int para) { return para; }

int foo3(int a, int b, int c) { return a + b + c; }


int main(int argv, char** args) {

    //当lambda表达式的[]为空时，为闭包对象。
    auto f = [](int value) {cout << value << endl; };
    functiona1(f);  //函数指针调用foo*
    f(1);           //lambda 表达式调用

    //function 包装了一个返回值为int，参数为int的函数
    function<int(int)>func = foo2;

    int important = 10;
    function<int(int)> func2 = [&](int value)->int {return 1 + value + important; };

    cout << "func = " << func(10) << " " << "func2 = " << func2(10) << endl;

    //将参数1，2绑定到函数foo上，但是使用placeholders::_1来对第一个参数进行占位
    auto bindFoo = bind(foo3, placeholders::_1, 1, 2);
    //这时调用一个参数即可。
    cout << "bindFoo = " << bindFoo(13) << endl;

    return argv;
}