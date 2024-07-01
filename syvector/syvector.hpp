#pragma once
#include <stdexcept>


template <typename T>
class syvector_iterator {
public:
    syvector_iterator(T * ptr){
        m_ptr = ptr;
    }
    // 前缀++
    syvector_iterator & operator ++ (){
        m_ptr += 1;
        return *this;
    };
    // 后缀--
    syvector_iterator operator ++ (int n){
        syvector_iterator temp = *this;
        m_ptr += 1;
        return temp;
    };
    // 前缀--
    syvector_iterator & operator -- (){
        m_ptr -= 1;
        return m_ptr;
    };
    // 后缀--
    syvector_iterator operator -- (int n){
        syvector_iterator temp = *this;
        m_ptr -= 1;
        return temp;
    };
    bool operator != (const syvector_iterator & other){       
        return m_ptr != other.m_ptr;
    };
    bool operator == (const syvector_iterator & other){       
        return m_ptr == other.m_ptr;
    };
    T * operator -> (){       
        return m_ptr;
    };
    T & operator * (){
        return * m_ptr;
    }
    syvector_iterator operator - (int n){
        syvector_iterator it = *this;
        it->m_ptr -= n;
        return it;
    }
    int operator - (const syvector_iterator & other) {
        return m_ptr - other.m_ptr;
    }
    syvector_iterator operator + (int n){
        syvector_iterator it = *this;
        it.m_ptr += n;
        return it;
    }
private:
    T * m_ptr;
};

template <typename T>
class syvector {
public:
    typedef syvector_iterator<T> iterator;
    iterator begin();
    iterator end();
    iterator insert(iterator pos, T value);
    iterator insert(iterator pos, int n, T value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);

private:

public:
    syvector();
    syvector(int n);
    syvector(int n, T value);
    ~syvector();
    T at(int index);
    T operator[](int index);
    T front();
    T back();
    T * data();
    void push_back(T value);
    void pop_back();
    int size();
    int capacity();
    void clear();
    bool empty();
    void assign(int n, T value);
    void resize(int n);
    void resize(int n, T value);
    void reserve(int n);
private:
    T* m_data;
    int m_size;
    int m_capacity;
};
#include <syvector.inl>
