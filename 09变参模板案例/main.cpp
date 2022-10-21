#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;


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

    //ģ��ݹ�
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

    //C++17 ��ε��÷�ʽ
    template<typename T2, typename ...Args>
    void printf2(T2 value, Args...args)
    {
        cout << value << endl;
        if constexpr (sizeof...(args) > 0)
            printf2(args...);
    }

    //��ʼ���б�չ���ݹ�
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


    //�۵����ʽ
    template <typename ...T>
    auto sum(T...t)
    {
        return(t + ...);
    }

}





int main(int agn, char** agc) {


    //�����������
    /*LenForChange::magic();
    LenForChange::magic(1);
    LenForChange::magic(2, "");*/

    //LenForChange::printf(1, 2, "123", 1.1);
    //LenForChange::printf2(1, 2, "123", 1.1);
    LenForChange::printf3(1, 2, "123", 1.1);


    cout << LenForChange::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

    //��ֵ������ʱ�Ƕ��������
    auto&& sum = LenForChange::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << sum << endl;
    return agn;
}