#include<iostream>
#include<thread>
#include<condition_variable>

std::mutex m;
std::condition_variable cv;
int amount = 0;

void addMoney(){
    std::lock_guard<std::mutex> lock(m);
    amount += 500;
    cv.notify_all();
}

void widrawMoney(){
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock,[](){return amount>0 ? true : false ;});
    amount-=100;
    std::cout<<std::this_thread::get_id()<<" deducted amount.\n";
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(widrawMoney);
    std::thread t3(widrawMoney);
    std::thread t4(widrawMoney);
    std::thread t5(widrawMoney);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout<<"amount: "<<amount;

    return 0;
}

