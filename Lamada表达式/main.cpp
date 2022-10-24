#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;

//[捕获列表](参数列表)mutable(可选)异常属性->返回类型{函数体}

void learn_lamada_func_1() {
    int value_1 = 1;
    auto copy_value_1 = [value_1]() {
        return value_1;
    };
    value_1 = 100;
    auto stored_value_1 = copy_value_1();
    cout <<"stored_value_1 = " << stored_value_1 << endl;
    //这时，stored_value_1 = 1，而value_1 = 100;
    //因为 copy_value_1 在创建时候就保存了一份value_1的拷贝
}

void learn_lamada_func_2() {
    int value_2 = 1;
    auto copy_value_2 = [&value_2]() {
        return value_2;
    };
    value_2 = 100;
    auto stored_value_2 = copy_value_2();
    cout << "stored_value_2 = " << stored_value_2 << endl;
    //这时，stored_value_2 = 100，而value_1 = 100;
    //因为 copy_value_2 保存的是引用
}



int main(int argv, char** args)
{
    learn_lamada_func_1();
    learn_lamada_func_2();

    
    auto important = make_unique<int>(1);
    auto add = [v1 = 1, v2 = move(important)](auto x, auto y)->decltype(x + y){
        return x + y + v1 + (*v2);
    };

    cout << add(3, 3.1) << endl;
    
    //泛型lambda
    auto generic = [](auto x, auto y) {return x + y; };

    cout << generic(4, 3.1) << endl;
    cout << generic(5, 3.1) << endl;
    cout << generic(6.6, 3.1) << endl;

    return argv; 
}