#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* array;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    DynamicArray(size_t initial_capacity = 10);
    ~DynamicArray();
    
    void insert(const T& value);
    void remove(size_t index);
    void clear();
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
};

#include "DynamicArray.cpp"

#endif
