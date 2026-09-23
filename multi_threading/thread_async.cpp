#include<iostream>
#include<thread>
#include<future>

long long sumP(int start, int end){
    long long sum = 0;
    for(int i=start;i<end;i++)
        sum+=i;
    return sum;
}

int main(){
    //async creates a task and return a future object.
    std::future<long long> sum = std::async(std::launch::async,sumP,1,1000000);

    std::cout<<"value: "<<sum.get();
    return 0;
}