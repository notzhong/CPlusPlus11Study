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


//有序：红黑树排序
//无序：哈希表排序
namespace  yes_or_no_sequence {
    //两组结构按同样的顺序初始化
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


    //分别对两组结构进行遍历
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
        return make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return make_tuple(2.9, 'B', "李四");
    if (id == 2)
        return make_tuple(1.7, 'C', "王五");

    //返回类型被推断为std::tuple<double,char,std::string>
    return make_tuple(0.0, 'D', "null");
}


int main(int argv, char** args) {
    auto student = get_student(0);
    cout << "ID: 0," << "GPA:" << std::get<0>(student) << ","
        << "成绩：" << get<1>(student) << ","
        << "姓名：" << get<2>(student) << endl;

    double gpa;
    char grade;
    string name;


    //元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    cout << "ID: 1," << "GPA:" << gpa << ","
        << "成绩：" << grade << ","
        << "姓名：" << name << endl;


    tuple<string, double, double, int>t("123", 4.5, 6.7, 8);
    cout << get<string>(t) << endl;
    //cout << get<double>(t) << endl;//报错，不允许。遇到相同类型，编译器不知道是哪一个。
    cout << get<2>(t) << endl;
    cout << get<int>(t) << endl;

    return argv;
}