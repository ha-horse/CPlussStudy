#include <thread>
#include <mutex>
#include <iostream>


std::mutex mt;
int data = 1;


void AddThread(int a) {
    mt.lock();
    data += a;
    std::cout << "add data = " << data << std::endl;
    mt.unlock();
}


void MulThread(int a) {
    mt.lock();
    data *= a;
    std::cout << "mul data = " << data << std::endl;
    mt.unlock();
}


int main() {
    std::thread t1(AddThread, 2);
    std::thread t2(MulThread, 10);

    t1.detach();
    t2.detach();

    std::cout << "main here" << std::endl;
    return 0;
}
