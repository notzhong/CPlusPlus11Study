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
    //��ʼ���б��캯��
    InitializingTheList(std::initializer_list<int>list);
    ~InitializingTheList();

    //�����ں����е��ó�ʼ���б�
    void Initializer(std::initializer_list<int>list);

};

