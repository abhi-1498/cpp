#include<iostream>
#include<chrono>

int main(){
    std::chrono::seconds s(5);
    std::chrono::milliseconds ms(40);

    // library handles the arithematic
    std::chrono::milliseconds t = s+ms;
    
    std::cout<<t;

    return 0;
}