#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;

class A {
public:
    int* pointer;
    A() :pointer(new int(1)) { cout << "����" << pointer << endl; };
    A(A& a) :pointer(new int(*a.pointer)) { cout << "����" << endl; };
    A(A&& a) noexcept :pointer(a.pointer) {
        a.pointer = nullptr;
        cout << "�ƶ�" << pointer << endl;
    };

    ~A()
    {
        cout << "����:"<<pointer << endl;
        delete pointer;
    }
};

A return_rvalue(bool test) {
    A a, b;
    if (test) return a;
    return b;
}



int main(int argv, char** args)
{
    {
        A obj = return_rvalue(false);
        cout << "obj:" << " " << obj.pointer << ": " << *obj.pointer << endl;
    }
    string str = "Hello world";
    vector<string>v;

    //��ʹ��push_back(const T&), ������������Ϊ
    v.push_back(str);
    //�����"str : Hello world"
    cout << "str : " << str << endl;


    //��ʹ��push_back(const T&&), ������ֿ�����Ϊ
    //�������ַ����ᱻ�ƶ���vector�У�������ʱ��move���������ٿ������ֵĿ���
    //��������str�е�ֵ���ÿ�
    v.push_back(move(str));
    //����� ��str ����
    cout << "str : " << str << endl;

    return argv;
}