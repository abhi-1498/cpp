#include<iostream>
#include<chrono>
#include<thread>

struct scopedTimer{
    std::string m_name;
    std::chrono::time_point<std::chrono::steady_clock> start;

    scopedTimer(std::string name){
        m_name = name;
        start = std::chrono::steady_clock::now();
    }

    ~scopedTimer(){
        auto curTime = std::chrono::steady_clock::now();
        auto elapsedTime = curTime - start;

        std::cout<<"elapsed time for "<<m_name<<":"<<elapsedTime<<"\n";
    }
};

int main(){
    scopedTimer timer("main");

    // elapsed time for main:16000300ns
    // spin wait or busy wait does not leave cpu and hence is more accurate
    auto start = std::chrono::steady_clock::now();
    while(std::chrono::steady_clock::now()-start < std::chrono::milliseconds(16));

    return 0;
}