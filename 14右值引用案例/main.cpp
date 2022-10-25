#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;
//右值，临时存在；左值，长期存在。
//右值：纯右值，将亡值。

namespace 将亡值 {

    vector<int> foo() {
        vector<int>temp{ 1,2,3,4 };
        return temp;
    }

    vector<int>&& v = foo();
}

//左值引用
void reference(string& str) {
    cout << "left value" << endl;
}

//右值引用
void reference(string&& str) {
    cout << "right value" << endl;
}



int main(int argv, char** args)
{
    string lv1 = "string";
    string&& rv1 = move(lv1);
    cout << rv1 << endl;

    //左值引用延长临时变量生命周期
    const string& lv2 = lv1 + lv1;
    cout << lv2 << endl;

    //右值引用延长临时变量的临时变量的生命周期
    string&& rv2 = lv1 + lv2;
    cout << rv2 << endl;
    rv2 += "Test";

    cout << rv2 << endl;

    reference(rv2);

    return argv;
}