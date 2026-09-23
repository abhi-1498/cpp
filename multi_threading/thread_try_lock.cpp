#include<iostream>
#include<thread>
#include<mutex>

int count = 0;
std::mutex mtx;

void countTo100000(){
    for(int i=0;i<100000;i++){
        //try_lock is unblocking lock aquisiton try
        if(mtx.try_lock()){
            count++;
            mtx.unlock();
        }
    }
}

int main(){
    std::thread t1(countTo100000);
    std::thread t2(countTo100000);

    t1.join();
    t2.join();

    std::cout<<"count:"<<count;
    return 0;
}