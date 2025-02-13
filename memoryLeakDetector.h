/*
线程安全：使用std::mutex保证多线程环境下的记录安全。
全面覆盖：处理了new、new[]、nothrow new等所有分配形式。
精准定位：通过__FILE__和__LINE__宏实现源码级定位。
低侵入性：只需包含头文件和定义宏即可启用检测。

宏冲突：可能会与第三方库中的new操作产生冲突，建议仅在调试时启用。
性能影响：频繁的内存操作会影响性能，建议仅在调试阶段使用。
placement new：需要特殊处理，当前实现会跳过对placement new的跟踪。
*/

#ifndef MEMORY_LEAK_DETECTOR_H
#define MEMORY_LEAK_DETECTOR_H

#ifdef ENABLE_MEMORY_LEAK_DETECTION

#include <cstddef>
#include <mutex>
#include <string>
#include <unordered_map>

struct AllocationInfo {
  size_t size;
  std::string file;
  int line;
};

class MemoryLeakDetector {
public:
  static MemoryLeakDetector &instance() {
    static MemoryLeakDetector detector;
    return detector;
  }

  void trackAllocation(void *ptr, size_t size, const char *file, int line) {
    std::lock_guard<std::mutex> lock(mutex_);
    allocations_[ptr] = {size, file, line};
  }

  void trackDeallocation(void *ptr) {
    std::lock_guard<std::mutex> lock(mutex_);
    allocations_.erase(ptr);
  }

  ~MemoryLeakDetector() {
    reportLeaks();
  }

private:
  MemoryLeakDetector() = default;
  // 禁止拷贝
  MemoryLeakDetector(const MemoryLeakDetector &) = delete;
  MemoryLeakDetector &operator=(const MemoryLeakDetector &) = delete;

  void reportLeaks() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (allocations_.empty()) return;

    fprintf(stderr, "\n=== Memory Leak Report ===\n");
    fprintf(stderr, "Total leaks: %zu\n", allocations_.size());
    for (const auto &entry : allocations_) {
      fprintf(stderr, "Leaked %zu bytes at %p (allocated at %s:%d)\n",
              entry.second.size, entry.first, entry.second.file.c_str(),
              entry.second.line);
    }
    fflush(stderr);
  }

  std::mutex mutex_;
  std::unordered_map<void *, AllocationInfo> allocations_;
};

// 重载operator new
void *operator new(size_t size, const char *file, int line) {
  void *ptr = malloc(size);
  if (ptr != nullptr) {
    MemoryLeakDetector::instance().trackAllocation(ptr, size, file, line);
  }
  return ptr;
}

void *operator new[](size_t size, const char *file, int line) {
  return operator new(size, file, line);
}

void operator delete(void* ptr) noexcept {
  MemoryLeakDetector::instance().trackDeallocation(ptr);
  free(ptr);
}

// 重载operator delete
void operator delete(void* ptr, size_t) noexcept {
  MemoryLeakDetector::instance().trackDeallocation(ptr);
  free(ptr);
}

void operator delete[](void *ptr) noexcept { operator delete(ptr); }

void operator delete[](void* ptr, size_t size) noexcept {
  operator delete(ptr, size);
}

// 处理nothrow版本
void *operator new(size_t size, const std::nothrow_t &, const char *file,
                   int line) noexcept {
  return operator new(size, file, line);
}

void *operator new[](size_t size, const std::nothrow_t &, const char *file,
                     int line) noexcept {
  return operator new(size, file, line);
}

// 宏替换将new替换为带文件名和行号的版本
#define new new (__FILE__, __LINE__)

#endif // ENABLE_MEMORY_LEAK_DETECTION

#endif // MEMORY_LEAK_DETECTOR_H