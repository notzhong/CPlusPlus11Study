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
    //将一个返回值为7的 lambda表达式封装到task中
    //packaged_task 的模板参数为要封装的函数类型
    packaged_task<int()>task([] {
        /*for (long long i = 0; i < 999999999000; i++) { 
            if (!(i - 1))
                cout << "runing" << i << endl;
        };*/
        return 7; });

    //获得task 的 future
    future<int> result = task.get_future(); //在一个线程中执行task
    thread(move(task)).detach();
    cout << "Waiting...";
    result.wait();

    //执行输出结果
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