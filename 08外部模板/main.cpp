#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

using namespace std;


namespace autoTest {

    void autoForTest() {
        vector<int>vec{ 1,2,3,4,5 };

        if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())*itr = 4;

        for (auto element : vec)
        {
            cout << element << endl;
        }

        for (int& element : vec)
            element += 1;
        for (auto element : vec)
            cout << element << endl;
    }
}



template class vector<bool>;
extern template class vector<double>;


template <bool T>class MagicType {
    bool magic = T;
};



int main(int agrn, char** agrc)
{
    //写法合法，但不建议,避免代码复杂化。
    vector<vector<int>>matrix;
    vector<MagicType<(1 > 2)>>magic;

    //vector<>

    return agrn;
}