#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>
using namespace std;


void reference(int& v) {
    cout << "左值引用" << endl;
}


void reference(int&& v) {
    cout << "右值引用" << endl;
}

//T& 左引用 -》T&
//T& 右引用 -》T&
//T&& 左引用 -》T&
//T&& 右引用 -》T&&
//以上为C++特有的类型推导，使用T&&可以推导为左右引用
template<typename T>
void pass(T&& v) {
    cout << "普通传参：";
    reference(v);

    cout << "move 传参：";
    reference(move(v));

    cout << "forward 传参：";
    reference(forward<T>(v));//与static_cast<T&&>(v)类似
}



int main(int argv, char** args) {
    cout << "传递右值：" << endl;
    pass(1);

    cout << "传递左值：" << endl;
    int v = 1;
    pass(v);




    return argv;
}