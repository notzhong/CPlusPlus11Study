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
    sTemporary << "�����ܺ�Ϊ��" << n_num << " ƽ��ֵΪ��" << agv;
    str = sTemporary.str();

    return make_tuple(n_num, agv, str);
}


int main(int agv, char** ags) {

    //�������Data, ��ҪC++17֧��
    auto [num, n_agv, str] = AddAlgo(8, 9);

    cout << num << " " << n_agv << str << endl;

    //����ʹ�ã����ͷ��ڴ�ʱ���׷����ڴ�Խ�磡����
    //auto arr = new auto(10);

    return agv;
}