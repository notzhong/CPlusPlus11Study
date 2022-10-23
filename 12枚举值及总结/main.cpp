#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;



enum Left {
    left_value1 = 1,
    left_value2
};

enum Right
{
    right_value1 = 1,
    right_value2
};

//强类型的枚举,c++11 引入枚举类概念，为实现类型安全。例如：
enum class new_enum1 :unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};


enum class new_enum2 : int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};



int main(int argn, char** args)
{
    if (Left::left_value1 == Right::right_value1)
        cout << "Left::left_value1==Right::right_value1" << endl;

    //枚举类不能作对比
    /*if (new_enum1::value1 == new_enum2::value1)
        cout << "Left::left_value1==Right::right_value1" << endl;*/


    return argn;
}
