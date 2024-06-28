#pragma once
#include <stdexcept>

template <typename T>
class syvector {
public:
    syvector();
    syvector(int size);
    syvector(int size, T value);
    ~syvector();
    T at(int index);
    T operator[](int index);
    
    T front();
    T back();
    T * data();
    void push_back(T value);
    void pop_back();
    T * begin();
    T * end();
    int size();
    int capacity();
private:
    T* m_data;
    int m_size;
    int m_capacity;
};
#include <syvector.inl>
