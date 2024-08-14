#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(size_t initial_capacity)
    : capacity(initial_capacity), size(0) {
    array = new T[capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template<typename T>
void DynamicArray<T>::resize(size_t new_capacity) {
    T* new_array = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    capacity = new_capacity;
}

template<typename T>
void DynamicArray<T>::insert(const T& value) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    array[size++] = value;
}

template<typename T>
void DynamicArray<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    --size;
}

template<typename T>
void DynamicArray<T>::clear() {
    size = 0;
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template<typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template<typename T>
size_t DynamicArray<T>::getCapacity() const {
    return capacity;
}
