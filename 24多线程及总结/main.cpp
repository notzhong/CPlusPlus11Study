#include<thread>
#include<mutex>
#include<atomic>
#include<future>
#include<queue>
#include<condition_variable>
#include<chrono>

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



int main(int argv, char** args) {

    //生产者数量
    queue<int>produced_nums;

    //互斥锁
    mutex m;

    //条件变量
    condition_variable cond_var;

    //结束标志
    auto done = false;

    //通知标志
    auto notified = false;
    
    //生产者线程
    thread producer([&] {
        for (int i = 0; i < 5; i++)
        {
            this_thread::sleep_for(chrono::seconds(1));
            //创建互斥锁
            unique_lock<mutex>lock(m);
            cout << "producing" << i << endl;
            produced_nums.push(i);
            notified = true;
            
            //通知一个线程
            cond_var.notify_one();
        }
        done = true;
        notified = true;
        cond_var.notify_one();
        });

    //消费者线程

    thread consumer([&] {
        unique_lock<mutex>lock(m);
        while (!done)
        {
            while (!notified)   //循环避免虚假唤醒
            {
                cond_var.wait(lock);
            }
            while (!produced_nums.empty())
            {
                cout << " consuming " << produced_nums.front() << endl;
                produced_nums.pop();
            }
            notified = false;
        }
        });

    producer.join();
    consumer.join();

    return  argv;
}