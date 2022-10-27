#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>

#include <functional>
#include <memory>
#include<unordered_map>


using namespace std;

//RAII unique_ptr, weak_ptr, shared_ptr

void foo(shared_ptr<int>i)
{
    (*i)++;
}


int main(int argv, char** args) {

    //auto pointer0 = new int(10); //非法，不允许直接赋值

    //构造了一个std::shared_ptr
    auto pointer = make_shared<int>(10);
    auto pointer2 = pointer;    //引用计数+1
    auto pointer3 = pointer;    //引用计数+1


    foo(pointer);
    cout << *pointer << endl;
    int* p = pointer.get();//不会增加引用计数

    cout << "reset pointer:" << endl;
    cout << "pointer.use_count() = " << pointer.use_count() << endl;
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl;


    pointer2.reset();//直接清理内存
    cout << "reset pointer2:" << endl;
    cout << "pointer.use_count() = " << pointer.use_count() << endl;
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl;


    pointer3.reset();
    cout << "reset pointer:" << endl;
    cout << "pointer.use_count() = " << pointer.use_count() << endl;
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl;

    //cout << *pointer2 << endl; //引用计数为0时，非法访问

    return argv;
}