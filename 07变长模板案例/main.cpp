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
    //C++11 ʹ��using����ģ������� ������typedef ԭ�� ����

    typedef int(*process)(void*);//ʹ��typedef����ĺ���ָ��
    using NewProcess = int(*)(void*);//ʹ��using����ĺ���ָ�룬��ͬ��typedef������

    template <typename T>
    using TrueDarkMagic = MagicType<vector<T>, string>;

    template<typename T = int, typename U = int>
    auto add(T x, U y)->decltype(x + y)
    {
        return x + y;
    }
}


//�ɱ䳤ģ��
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