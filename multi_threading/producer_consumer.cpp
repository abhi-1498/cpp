#include<iostream>
#include<thread>
#include<condition_variable>
#include<queue>

std::queue<int> q;
int bufferSize = 100;
std::mutex m;
std::condition_variable cv;

void producer(int n){
    while(n){
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock,[](){ return q.size()<bufferSize;});
        std::cout<<"Produced: "<<n<<"\n";
        q.push(n);
        n--;
        lock.unlock();
        cv.notify_one();
    }
}

void consumer(){
    while(1){
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock,[](){return q.size()>0;});
        int val = q.front();
        q.pop();
        std::cout<<"Consumed: "<<val<<"\n";
        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    std::thread t1(producer,100);
    std::thread t2(producer,100);
    std::thread t3(producer,100);
    std::thread t4(consumer);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
