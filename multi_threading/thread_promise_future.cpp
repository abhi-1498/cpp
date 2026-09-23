#include<iostream>
#include<thread>
#include<future>

void sumP(std::promise<long long> && sumPromise,int start, int end){
    long long sum = 0;
    for(int i=start;i<end;i++)
        sum+=i;
    sumPromise.set_value(sum);
}

int main(){
    //promise obj is create and passed to funtion
    std::promise<long long> sumPromise;
    //future obj is created form promise obj where the value will be set.
    std::future<long long> sum = sumPromise.get_future();

    std::thread t(sumP,std::move(sumPromise),1,1000000);

    t.join();

    std::cout<<"value: "<<sum.get();
    return 0;
}