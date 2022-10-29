#include<thread>
#include<mutex>
#include<atomic>
#include<future>

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>
#include <functional>
#include<memory>
#include<unordered_map>

using namespace std;

void foo() {
    cout << "hello world" << endl;
}


void foo2()
{
    //��һ������ֵΪ7�� lambda���ʽ��װ��task��
    //packaged_task ��ģ�����ΪҪ��װ�ĺ�������
    packaged_task<int()>task([] {
        /*for (long long i = 0; i < 999999999000; i++) { 
            if (!(i - 1))
                cout << "runing" << i << endl;
        };*/
        return 7; });

    //���task �� future
    future<int> result = task.get_future(); //��һ���߳���ִ��task
    thread(move(task)).detach();
    cout << "Waiting...";
    result.wait();

    //ִ��������
    cout << "Done!" << endl << "Result is " << result.get() << endl;
}


int main(int argv, char** args) {
    thread t(foo);
    t.detach();
    t.join();
    foo2();

    //t.join();

    return  argv;
}