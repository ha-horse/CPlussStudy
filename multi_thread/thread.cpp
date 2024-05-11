#include <thread>
#include <iostream>

 
// 无参数函数
void HelloThread() {
    std::cout << "hello thread!" << std::endl;
}

//有参数函数
int SumThread(int a, int b) {
    int c = a + b;
    std::cout << a << " + " << b << " = " << c << std::endl;
    return c;
}

int main()
{
    std::thread t1 (HelloThread);
    std::thread t2 (SumThread, 1, 2);

    // join()是主线程等待子线程结束方可执行下一步(串行),
    // detach()是的子线程放飞自我，独立于主线程并发执行，主线程后续代码段无需等待。
    // t1.join();
    // t2.join();
    t1.detach();
    t2.detach();

    //主线程代码
    std::cout << "main here" << std::endl;
    return 0;
}