#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;

using foo = void(int);//����һ������ָ��

void functiona1(foo f) {//foo*
    f(1);
}

int foo2(int para) { return para; }

int foo3(int a, int b, int c) { return a + b + c; }


int main(int argv, char** args) {

    //��lambda���ʽ��[]Ϊ��ʱ��Ϊ�հ�����
    auto f = [](int value) {cout << value << endl; };
    functiona1(f);  //����ָ�����foo*
    f(1);           //lambda ���ʽ����

    //function ��װ��һ������ֵΪint������Ϊint�ĺ���
    function<int(int)>func = foo2;

    int important = 10;
    function<int(int)> func2 = [&](int value)->int {return 1 + value + important; };

    cout << "func = " << func(10) << " " << "func2 = " << func2(10) << endl;

    //������1��2�󶨵�����foo�ϣ�����ʹ��placeholders::_1���Ե�һ����������ռλ
    auto bindFoo = bind(foo3, placeholders::_1, 1, 2);
    //��ʱ����һ���������ɡ�
    cout << "bindFoo = " << bindFoo(13) << endl;

    return argv;
}