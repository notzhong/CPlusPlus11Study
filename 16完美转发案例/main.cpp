#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>
using namespace std;


void reference(int& v) {
    cout << "��ֵ����" << endl;
}


void reference(int&& v) {
    cout << "��ֵ����" << endl;
}

//T& ������ -��T&
//T& ������ -��T&
//T&& ������ -��T&
//T&& ������ -��T&&
//����ΪC++���е������Ƶ���ʹ��T&&�����Ƶ�Ϊ��������
template<typename T>
void pass(T&& v) {
    cout << "��ͨ���Σ�";
    reference(v);

    cout << "move ���Σ�";
    reference(move(v));

    cout << "forward ���Σ�";
    reference(forward<T>(v));//��static_cast<T&&>(v)����
}



int main(int argv, char** args) {
    cout << "������ֵ��" << endl;
    pass(1);

    cout << "������ֵ��" << endl;
    int v = 1;
    pass(v);




    return argv;
}