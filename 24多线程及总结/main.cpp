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

    //����������
    queue<int>produced_nums;

    //������
    mutex m;

    //��������
    condition_variable cond_var;

    //������־
    auto done = false;

    //֪ͨ��־
    auto notified = false;
    
    //�������߳�
    thread producer([&] {
        for (int i = 0; i < 5; i++)
        {
            this_thread::sleep_for(chrono::seconds(1));
            //����������
            unique_lock<mutex>lock(m);
            cout << "producing" << i << endl;
            produced_nums.push(i);
            notified = true;
            
            //֪ͨһ���߳�
            cond_var.notify_one();
        }
        done = true;
        notified = true;
        cond_var.notify_one();
        });

    //�������߳�

    thread consumer([&] {
        unique_lock<mutex>lock(m);
        while (!done)
        {
            while (!notified)   //ѭ��������ٻ���
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