#include <cstddef> 

template <typename T>
class Myvector
{
private:
    T* p_data;
    size_t size; // 当前大小
    size_t capacity; //已经申请内存的总容量

private:
void ReAloc();

const T& operator[](size_t index) const;

T& operator[](size_t index);

public:
    Myvector();
    Myvector(size_t n);
    Myvector(size_t n, T value);
    ~Myvector();

    void push_back(T &value);
};

template <typename T>
Myvector<T>::Myvector()
{
    p_data = new T[sizeof(T)];
    std::fill(p_data, p_data + sizeof(T), 0);
}

template <typename T>
Myvector<T>::Myvector(size_t n)
{
    p_data = new T[n];
    std::fill(p_data, p_data + n, 0);
}

template <typename T>
Myvector<T>::Myvector(size_t n, T value)
{
    p_data = new T[n];
    std::fill(p_data, p_data + n, value);
}

template <typename T>
Myvector<T>::~Myvector()
{
}

template <typename T>
void Myvector<T>::ReAloc()
{
    capacity *= 2;
    T *p = new T[capacity];
    std::copy(p_data, p_data + size, p);
    delete []p_data;
    p_data = p;
}

template <typename T>
const T& Myvector<T>::operator[](size_t index) const
{
    return *(p_data + index);
}

template <typename T>
T& Myvector<T>::operator[](size_t index)
{
    return *(p_data + index);
}

template <typename T>
void Myvector<T>::push_back(T &value)
{
    if (size >= capacity) ReAloc();
    p_data[size] = value;
    size++;
    
}
