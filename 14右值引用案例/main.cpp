#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>

#include <functional>

using namespace std;
//��ֵ����ʱ���ڣ���ֵ�����ڴ��ڡ�
//��ֵ������ֵ������ֵ��

namespace ����ֵ {

    vector<int> foo() {
        vector<int>temp{ 1,2,3,4 };
        return temp;
    }

    vector<int>&& v = foo();
}

//��ֵ����
void reference(string& str) {
    cout << "left value" << endl;
}

//��ֵ����
void reference(string&& str) {
    cout << "right value" << endl;
}



int main(int argv, char** args)
{
    string lv1 = "string";
    string&& rv1 = move(lv1);
    cout << rv1 << endl;

    //��ֵ�����ӳ���ʱ������������
    const string& lv2 = lv1 + lv1;
    cout << lv2 << endl;

    //��ֵ�����ӳ���ʱ��������ʱ��������������
    string&& rv2 = lv1 + lv2;
    cout << rv2 << endl;
    rv2 += "Test";

    cout << rv2 << endl;

    reference(rv2);

    return argv;
}