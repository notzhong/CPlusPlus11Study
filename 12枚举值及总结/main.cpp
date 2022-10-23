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

//ǿ���͵�ö��,c++11 ����ö������Ϊʵ�����Ͱ�ȫ�����磺
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

    //ö���಻�����Ա�
    /*if (new_enum1::value1 == new_enum2::value1)
        cout << "Left::left_value1==Right::right_value1" << endl;*/


    return argn;
}
