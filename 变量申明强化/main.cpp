#include<iostream>
#include <vector>
#include<algorithm>



int main(int agv, char** ags) {
    std::vector<int>vec{ 1,2,3,4 };
    //const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    //C++17 ������if��ʹ�ñ�������
    if (const std::vector<int>::iterator itr =std::find(vec.begin(),vec.end(),2);
        itr != vec.end())
    {
        *itr = 3;
    }

    //C++11 for����ʹ��auto�����Ƶ�����iterator����ѭ��
    for (auto &itr :vec)
    {
        std::cout << itr << std::endl;
    }
    return agv;
}