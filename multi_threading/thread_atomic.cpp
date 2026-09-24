#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> count=0;

void inc(){
    for(int i=0;i<100000;i++)
        count++;
}

int main(){
    std::thread t1(inc);
    std::thread t2(inc);

    t1.join();
    t2.join();

    std::cout<<"count: "<<count;
    return 0;
}