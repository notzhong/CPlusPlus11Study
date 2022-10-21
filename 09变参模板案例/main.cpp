#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;


//可变长模板
namespace LenForChange {

    template<typename ...Ts>class Magic;

    /*class Magic<int,
        vector<int>,
        map<string, vector<int>>> darkMagic;*/

        //class Magic<> nothing;

    template <typename Require, typename ...Args>class Magic2;

    template <typename ...Args> void
        Print(const string& str, Args... args) {};

    template <typename ...Args>
    void magic(Args...args)
    {
        cout << sizeof...(args) << endl;
    }

    //模板递归
    template <typename T0>
    void printf(T0 value)
    {
        cout << value << endl;
    }
    template<typename T, typename ...Args>
    void printf(T value, Args...args)
    {
        cout << value << endl;
        printf(args...);
    }

    //C++17 变参调用方式
    template<typename T2, typename ...Args>
    void printf2(T2 value, Args...args)
    {
        cout << value << endl;
        if constexpr (sizeof...(args) > 0)
            printf2(args...);
    }

    //初始化列表展开递归
    template <typename T, typename...Args>
    auto printf3(T value, Args...args)
    {
        cout << value << endl;
        return initializer_list<T>
        {
            ([&] {
                cout << args << endl;
                }(), value)...
        };
    }


    //折叠表达式
    template <typename ...T>
    auto sum(T...t)
    {
        return(t + ...);
    }

}





int main(int agn, char** agc) {


    //传入参数个数
    /*LenForChange::magic();
    LenForChange::magic(1);
    LenForChange::magic(2, "");*/

    //LenForChange::printf(1, 2, "123", 1.1);
    //LenForChange::printf2(1, 2, "123", 1.1);
    LenForChange::printf3(1, 2, "123", 1.1);


    cout << LenForChange::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

    //右值引用临时非定义变量。
    auto&& sum = LenForChange::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << sum << endl;
    return agn;
}