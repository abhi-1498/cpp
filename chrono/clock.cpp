#include<iostream>
#include<chrono>

int main(){
    // system time, can be changed by user
    auto now = std::chrono::system_clock::now();
    std::time_t legecyTime = std::chrono::system_clock::to_time_t(now);
    std::cout<<"current time: "<<std::ctime(&legecyTime);

    // monotonic clock, cannot be changed
    auto steadyTime = std::chrono::steady_clock::now();
    std::cout<<"steady clock time: "<<steadyTime.time_since_epoch();
    return 0;
}