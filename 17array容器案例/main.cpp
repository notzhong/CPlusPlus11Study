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


//vector 当存入大量输入or删除，扩容的内存不归还，需要使用shrink_to_fit释放多余空间。
int main(int argv, char** args) {

	constexpr int len = 4;

	array<int, len>arr = { 1,4,3,2 };

	/*vector<int> v;

	cout << "size : " << v.size() << endl;
	cout << "capacity....容量" << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.shrink_to_fit();
	cout << "size : " << v.size() << endl;
	cout << "capacity....容量" << v.capacity() << endl;

	v.clear();
	cout << "size : " << v.size() << endl;
	cout << "capacity....容量" << v.capacity() << endl;*/

	//C 风格接口传参
	//foo(arr, arr.size()); //非法，无法隐式转换
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());


	//更多接口
	sort(arr.begin(), arr.end());
	for (auto& i : arr)
		cout << i << endl;

	//forward_list 相比list空间利用率高

    return argv;
}