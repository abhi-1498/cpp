#include<iostream>
#include<chrono>
#include<thread>

int sumOdd(int s,int e){
    int sum=0;
    for(int i=s;i<e;i++){
        if(i&1==1)
            sum+=i;
    }
    return sum;
}

int sumEven(int s,int e){
    int sum=0;
    for(int i=s;i<e;i++){
        if(i&1==0)
            sum+=i;
    }
    return sum;
}

int main(){
    auto start = std::chrono::steady_clock::now();

    //takes 4sec to run singlethreaded
    // sumEven(0,10000000);
    // sumOdd(0,10000000);

    //making two threads divide the workfload and runs in 2sec.
    std::thread t1(sumEven,0,10000000);
    std::thread t2(sumOdd,0,10000000);

    t1.join();
    t2.join();

    auto curTime = std::chrono::steady_clock::now();;
    auto elapsedTime = curTime - start;

    std::cout<<elapsedTime;

    return 0;
}