#include "syvector.hpp"

template <typename T>
syvector<T>::syvector() : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename T> 
syvector<T>::syvector(int n) : m_size(n), m_capacity(0){
    while(m_capacity < n){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    m_data = new T[m_capacity];
}

template <typename T> 
syvector<T>::syvector(int n, T value) : m_size(n), m_capacity(0){
    while(m_capacity < n){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    m_data = new T[m_capacity];
    for(int i = 0; i < n; i++){
        m_data[i] = value;
    }
}

template <typename T>
syvector<T>::~syvector(){
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
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
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        T * new_data = new T[m_capacity];
        for(int i = 0; i < m_size; ++i){
            new_data[i] = std::move_if_noexcept(m_data[i]);
        }
        if(m_data != nullptr){
            delete[] m_data;
            m_data = nullptr;
        }
        m_data = new_data;
    }
    m_data[m_size] = value;
    ++m_size;
}

template <typename T>
void syvector<T>::pop_back(){
    if(m_size > 0)
        --m_size;
}

template <typename T>
int syvector<T>::size(){
    return m_size;
}

template <typename T>
int syvector<T>::capacity(){
    return m_capacity;
}

template <typename T>
typename syvector<T>::iterator syvector<T>::begin(){
    return syvector<T>::iterator(m_data);
}

template <typename T>
typename syvector<T>::iterator syvector<T>::end(){
    return syvector<T>::iterator(m_data + m_size);;
}

template <typename T>
void syvector<T>::clear(){
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
bool syvector<T>::empty(){
    return m_size == 0;
}

template <typename T>
void syvector<T>::assign(int n, T value){
    if(m_capacity >= n){
        for(int i = 0; i < m_capacity; ++i){
            m_data[i] = value;
        }
        m_size = n;
        return;
    }    
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    while(m_capacity < n){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    m_data = new T[n];
    for(int i = 0; i < n; i++){
        m_data[i] = value;
    }
}

template <typename T>
void syvector<T>::resize(int n){
    resize(n, T());
}

template <typename T>
void syvector<T>::resize(int n, T value){
    if(n <= m_size){
        m_size = n;
        return;
    }
    if(n < m_capacity){
        for(int i = m_size; i < n; ++i){
            m_data[i] = value;
        }
        m_size = n;
        return;
    }
    while(m_capacity < n){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    T * new_data = new T[m_capacity];
    for(int i = 0; i < m_size; ++i){
        new_data[i] = std::move_if_noexcept(m_data[i]);
    }
    for(int i = m_size; i < n; ++i){
        new_data[i] = value;
    }
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = new_data;
    m_size = n;
}

template<typename T>
void syvector<T>::reserve(int n){
    if(m_capacity >= n){
        return;
    }
    while(m_capacity < n){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    T * new_data = new T[m_capacity];
    for(int i = 0; i < m_size; ++i){
        new_data[i] = std::move_if_noexcept(m_data[i]);
    }
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = new_data;
}

template<typename T>
typename syvector<T>::iterator syvector<T>::insert(iterator pos, T value){
    return insert(pos, 1, value);
}

template<typename T>
typename syvector<T>::iterator syvector<T>::insert(iterator pos, int n, T value){
    int size = pos - this->begin();
    if(m_size + n <= m_capacity){
        for(int i = m_size - 1; i >= size; --i){
            m_data[i + n] = m_data[i];
        }
        for(int i = 0; i < n; ++i){
            m_data[i + size] = value;
        }
        m_size += n;
        return iterator(m_data + size);
    }
    while(m_size + n > m_capacity){
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
    }
    T * new_data = new T[m_capacity];
    for(int i = 0; i < size; ++i){
        new_data[i] = m_data[i];
    }
    for(int i = size; i < size + n; ++i){
        new_data[i] = value;
    }
    for(int i = size; i < m_size; ++i){
        new_data[i + n] = m_data[i];
    }
    if(m_data != nullptr){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = new_data;
    m_size += n;
    return iterator(m_data + size);
}

template<typename T>
typename syvector<T>::iterator syvector<T>::erase(iterator pos){
    int size = pos - begin();
    for(int i = size; i < m_size - 1; ++i){
        m_data[i] = m_data[i+1];
    }
    --m_size;
    return pos;
}

template<typename T>
typename syvector<T>::iterator syvector<T>::erase(iterator first, iterator last){
    int f = first - begin();
    int l = last - begin();
    int n = last - first;
    for(int i = 0; i < n; ++i){
        m_data[i + f] = m_data[l + i];
    }
    m_size -= n;
    return iterator(m_data + f);
}
