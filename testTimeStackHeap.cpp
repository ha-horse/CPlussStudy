#include <iostream>
#include <chrono>

void stackMemory() {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; ++i) {
      int arr[100]; // stack malloca
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Stack time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << "microseconds" << std::endl;
}



void heapMemory() {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 1000000; ++i) {
      int* arr = new int[100]; // heap malloca
      delete[] arr;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Heap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << "microseconds" << std::endl;
}


int main() {
  stackMemory();
  heapMemory();
  return 0;
}


/*
栈内存的申请和释放速度快于堆内存，主要原因包括：
1、栈内存的管理是自动且顺序的，而堆内存的管理是手动且随机的
2、栈内存的操作不涉及操作系统和线程同步，而堆内存可能涉及系统调用和锁机制
3、栈内存具有良好的缓存局部性，而堆内存的缓存局部性较差
4、栈内存不会产生内存碎片问题，而堆内存可能会产生内存碎片
*/