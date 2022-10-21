#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>

using namespace std;


string lookup1() {
    string str;
    return str;
};

string& lookup2() {
    string str;
    return str;
};


//string lookup_a_string1()
//{
//    return lookup1();
//}
//
//string& lookup_a_string2()
//{
//    return lookup2();
//}

//返回类型推导
decltype(auto) lookup_a_string1()
{
    return lookup1();
}

decltype(auto) lookup_a_string2()
{
    return lookup2();
}


template <typename T>
auto print_type_info(const T& t) {
    if constexpr (is_integral<T>::value) {
        return t + 1;
    }
    else
    {
        return t + 0.01;
    }
}


int main(int agrv, char** agrc)
{
    cout << print_type_info(5) << endl;
    cout << print_type_info(3.14) << endl;

    return agrv;
}