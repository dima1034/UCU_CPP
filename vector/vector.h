//
// Created by dosta on 29.04.2018.
//

#ifndef CSTD_VECTOR_H
#define CSTD_VECTOR_H


#include <iostream>


template<typename T>
class vector {

public:

    // Init Constructor
    vector(std::initializer_list<T> lst)
            : _size(lst.size())
            , _capacity(lst.size())
            , buffer(new T[lst.size()]) 
    {
        std::copy(lst.begin(), lst.end(), buffer);
    }

    // Move Constructor
    vector(vector&& other) noexcept
            : _size(other.size())
            , _capacity(other.capacity())
            , buffer(other.buffer) 
    { // && ссылка на rvalue
        other._size     = 0;
        other._capacity = 0;
        other.buffer    = nullptr;
    }
    
    // Copy Constructor
    vector(const vector& other)
            : _size(other.size())
            , _capacity(other.capacity())
            , buffer(new T[size]) 
    {
        std::copy(other.buffer, other.buffer + other.size(), buffer);
    }
    
    // Не допускает неявное преобразования типа: vector<double> v = 10; instead -> vector<double> v(10)
    explicit vector(size_t size)
            : _size(size)
            , _capacity(size)
            , buffer(new T[size]) 
    {}

    // Default Constructor
    vector()
            : _size(DEFAULT_VECTOR_SIZE)
            , _capacity(DEFAULT_VECTOR_CAPACITY)
            , buffer(new T[DEFAULT_VECTOR_CAPACITY])
    {}

    // Move Assignment Operator
    vector& operator= (vector&& other) noexcept
    {
        other.swap(*this);
        return *this;
    };


    // Copy Assignment Operator
    vector& operator= (const vector& other)
    {
        T* temp = new T[other.size()];

        std::copy(other.buffer, other.buffer + other.size(), temp);
        delete[] buffer;

        buffer = temp;
        _size = other.size();
        _capacity = other.capacity();

        return *this;
    }

    friend std::ostream& operator<< (std::ostream& os, const vector<T>& vec)
    {
        for(int indice = DEFAULT_VECTOR_SIZE; indice < vec.size(); indice++) 
            os << vec[indice] << " ";

        os << std::endl;
        return os;
    }

    void push_back(T const& value);
    
    void pop_back(T const& value);

    const T& operator[] (int index) const;
    T& operator[] (int index);
  
    std::size_t max_size() const;
        
    std::size_t size() const;
    
    std::size_t capacity() const;

    ~vector()
    {
        delete[] buffer;            // Clean up the resource
    }

private:    

    constexpr static int DEFAULT_VECTOR_SIZE     = 0;
    constexpr static int DEFAULT_VECTOR_CAPACITY = 1;
    constexpr static char OUT_OF_RANGE[]         = "index out of range"; //why not string????

    T *buffer = nullptr;
    std::size_t _size     = DEFAULT_VECTOR_SIZE;     // The number of objects in the vector
    std::size_t _capacity = DEFAULT_VECTOR_CAPACITY;

    void swap(vector& other) noexcept;
    void allocate();
};


template<typename T>
const T& vector<T>::operator[] (int index) const
{
    if(index >= _size)
    {
        throw std::out_of_range(OUT_OF_RANGE);
    }
    return buffer[index];
}

template<typename T>
T& vector<T>::operator[] (int index) 
{
    if(index >= _size)
    {
        throw std::out_of_range(OUT_OF_RANGE);
    }
    return buffer[index];
}

template<typename T>
void vector<T>::allocate()
{
    _capacity *= 2;
    
    T* temp = new T[_capacity];
    std::copy(buffer, buffer + size(), temp);
    delete[] buffer;

    buffer = temp;
}

template<typename T>
std::size_t vector<T>::max_size() const
{
    std::size_t max_size = -1;
    max_size = max_size / sizeof(T);
    return max_size;
}

template<typename T>
std::size_t vector<T>::size() const
{
    return _size;
}

template<typename T>
std::size_t vector<T>::capacity() const
{
    return _capacity;
}

template<typename T>
void vector<T>::push_back(T const& value)
{
    if (_size >= _capacity) {
        allocate();
    }
    //buffer = new (buffer + _size) T(value);
    buffer[_size] = value;
    ++_size;
}

template<typename T>
void vector<T>::pop_back(T const& value)
{
    buffer[_size].~T();
    _size--;
}

template<typename T>
void vector<T>::swap(vector& other) noexcept
{
    std::swap(_size,     other.size());
    std::swap(_capacity, other.capacity());
    std::swap(buffer,    other.buffer);
}


#endif //CSTD_VECTOR_H
