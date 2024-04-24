#ifndef MYALLOCA_H_
#define MYALLOCA_H_

template<class T>
class Myalloca
{
private:
    /* data */
public:
    Myalloca();
    Myalloca(T *ptr);
    Myalloca(unsigned int n, T value);
    ~Myalloca();

    T* allocate();
    T* allocate(unsigned int n);

    void deallocate(T* ptr);
    void deallocate(T* ptr, unsigned int n);
};

template<class T>
Myalloca<T>::Myalloca() {
}

template<class T>
Myalloca<T>::Myalloca(T *ptr) {
    ::new ((void*)ptr) T();
}

template<class T>
Myalloca<T>::~Myalloca(){
}

template<class T>
T* Myalloca<T>::allocate()
{
    return static_cast<T*>(::operator new(sizeof(T)));
}

template<class T>
T* Myalloca<T>::allocate(unsigned int n)
{
    if (n == 0)
    return nullptr;
    return static_cast<T*>(::operator new(n * sizeof(T)));
}

template<class T>
void Myalloca<T>::deallocate(T* ptr) {}

template<class T>
void Myalloca<T>::deallocate(T* ptr, unsigned int n) {}


#endif