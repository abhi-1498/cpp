#include<iostream>
#include<thread>
#include<mutex>

int amount = 0;
std::mutex mtx;

void addMoney(){
    //template wrapper with RAII
    std::unique_lock<std::mutex> lock(mtx);
    amount++;
}

void addMoney2(){
    //defer_lock tells not to lock at the time of obj creation.
    //needs explicit locking
    std::unique_lock<std::mutex> lock(mtx,std::defer_lock);
    lock.lock();
    amount++;
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    std::thread t3(addMoney2);
    std::thread t4(addMoney2);

    t1.join();
    t2.join();

    t3.join();
    t4.join();

    std::cout<<"amount:"<<amount;
    return 0;
}
