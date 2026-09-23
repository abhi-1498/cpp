#include<iostream>
#include<thread>
#include<mutex>

int amount = 0;
std::mutex mtx;

void addMoney(){
    //mutex lock before the critical section.
    mtx.lock();
    amount++;
    //unlock after the critical section is done.
    mtx.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout<<"amount:"<<amount;
    return 0;
}