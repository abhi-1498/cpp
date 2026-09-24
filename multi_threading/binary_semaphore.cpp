#include<iostream>
#include<thread>
#include<semaphore>
#include<chrono>

std::binary_semaphore mainToWorker{0},workerToMain{0};

void worker(){
    //try to acquire semaphore
    mainToWorker.acquire();

    std::cout<<"acquired semaphore.\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));

    // signal main thread that work is done.
    workerToMain.release();
}

int main(){
    std::thread t(worker);

    //signal worker thread to start working.
    mainToWorker.release();

    std::cout<<"waiting worker thread work to be completed.\n";
    //wait for worker thread to complete and signal
    workerToMain.acquire();

    std::cout<<"worker signaled main thread to proceed.\n";
    
    t.join();
    return 0;
}