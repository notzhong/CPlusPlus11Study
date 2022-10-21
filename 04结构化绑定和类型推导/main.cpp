#include <iostream>
#include<sstream>
#include<string>
#include <tuple>


using namespace std;


tuple<int, double, string>AddAlgo(int x, int y)
{
    int n_num = x + y;
    double agv = static_cast<double>(n_num) / 2;

    stringstream sTemporary;
    string str;
    sTemporary << "数据总和为：" << n_num << " 平均值为：" << agv;
    str = sTemporary.str();

    return make_tuple(n_num, agv, str);
}


int main(int agv, char** ags) {

    //计算输出Data, 需要C++17支持
    auto [num, n_agv, str] = AddAlgo(8, 9);

    cout << num << " " << n_agv << str << endl;

    //不可使用，在释放内存时，易发生内存越界！！！
    //auto arr = new auto(10);

    return agv;
}