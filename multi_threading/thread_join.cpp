#include<iostream>
#include<thread>

void run(int n){
    while(n --> 0)
        std::cout<<"hehe\n";
}

int main(){
    std::thread t1(run,10);

    //always check joinable before join/detach is called because double join/detach crashes the program.
    if(t1.joinable())
        t1.join();
    return 0;
}
