#include<iostream>
#include<thread>
#include<mutex>

int amount = 0;
std::mutex mtx;

void addMoney(){
    //template wrapper with RAII
    std::lock_guard<std::mutex> lock(mtx);
    amount++;
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout<<"amount:"<<amount;
    return 0;
}