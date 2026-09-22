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

class base{
    public:
    void operator()(int x){
        while( x-- > 0)
            std::cout<<"functor :"<<x<<"\n";
    }
};

class baseNonStatic{
    public:
    void fun(int x){
        while( x-- > 0)
            std::cout<<"Non-static :"<<x<<"\n";
    }
};

class baseStatic{
    public:
    static void fun(int x){
        while( x-- > 0)
            std::cout<<"static :"<<x<<"\n";
    }
};

int main(){
    // funtion pointer
    std::thread t1(sumOdd,0,1000000);

    //lambda
    auto fun = [](int x){
        while(x-- > 0)
            std::cout<<"first lamba:"<<x <<"\n";
    };
    std::thread t2(fun,10);

    std::thread t3([](int x){
            while(x-- > 0)
                std::cout<<x <<"\n";
        },10);

    // functor/funtion object
    std::thread t4(base(),10);

    // non-static member
    baseNonStatic obj;
    std::thread t5(baseNonStatic::fun,&obj,10);

    //static member
    std::thread t6(baseStatic::fun,10);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}