#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>

#include <functional>
using namespace std;


void foo(int* p, int len) {
	for (int i = 0; i != len; i++)
	{
		cout << reinterpret_cast<unsigned int*>(p)[i] << endl;
	}
}


//vector �������������orɾ�������ݵ��ڴ治�黹����Ҫʹ��shrink_to_fit�ͷŶ���ռ䡣
int main(int argv, char** args) {

	constexpr int len = 4;

	array<int, len>arr = { 1,4,3,2 };

	/*vector<int> v;

	cout << "size : " << v.size() << endl;
	cout << "capacity....����" << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.shrink_to_fit();
	cout << "size : " << v.size() << endl;
	cout << "capacity....����" << v.capacity() << endl;

	v.clear();
	cout << "size : " << v.size() << endl;
	cout << "capacity....����" << v.capacity() << endl;*/

	//C ���ӿڴ���
	//foo(arr, arr.size()); //�Ƿ����޷���ʽת��
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());


	//����ӿ�
	sort(arr.begin(), arr.end());
	for (auto& i : arr)
		cout << i << endl;

	//forward_list ���list�ռ������ʸ�

    return argv;
}