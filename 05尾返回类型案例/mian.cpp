#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>

using namespace std;


//C++11 ֮ǰ
template <typename R,typename T,typename U>
R add(T x, U y)
{
    return x + y;
}




//C++11 ֮��auto β�����������Ƶ�
template<typename T,typename U>
auto GetAddNum(T x, U y)->decltype(x + y) {
    return x + y;
}


//C++14 ֮���
template <typename T,typename U>
auto add2(T x, U y)
{
    return x + y;
}


//auto �������������Ƶ�
//int Add(auto x, auto y)
//{
//    return 0;
//}


int main(int agv, char** agc)
{
    auto x = 1;
    auto y = 2.0;

    //decltype�Ա��ʽ���������Ƶ�
    decltype(x + y)z = 3;

    if (is_same<decltype(x), int>::value)
        cout << "type x == int" << endl;
    if(is_same<decltype(x), float>::value)
        cout << "type x == float" << endl;
    if (is_same<decltype(x), decltype(z)>::value)
        cout << "type x == type z" << endl;


    //11 ֮ǰ��
    int num1 = add<int, int, int>(8, 9);
    cout << num1 << endl;

    //C++11
    auto a = GetAddNum<int,double>(x, 8.0);
    if (is_same<decltype(a), double>::value)
    {
        cout << "a is double" << endl;
    }

    //C++14
    auto q = add2<double, int>(1.0, 2);
    cout << "q: " << q << endl;


    return agv;
}