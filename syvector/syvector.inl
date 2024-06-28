#include "syvector.hpp"
template <typename T>
syvector<T>::syvector() : m_data(nullptr), m_size(0), m_capacity(0) {}
template <typename T> 
syvector<T>::syvector(int size) : m_size(size), m_capacity(0){
    while(m_capacity < size){
        if(m_capacity == 0)
            m_capacity = 1;
        else
            m_capacity *= 2;
    }
    m_data = new T[m_capacity];
}
template <typename T> 
syvector<T>::syvector(int size, T value) : m_size(size), m_capacity(0){
    while(m_capacity < size){
        if(m_capacity == 0)
            m_capacity = 1;
        else
            m_capacity *= 2;
    }
    m_data = new T[m_capacity];
    for(int i = 0; i < size; i++){
        m_data[i] = value;
    }
}
template <typename T>
syvector<T>::~syvector(){
    if(m_data!= nullptr){
        delete[] m_data;
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
T syvector<T>::at(int index){
    if(index < 0 || index >= m_size){
        throw std::out_of_range("index out of range");
    }
    return m_data[index];
}

template <typename T>
T syvector<T>::front(){
    return m_data[0];
}

template <typename T>
T syvector<T>::back(){
    return m_data[m_size - 1];
}

template <typename T>
T * syvector<T>::data() {
    return m_data;
}

template <typename T>
T syvector<T>::operator[](int index){
    return m_data[index];
}

template <typename T>
void syvector<T>::push_back(T value){
    if(m_size == m_capacity){
        if(m_capacity == 0) 
            m_capacity = 1;
        else 
            m_capacity *= 2;
        T * new_data = new T[m_capacity];
        for(int i = 0; i < m_size; ++i){
            new_data[i] = m_data[i];
        }
        if(m_data!= nullptr){
            delete[] m_data;
        }
        m_data = new_data;
    }
    m_data[m_size] = value;
    ++m_size;
}

template <typename T>
int syvector<T>::size(){
    return m_size;
}

template <typename T>
int syvector<T>::capacity(){
    return m_capacity;
}
