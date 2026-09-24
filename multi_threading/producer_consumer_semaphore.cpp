#include<iostream>
#include<thread>
#include<semaphore>
#include<queue>
#include<chrono>

std::queue<int> q;
std::binary_semaphore signal_p{1},signal_c{0};

void producer(){
    while(1){
        signal_p.acquire();
        for(int i=0;i<5;i++){
            std::cout<<" Produced: "<<i;
            q.push(i);
        }
        std::cout<<std::endl;
        signal_c.release();
    }
}

void consumer(){
    while(1){
        signal_c.acquire();
        for(int i=0;i<5;i++){
            int val = q.front();
            q.pop();
            std::cout<<" Consumed: "<<val;
        }
        std::cout<<"\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        signal_p.release();
    }
}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
