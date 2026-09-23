#include<iostream>
#include<thread>
#include<mutex>

int x=0,y=0;
std::mutex m1,m2;

void incXY(std::mutex &m,int &n){
    while(1){
        m.lock();
        n++;
        m.unlock();
    }
}

void consumeXY(){
    int n = 100;
    while(1){
        //std::try_lock tries to lock a list of mutex.
        //if any is not aquired releasess all other aquired.
        //return -1 on success
        if(std::try_lock(m1,m2)==-1){
            std::cout<<"got all lock: ";
            std::cout<<"x:"<<x<<" y:"<<y<<std::endl;
            n--;
            m1.unlock();
            m2.unlock();
        }
        if(n==0) break;
    }
}

int main(){
    std::thread t1(incXY,std::ref(m1),std::ref(x));
    std::thread t2(incXY,std::ref(m2),std::ref(y));
    std::thread t3(consumeXY);

    t1.detach();
    t2.detach();
    t3.join();
    
    return 0;
}