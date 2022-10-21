#pragma once
#include<iostream>
#include <initializer_list>
#include<vector>

class InitializingTheList
{
private:
    std::vector<int> vec;

public:
    std::vector<int> GetValue()const;
    //初始化列表构造函数
    InitializingTheList(std::initializer_list<int>list);
    ~InitializingTheList();

    //可以在函数中调用初始化列表
    void Initializer(std::initializer_list<int>list);

};

