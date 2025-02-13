#define ENABLE_MEMORY_LEAK_DETECTION

#include <thread>

#include "memoryLeakDetector.h"

int test1() {
  int *p = new int;
  // 忘记释放p

  return 0;
}

int test2() {
  int *p = new int;
  delete p;

  return 0;
}

int test3() {
  int *arr = new int[10];
  // 忘记释放arr

  return 0;
}

void alloc() { int *p = new int; }

int test4() {
  std::thread t(alloc);
  t.join();

  return 0;
}

int main() {
  // test1();
  test2();
  // test3();
  // test4();
  return 0;
}