#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>

#include <functional>


#include<unordered_map>

using namespace std;


//���򣺺��������
//���򣺹�ϣ������
namespace  yes_or_no_sequence {
    //����ṹ��ͬ����˳���ʼ��
    unordered_map<int, string>u{
        {1,"1"},
        {3,"3"},
        {2,"2"}
    };


    map<int, string> v = {
        {1,"1" },
        { 3,"3" },
        { 2,"2" }
    };


    //�ֱ������ṹ���б���
    void Print() {
        cout << "unordered_map" << endl;
        for (const auto& n : u)
            cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";

        cout << endl;

        cout << "map" << endl;
        for (const auto& n : v)
            cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}


auto get_student(int id)
{
    if (id == 0)
        return make_tuple(3.8, 'A', "����");
    if (id == 1)
        return make_tuple(2.9, 'B', "����");
    if (id == 2)
        return make_tuple(1.7, 'C', "����");

    //�������ͱ��ƶ�Ϊstd::tuple<double,char,std::string>
    return make_tuple(0.0, 'D', "null");
}


int main(int argv, char** args) {
    auto student = get_student(0);
    cout << "ID: 0," << "GPA:" << std::get<0>(student) << ","
        << "�ɼ���" << get<1>(student) << ","
        << "������" << get<2>(student) << endl;

    double gpa;
    char grade;
    string name;


    //Ԫ����в��
    std::tie(gpa, grade, name) = get_student(1);
    cout << "ID: 1," << "GPA:" << gpa << ","
        << "�ɼ���" << grade << ","
        << "������" << name << endl;


    tuple<string, double, double, int>t("123", 4.5, 6.7, 8);
    cout << get<string>(t) << endl;
    //cout << get<double>(t) << endl;//����������������ͬ���ͣ���������֪������һ����
    cout << get<2>(t) << endl;
    cout << get<int>(t) << endl;

    return argv;
}