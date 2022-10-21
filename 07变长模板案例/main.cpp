#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;

//template <bool T> class MagicType {
//    bool magic = T;
//};

template <typename T, typename U>
class MagicType
{
public:
    T dark;
    U magic;
};

namespace UseForUsing{
    //C++11 使用using定义模板别名， 类似于typedef 原名 新名

    typedef int(*process)(void*);//使用typedef定义的函数指针
    using NewProcess = int(*)(void*);//使用using定义的函数指针，等同于typedef的作用

    template <typename T>
    using TrueDarkMagic = MagicType<vector<T>, string>;

    template<typename T = int, typename U = int>
    auto add(T x, U y)->decltype(x + y)
    {
        return x + y;
    }
}


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

}



int main(int agn, char** agc) {

    UseForUsing::TrueDarkMagic<bool> you;


    LenForChange::magic();
    LenForChange::magic(1);
    LenForChange::magic(2,"");
    return agn;
}